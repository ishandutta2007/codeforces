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

vvi adj;
vi deg;
int maxa;
int ld=-1;
bool can=1;

void dfs(int i,int p,int d) {
	int lv=0;
	for(int j:adj[i]) {
		if(j==p) continue;
		if(deg[j]==1) ++lv;
		dfs(j,i,d+1);
	}
	if(lv>1) maxa-=(lv-1);
	if(deg[i]==1) {
		if(ld==-1) ld=d;
		else if((ld-d)&1) {
			can=0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    adj.resize(n);
    deg.resize(n,0);
    int u,v;
    int st=-1e9;
    rep(i,n-1) {
    	cin>>u>>v;
    	--u;--v;
    	++deg[u];
    	++deg[v];
    	if(deg[u]>1) st=u;
    	else if(deg[v]>1) st=v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
   	maxa=n-1;
    dfs(st,-1,0);
   	int mina=can ? 1 : 3;
    printf("%d %d\n",mina,maxa);

}