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
const int mod = 1000000007;
const int MAXN = 70010, LOG=20;

int n, s, u, v, x, y, t, a, b;
int A[MAXN];
int ind[MAXN];
int cap[MAXN];
int par[MAXN];
bitset<MAXN> dp, newdp, tmp; //dp[MAXN];
bool root[MAXN];
int ans[MAXN];

bool cmp(int i, int j){ return A[i]<A[j];}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//debug(sizeof(dp))
	cin>>n>>s;
	for (int i=1; i<=n; i++) cin>>A[i], ind[i]=i, cap[i]=A[i];
	sort(ind+1, ind+n+1, cmp);
	s-=A[ind[n]];
	
	if (s<0) return puts("-1");
	
	dp.set(0);
	for (int i=1; i<n; i++){
		newdp=dp|(dp<<A[ind[i]]);
		tmp=dp^newdp;
		dp=newdp;
		for(int j=tmp._Find_first();j< tmp.size();j = tmp._Find_next(j)) par[j]=ind[i];
	}
	
	if (!dp[s]) return puts("-1");
	
	debug("while begin")
	
	root[ind[n]]=1;
	while (s){
		root[par[s]]=1;
		s-=A[par[s]];
	}
	
	//debug("while end")
	
	/*
	cerr<<endl;
	for (int i=1; i<=n; i++) cerr<<root[i]<<' ';cerr<<endl;
	cerr<<endl;
	*/
	for (int i=1; i<n; i++) if (!root[ind[i]]){
		ans[ind[i+1]]=ind[i];
		cap[ind[i+1]]-=A[ind[i]];
	}
	for (int i=1; i<=n; i++){
		cout<<cap[i]<<' '<<(ans[i]!=0)<<' ';
		if (ans[i]) cout<<ans[i]<<' ';
		cout<<'\n';
	}
	
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