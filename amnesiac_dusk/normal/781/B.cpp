#pragma GCC optimze("Ofast")
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
const int mod=998244353;
//const int mod=1000000007;
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

struct BipartiteMatcher{
    vector<vector<int>> G;
    vector<int> L, R, Viz;
    void init(int n, int m){
        G.clear(), L.clear(), R.clear(), Viz.clear();
        G.resize(n), L.resize(n, -1), R.resize(m, -1), Viz.resize(n, 0);
    }
    void AddEdge(int a, int b){ G[a].push_back(b); }
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
string hol[2005];
int ff[2005];
pii pol[1005];
void solve() {
	int n;
	cin>>n;
	int cntr=0;
	map<string,int> lol;
	bm.init(n+1, 2*n+1);
	fr(i,1,n) {
		string s1,s2;
		cin>>s1>>s2;
		string a=s1.substr(0, 3);
		string b=s1.substr(0, 2);
		b+=s2[0];
		if(lol.find(a)==lol.end()) {
			lol[a]=++cntr;
			hol[cntr]=a;
		}
		if(lol.find(b)==lol.end()) {
			lol[b]=++cntr;
			hol[cntr]=b;
		}
		pol[i]={lol[a],lol[b]};
		ff[lol[a]]++;
	}
	fr(i,1,n) {
		if(ff[pol[i].fi]==1)
			bm.AddEdge(i,pol[i].fi);
		bm.AddEdge(i,pol[i].se);
	}
	if(bm.Solve()==n) {
		cout<<"YES"<<endl;
		fr(i,1,n)
			cout<<hol[bm.L[i]]<<endl;
	} else
		cout<<"NO"<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}