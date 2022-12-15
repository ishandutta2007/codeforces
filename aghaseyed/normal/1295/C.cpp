#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int nxt[MAXN][26];
string S, T;

int solve(){
	cin>>S>>T;
	n=S.size();
	memset(nxt[n], -1, sizeof(nxt[n]));
	for (int i=n-1; ~i; i--){
		memcpy(nxt[i], nxt[i+1], sizeof(nxt[i]));
		nxt[i][S[i]-'a']=i;
	}
	ans=1;
	int pos=0;
	for (char ch:T){
		if (nxt[0][ch-'a']==-1) kill(-1)
		if (nxt[pos][ch-'a']==-1) pos=0, ans++;
		pos=nxt[pos][ch-'a']+1;
	}
	
	cout<<ans<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int Test;
	cin>>Test;
	while (Test--) solve();
	
	return 0;
}