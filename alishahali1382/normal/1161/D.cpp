#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
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
const int mod = 998244353;
const int MAXN = 1010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int color[MAXN*2];
bool mark[MAXN*2];
vector<pii> G[MAXN*2];
string s;

bool dfs(int node, int c){
	mark[node]=1;
	color[node]=c;
	for (pii p:G[node]){
		if (!mark[p.first] && !dfs(p.first, c^p.second)) return 0;
		if (color[p.first]!=c^p.second) return 0; 
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>s;
	n=s.size();
	s="."+s;
	if (s[n]=='1') kill(0)
	s[n]='0';
	for (int len=1; len<n; len++){
		for (int i=0; i<2*MAXN; i++) G[i].clear();
		for (int i=1; i<=n; i++) if (s[i]!='?'){
			G[i].pb({MAXN+i, s[i]-'0'});
			G[MAXN+i].pb({i, s[i]-'0'});
		}
		for (int i=1; i<=n; i++) G[i].pb({n-i+1, 0});
		for (int i=1; i<=len; i++) G[MAXN+n-len+i].pb({MAXN+n-i+1, 0});
		
		memset(color, 0, sizeof(color));
		memset(mark, 0, sizeof(mark));
		
		ll res=dfs(1, 1);
		if (!mark[MAXN+n]) res*=dfs(MAXN+n, 1);
		else res*=(color[MAXN+n]==1);
		
		for (int i=1; i<=n-len; i++){
			if (!mark[MAXN+i]) res*=dfs(MAXN+i, 0);
			else res*=(color[MAXN+i]==0);
		}
		
		for (int i=1; i<=n; i++) if (!mark[i]) res=(res*2*dfs(i, 0))%mod;
		for (int i=1; i<=n; i++) if (!mark[MAXN+i]) res=(res*2*dfs(MAXN+i, 0))%mod;
		ans=(ans+res)%mod;
	}
	cout<<ans<<'\n';
	
	return 0;
}
/*
      ___           ___                            ___           ___           ___           ___           ___           ___
     /\  \         /\__\      ___                 /\  \         /\__\         /\  \         /\__\         /\  \         /\__\      ___
    /::\  \       /:/  /     /\  \               /::\  \       /:/  /        /::\  \       /:/  /        /::\  \       /:/  /     /\  \
   /:/\:\  \     /:/  /      \:\  \             /:/\ \  \     /:/__/        /:/\:\  \     /:/__/        /:/\:\  \     /:/  /      \:\  \
  /::\~\:\  \   /:/  /       /::\__\           _\:\~\ \  \   /::\  \ ___   /::\~\:\  \   /::\  \ ___   /::\~\:\  \   /:/  /       /::\__\
 /:/\:\ \:\__\ /:/__/     __/:/\/__/          /\ \:\ \ \__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/__/     __/:/\/__/
 \/__\:\/:/  / \:\  \    /\/:/  /             \:\ \:\ \/__/ \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \:\  \    /\/:/  /
      \::/  /   \:\  \   \::/__/               \:\ \:\__\        \::/  /       \::/  /       \::/  /       \::/  /   \:\  \   \::/__/
      /:/  /     \:\  \   \:\__\                \:\/:/  /        /:/  /        /:/  /        /:/  /        /:/  /     \:\  \   \:\__\
     /:/  /       \:\__\   \/__/                 \::/  /        /:/  /        /:/  /        /:/  /        /:/  /       \:\__\   \/__/
     \/__/         \/__/                          \/__/         \/__/         \/__/         \/__/         \/__/         \/__/
*/