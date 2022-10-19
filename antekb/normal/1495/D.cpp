#include<bits/stdc++.h>

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

//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N=405, INF=1e9+5, mod=998244353;
vi E[N];
ll d[N][N], ans[N][N];
int n;
void bfs(int s){
	d[s][s]=1;
	vi V;
	V.pb(s);
	ans[s][s]=1;
	for(int i=0; i<V.size(); i++){
		int v=V[i];
		int t=0;
		for(int u:E[v]){
			if(v!=s && d[s][u]==d[s][v]-1)t++;
			if(d[s][u]==0){
				V.pb(u);
				d[s][u]=d[s][v]+1;
			}
		}
		if(v!=s){
			ans[s][s]*=t;
			ans[s][s]%=mod;
		}
	}
	for(int i=1; i<=n; i++)d[s][i]--;
	//for(int i=1; i<=n; i++)cerr<<d[s][i]<<" ";
	//cerr<<endl;
}
void calc(int a, int b){
	ans[a][b]=1;
	vector<int> V(d[a][b]+1);
	int cnt=0;
	for(int i=1; i<=n; i++){
		if(d[a][i]+d[b][i]==d[a][b])V[d[a][i]]=i, cnt++;
	}
	if(cnt!=V.size())ans[a][b]=0;
	//deb(a, b, cnt, V[0], V.back());
	for(int i=0; i<V.size(); i++)if(!V[i])ans[a][b]=0;
	if(ans[a][b]==0)return;
	for(int i=1; i<=n; i++){
		if(d[a][i]+d[b][i]==d[a][b])continue;
		int v=V[i];
		int t=0;
		for(int u:E[i]){
			if(d[a][u]+1==d[a][i] && d[b][u]+1==d[b][i])t++;
		}
		ans[a][b]*=t;
		ans[a][b]%=mod;
	}
}
int main(){
	//BOOST;
	int m;
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int a, b;
		cin>>a>>b;
		E[a].pb(b);
		E[b].pb(a);
	}
	for(int i=1; i<=n; i++)bfs(i);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i!=j)calc(i, j);
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
}