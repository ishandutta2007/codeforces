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

const int N=2e5+5, INF=1e9+5, mod=1e9+7;

int main(){
	//BOOST;
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		vector<vector<int> > czy(n, vector<int>(m));
		vector<vi> num=czy;
		vi V(n*m);
		for(int &i:V)cin>>i;
		vi V2=V;
		sor(V2);
		vector<pair<int, pii> > V3;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				num[i][j]=V2[i*m+j];
				V3.pb(mp(V2[i*m+j], mp(i, j)));
			}
		}
		sort(all(V3), [](pair<int, pii> a, pair<int, pii> b){if(a.st!=b.st)return a.st<b.st;if(a.nd.st!=b.nd.st)return a.nd.st<b.nd.st; return a.nd.nd>b.nd.nd;});
		map<int, int> wolne;
		for(int i=n*m-1; i>=0; i--)wolne[V3[i].st]=i;
		int ans=0;
		for(int i=0; i<n*m; i++){
			int a=wolne[V[i]];
			wolne[V[i]]++;
			int x=V3[a].nd.st, y=V3[a].nd.nd;
			for(int j=0; j<y; j++)if(czy[x][j])ans++;
			czy[x][y]=1;
		}
		cout<<ans<<"\n";
	}
}