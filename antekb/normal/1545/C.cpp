#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("trapv")
#define st first
#define nd second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define sz(x) (int)(x).size()
#define rsz(x) resize(x)

using namespace std;

///~~~~~~~~~~~~~~~~~~~~~~~~~~

void debug(){cerr<<"\n";}
template <typename H, typename... T>
void debug(H h, T... t) {cerr<<h; if (sizeof...(t)) cerr << ", "; debug(t...);}
#define deb(x...) cerr<<#x<<" = ";debug(x);

///~~~~~~~~~~~~~~~~~~~~~~~~~

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef string str;

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N=2e5+5, mod=998244353, INF=1e9+5;
vi E[N];
int vis[N];
void dfs(int v)
{
	for(int u:E[v]){
		if(vis[u])assert(vis[u]+vis[v]==3);
		else{
			vis[u]=3-vis[v];
			dfs(u);
		}
	}
}
int main(){
	int tt=1;
	cin>>tt;
	while(tt--){
	int n;
	cin>>n;
	vector<vi> V(2*n, vi(n));
	for(int i=0; i<n+n; i++){
		for(int &j:V[i])cin>>j, --j;
	}
	vi zle(2*n), res;
	vector<vi> col(n, vi(n));
	ll ans=1;
	while(res.size()<n){
		bool b=0;
		for(int j=0; j<n; j++){
			vi ile(n);
			for(int i=0; i<2*n; i++){
				if(!zle[i]){
					ile[V[i][j]]++;
				}
			}
			for(int i=0; i<n; i++){
				if(!col[j][i] && ile[i]==1){
					for(int k=0; k<2*n; k++){
						if((!zle[k])&&(V[k][j]==i)){
							zle[k]=1;
							res.pb(k);
							//deb(i+1, j+1, k+1);
							b=1;
							break;
						}
					}
					if(b==1)break;
				}
			}
			if(b==1)break;
		}
		if(b){
		//deb(res.back()+1);
			for(int i=0; i<2*n; i++){
				for(int j=0; j<n; j++){
					if(V[i][j]==V[res.back()][j]){
						zle[i]=1;
						//deb(i+1);
					}
				}
			}
			for(int j=0; j<n; j++){
				col[j][V[res.back()][j]]=1;
			}
		}
		else{
			for(int j=0; j<n; j++){
				vi ile(n, -1);
				for(int i=0; i<2*n; i++){
					if(!zle[i]){
						if(ile[V[i][j]]==-1)ile[V[i][j]]=i;
						else{
							E[ile[V[i][j]]].pb(i);
							E[i].pb(ile[V[i][j]]);
						}
					}
				}
			}
			for(int i=0; i<2*n; i++){
				if(!zle[i] && !vis[i]){
					vis[i]=1;
					dfs(i);
					ans=(ans*2)%mod;
				}
			}
			for(int i=0; i<2*n; i++){
				if(vis[i]==1)res.pb(i);
			}
			assert(res.size()==n);
			break;
		}
	}
	cout<<ans<<"\n";
	for(int i:res)cout<<i+1<<" ";
		cout<<"\n";
	for(int i=0; i<2*n; i++){
		vis[i]=0;
		E[i].clear();
	}
	}
}