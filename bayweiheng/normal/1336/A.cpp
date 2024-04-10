#include<bits/stdc++.h>

using namespace std;

typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef tuple<int,int,int> iii;

#define pb push_back
#define ctz __builtin_ctz
#define pct __builtin_popcount
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);++i)

const int maxn=2e5+5;
int p[maxn],d[maxn],w[maxn];
vi adj[maxn];
ll ans;

void dfs(int i,int q,int e) {
	p[i]=q;d[i]=e;
	w[i]=1;
	for(int j:adj[i]) {
		if(j==q) continue;
		dfs(j,i,e+1);
		w[i]+=w[j];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    int u,v;
    rep(i,n-1) {
    	cin>>u>>v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    dfs(1,-1,0);
    vi a;
    rep(i,n) {
    	a.pb(w[i+1]-d[i+1]-1);
    }
    sort(all(a),greater<int>());
    rep(i,n-k) ans+=a[i];
    cout<<ans<<endl;

}