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

const int N = 100'010, M=64;
ll b[N], a;
ll btmp[N];
int nxt[N];
int dp[M][N];
int n;

int dig(ll x, int i){return ((x>>i)&1);}
int cst(int j, int i, int d, int cr){return dig(b[j], i)^d^cr;}

void update(int i, int d)
{
	int sum=0;
	Loop(j,0,n) sum += cst(j, i, d, 0);
	for(int j=0, p=0; j<=n; ++j){
		while(p<n && dig(b[nxt[p]],i)+!d+(nxt[p]<j) >= 2) ++p;
		dp[i+1][p] = min(dp[i+1][p], dp[i][j]+sum);
		sum -= cst(j, i, d, 0);
		sum += cst(j, i, d, 1);
	}
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
 	cin >> n;
 	Loop(i,0,n) cin >> b[i];
 	Loop(i,0,M) Loop(j,0,N) dp[i][j] = 2e9;
 	dp[0][0] = 0;
 	Loop(i,0,M-1)
 	{
	 	vector<int> vec[2];
	 	LoopR(j,0,n) vec[dig(b[j], i)].push_back(j);
	 	for(int d=1, cnt=0; d>=0; --d){
	 		while(vec[d].size()){
	 			nxt[cnt++] = vec[d].back();
	 			vec[d].pop_back();
	 		}
	 	}
	 	update(i, 0);
	 	update(i, 1);
 		Loop(i,0,n) btmp[i] = b[i];
 		Loop(i,0,n) b[i] = btmp[nxt[i]];
 	}
 	cout << dp[M-1][0] << '\n';
}