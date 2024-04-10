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
#define code(i,j) (((i)<<4) | (j))

const int maxn=2e5+5;
int cnt[maxn][200];
int ban[200];
int cant[200][200];
int k;
int ans=0;
vi stk;
vi conflict[maxn];
void go(int len) {
	if(len==k+1) {
		// do check
		rep(i,k) {
			rep(j,i) {
				if(cant[stk[i]][stk[j]]) {
					return;
				}
			}
		}
		++ans;
		return;
	}
	rep(j,len) {
		int tmp = code(len, j);
		if(ban[tmp]) continue;
		stk.pb(tmp);
		go(len+1);
		stk.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m>>k;
    vii adj[n];
    int u,v,w;
    rep(i,m) {
    	cin>>u>>v>>w;;
    	--u;--v;
    	adj[u].pb({w,v});
    }

    int len,tmp,idx;
    rep(i,n) {
    	sort(all(adj[i]));
    	len=adj[i].size();
    	rep(j,len) {
    		tmp = code(len, j);
    		idx = adj[i][j].second;
    		conflict[idx].pb(tmp);
    		++cnt[idx][tmp];
    	}
    }
    rep(i,n) {
    	sort(all(conflict[i]));
    	conflict[i].erase(unique(all(conflict[i])), conflict[i].end());
    	len=conflict[i].size();
    	rep(j,len) {
    		if(cnt[i][conflict[i][j]]>1) ban[conflict[i][j]]=1;
    		rep(k,j) {
    			cant[conflict[i][j]][conflict[i][k]]=cant[conflict[i][k]][conflict[i][j]]=1;
    		}
    	}
    }
    go(1);
    cout<<ans<<endl;

}