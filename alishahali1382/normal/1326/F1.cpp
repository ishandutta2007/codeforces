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
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int N=14, NN=7;

int n, m, k, u, v, x, y, t, a, b;
int cnt1[N][1<<NN][1<<N];   //  payan           result   mask
int cnt2[N][1<<NN][1<<N];   //  shoroo          result   mask
int cnt3[N][1<<NN][1<<N];   //  baade_payan     result   mask
int adj[N][N], P[N];
ll ans[1<<N];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++) for (int j=0; j<n; j++){
		char ch;
		cin>>ch;
		adj[i][j]=(ch-'0');
	}
	int middle=n/2;
	
	for (int mask=0; mask<(1<<n); mask++){
		int ted=0;
		for (int i=0; i<n; i++) if (mask&(1<<i)) P[ted++]=i;
		
		if (ted!=middle && ted!=n-middle) continue ;
		
		do{
			int res=0;
			for (int i=0; i+1<ted; i++) if (adj[P[i+1]][P[i]]) res|=(1<<i);
			if (ted==middle) cnt1[P[ted-1]][res][mask]++;
			if (ted==n-middle) cnt2[P[0]][res][mask]++;
		} while (next_permutation(P, P+ted));	
	}
	
	for (int mask=0; mask<(1<<n); mask++) if (__builtin_popcount(mask)==middle){
		for (int u=0; u<n; u++) if (mask&(1<<u)){
			for (int v=0; v<n; v++) if ((mask&(1<<v))==0){
				for (int resl=0; resl<(1<<(middle-1)); resl++){
					cnt3[v][resl|(adj[u][v]<<(middle-1))][mask]+=cnt1[u][resl][mask];
				}
			}
		}
	}
	
	for (int mask=0; mask<(1<<n); mask++) if (__builtin_popcount(mask)==middle){
		//for (int u=0; u<n; u++) if (mask&(1<<u)){
			for (int v=0; v<n; v++) if ((mask&(1<<v))==0){
				for (int resl=0; resl<(1<<(middle/*-1*/)); resl++){
					for (int resr=0; resr<(1<<(n-middle-1)); resr++){
						int res=resl|(resr<<middle);
						//if (adj[u][v]) res|=(1<<(middle-1));
						ans[res]+=cnt3[v][resl][mask]*cnt2[v][resr][(1<<n)-1-mask];
					}
				}
			}
		//}
	}
	for (int mask=0; mask<(1<<(n-1)); mask++) cout<<ans[mask]<<' ';
	
	
	return 0;
}