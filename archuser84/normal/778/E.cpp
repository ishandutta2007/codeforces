///
///   Oh? You're approaching me?
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 1010;
string b[N], a;
string btmp[N];
int nxt[N];
int c[10];
int dp[N][N];
int n;

int dig(const string& s, int i){return i<s.size()? s[i]-'0': 0;}
int cst(int j, int i, int d, int cr){return i<a.size() || i<b[j].size() || cr? c[(dig(b[j], i)+d+cr)%10]: 0;}

void update(int i, int d)
{
	int sum=0;
	Loop(j,0,n) sum += cst(j, i, d, 0);
	for(int j=0, p=0; j<=n; ++j){
		while(p<n && dig(b[nxt[p]],i)+d+(nxt[p]<j) >= 10) ++p;
		dp[i+1][p] = max(dp[i+1][p], dp[i][j]+sum);
		sum -= cst(j, i, d, 0);
		sum += cst(j, i, d, 1);
	}
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
 	cin >> a >> n; reverse(a.begin(), a.end());
 	Loop(i,0,n){
 		cin >> b[i];
 		reverse(b[i].begin(), b[i].end());
 	}
	Loop(i,0,10) cin >> c[i];
 	Loop(i,0,N) Loop(j,0,N) dp[i][j] = -2e9;
 	dp[0][0] = 0;
 	Loop(i,0,N-1)
 	{
	 	vector<int> vec[10];
	 	LoopR(j,0,n) vec[dig(b[j], i)].push_back(j);
	 	for(int d=9, cnt=0; d>=0; --d){
	 		while(vec[d].size()){
	 			nxt[cnt++] = vec[d].back();
	 			vec[d].pop_back();
	 		}
	 	}
 		if(i<a.size() && a[i]=='?'){
 			Loop(d,0,10) if(d || i+1<a.size())
 				update(i, d);
 		} else update(i, dig(a, i));
 		Loop(i,0,n) btmp[i].swap(b[i]);
 		Loop(i,0,n) b[i].swap(btmp[nxt[i]]);
 	}
 	cout << dp[N-1][0] << '\n';
}