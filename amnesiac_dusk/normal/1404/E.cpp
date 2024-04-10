#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifndef rd
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(int a, int b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

char a[205][205];
int upd[205][205];
int ld[205][205];
vector<int> E[100005];
int side[100005],cnt[2];
void DFS(int u)
{
	cnt[side[u]]++;
	for(int v:E[u])	{
		if(v&&side[v]==-1)
		{
			side[v]=side[u]^1;
			DFS(v);
		}
	}
}
struct BipartiteMatcher{
    vector<vector<int>> G;
    vector<int> L, R, Viz;
    void init(int n, int m){
        G.clear(), L.clear(), R.clear(), Viz.clear();
        G.resize(n), L.resize(n, -1), R.resize(m, -1), Viz.resize(n, 0);
    }
    void AddEdge(int a, int b){if(a==0||b==0)
    	return; G[a].push_back(b); }
    bool Match(int node){
        if(Viz[node]) return 0;
        Viz[node] = 1;
        for(auto vec : G[node]){
            if(R[vec] == -1 || Match(R[vec])) {
                L[node] = vec;
                R[vec] = node;
                return 1;
            }
        }
        return 0;
    }
    int Solve(){
        bool ok = 1;
        while(ok){
            ok = 0;
            fill(Viz.begin(), Viz.end(), 0);
            fr(i, 0, L.size() - 1)
                if(L[i] == -1)
                    ok |= Match(i);
        }
        int ret = 0;
        fr(i, 0, L.size() - 1)
            ret += (L[i] != -1);
        return ret;
    }
} bm;

void solve() {
	bm.init(40000, 40000);
	memset(side,-1,sizeof(side));
	int n,m;
	cin>>n>>m;
	int cntr=0,answer=0;
	fr(i,1,n)
		fr(j,1,m) {
			cin>>a[i][j];
			if(a[i][j]=='#')
				answer++;
		}
	rep(i,1,n)
		fr(j,1,m)
			if(a[i][j]=='#'&&a[i+1][j]=='#')
				upd[i][j]=++cntr;
	int total=cntr;
	cntr=0;
	fr(i,1,n)
		rep(j,1,m)
			if(a[i][j]=='#'&&a[i][j+1]=='#')
				ld[i][j]=++cntr;
	total+=cntr;
	rep(i,1,n) {
		fr(j,1,m) {
			if(j>1) {
				bm.AddEdge(upd[i][j],ld[i][j-1]);
				bm.AddEdge(upd[i][j],ld[i+1][j-1]);
			}
			if(j<m) {
				bm.AddEdge(upd[i][j],ld[i][j]);
				bm.AddEdge(upd[i][j],ld[i+1][j]);
			}
		}
	}
	trace(cntr,answer);
	int ter=total-bm.Solve();
	answer-=ter;
	cout<<answer<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}