#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Tree;

const double PI = 4 * atan(1);

#define sz(x) (int)(x).size()
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define vi vector<int>
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define vpi vector<pair<int, int>>
#define vpd vector<pair<double, double>>
#define pd pair<double, double>

#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)

void fast_io(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void io(string taskname){
    string fin = taskname + ".in";
    string fout = taskname + ".out";
    const char* FIN = fin.c_str();
    const char* FOUT = fout.c_str();
    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);
    fast_io();
}
const int MAX = 1e5+5;
vector<pair<int, ll>> adj[MAX];
pair<pair<ll, int>, pair<ll, int>> best[MAX];
vector<pair<ll, int>> paths;
const int MAXSEG = (1<<18);
int N;
int st[MAXSEG];

void upd(int i, int x, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N - 1;
	if (hi < i || lo > i) return;
	if (lo == hi) { st[node] += x; return; }
	int mid = (lo + hi) / 2;
	upd(i, x, lo, mid, 2 * node + 1);
	upd(i, x, mid + 1, hi, 2 * node + 2);
	st[node] = max(st[2 * node + 1], st[2 * node + 2]);
}

int query(int s, int e, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N - 1;
	if (hi < s || lo > e) return 0;
	if (lo >= s && hi <= e) return st[node];
	int mid = (lo + hi) / 2;
	return max(query(s, e, lo, mid, 2 * node + 1),
			query(s, e, mid + 1, hi, 2 * node + 2));
}
template<int SZ> struct DSU{
    int par[SZ], sz[SZ];

    void reset(){
        f0r(i, MAXSEG) st[i] = 0;
        for(int i = 0; i<SZ; i++){
            par[i] = i;
            sz[i] = 1;
            upd(i, 1);
        }
    }
    int get(int x){
        if(par[x] != x){
            par[x] = get(par[x]);
        }
        return par[x];
    }
    bool unite(int x, int y){
        x = get(x);
        y = get(y);
        if(x == y){
            return false;
        }
        if(sz[x] < sz[y]){
            swap(x, y);
        }
        sz[x] += sz[y];
        upd(x, query(y, y));
        par[y] = x;
        return true;
    }
};

void update(int i, pair<ll, int> x){
    if(best[i].s.f< x.f){
        best[i].s = x;
    }
    if(best[i].f.f< best[i].s.f){
        swap(best[i].f, best[i].s);
    }
}
ll dfs(int src, int par){
    for(auto nxt: adj[src]){
        if(nxt.f != par){
            ll path = nxt.s + dfs(nxt.f, src);
            update(src, mp(path, nxt.f));
        }
    }
    if(sz(adj[src]) == 1){
        return 0;
    }
    return best[src].f.f;
}
ll get(int src, int nxt){
    if(best[src].f.s != nxt){
        return best[src].f.f;
    }
    return best[src].s.f;
}
void dfs1(int src, int par, ll best){
    update(src, mp(best, par));
    for(auto nxt: adj[src]){
        if(nxt.f != par){
            dfs1(nxt.f, src, nxt.s + get(src, nxt.f));
        }
    }
}

DSU<MAX> d;
int main(){
    fast_io();
    int n;
    cin >> n;
    N = n;
    f0r(i, n-1){
        int xi, yi;
        ll wi;
        cin >> xi >> yi >> wi;
        xi--; yi--;
        adj[xi].eb(mp(yi, wi));
        adj[yi].eb(mp(xi, wi));
    }
    f0r(i, n){
        best[i] = mp(mp(0, -1), mp(0, -1));
    }
    dfs(0, -1);
    dfs1(0, -1, -1);
    f0r(i, n){
        paths.eb(mp(best[i].f.f, i));
    }
    unordered_map<int, int> um;
    sort(all(paths));
    reverse(all(paths));
    f0r(i, n){
        um[paths[i].s] = i;
        //cout << paths[i].f << "  asdf  " << paths[i].s << endl;
    }
    int q;
    cin >> q;
    while(q--){
        ll l;
        cin >> l;
        d.reset();
        int ptr = -1;
        int ans = 0;
        f0r(i, n){
            while(ptr+1 <n && abs(paths[i].f  - paths[ptr+1].f)>l){
                ptr++;
                //cout << ptr << " remove " << i << endl;
                ///remove
                int idx = d.get(paths[ptr].s);
                upd(idx,  -1);
            }
            for(auto nxt: adj[paths[i].s]){
                int v = nxt.f;
                if(um[v] < i && abs(paths[i].f - paths[um[v]].f)<= l){
                    d.unite(v, paths[i].s);
                   //cout << v << " " << paths[i].s << endl;
                }
            }
            ans = max(ans, query(0, MAX-1));

        }
        cout << ans << endl;
    }
    return 0;
}