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
const int MAX = 1e5 + 5;
const int BOUND  = 1e5+5;
vi adj[MAX];
vector<pair<int, pii>> ans;
int depth[MAX];
int p[MAX];
int dfs(int src, int par){
    p[src] = par;
    if(par == -1){
        depth[src] = 0;
    }
    for(int nxt: adj[src]){
        if(nxt == par) continue;
        depth[nxt] = depth[src] + 1;
        dfs(nxt, src);
    }
}
void out(int u, int v, int x){
    if(u == v) return;
    ans.eb(mp(x, mp(u, v)));
}
void ADD(int leaf, int u, int x){
    if(sz(adj[u]) == 1){
        out(u, leaf, x);
        return;
    }
    int v1 = -1;
    int v2 = -1;
    int cur = leaf;
   // cout << cur <<" " << u<< endl;
    int cnt = 0;
    while(p[cur] != u){
        cur = p[cur];
        cnt++;
        if(cnt>= BOUND){
                cout << 1 << endl;
            assert(false);
        }
    }
   // cout << p[cur] << endl;
   // cout << leaf << " " << u << " "<<  cur << endl;
    //cout << sz(adj[u]) << endl;
    if(sz(adj[u]) <3){
            cout << "bad" << endl;
        assert(false);
    }
    for(int nxt: adj[u]){
        if(nxt == cur) continue;
        //cout << cur << " " << nxt << endl;
        if(v1 == -1) v1 = nxt;
        else{v2 = nxt; break;}
    }
   // cout << v1 << " " << v2 << endl;
    int b1 = u;
    int b2 = u;
   // cout <<"begin" << endl;
   cnt = 0;
   assert(v1 != -1 && v2 != -1);
    while(sz(adj[v1]) != 1){
        for(int nxt: adj[v1]){
            if(nxt == b1) continue;
            b1 = v1;
            v1 = nxt;
            break;
        }
        cnt++;
        if(cnt>=BOUND){
                cout << 2  << endl;
            assert(false);
        }
    }
    cnt = 0;
    while(sz(adj[v2]) != 1){
        for(int nxt: adj[v2]){
            if(nxt == b2) continue;
            b2 = v2;
            v2 = nxt;
            break;
        }
        cnt++;
        if(cnt>= BOUND){
            cout << 3 << endl;
            assert(false);
        }
        //cout << v2 << endl;
    }
   // cout << "Ya" << endl;
    out(leaf, v1, x/2);
    out(leaf, v2, x/2);
    out(v1, v2, -x/2);
}
void add(int u, int v, int x){
    if(depth[u] > depth[v]) swap(u, v);
    int cur = v;
    int cnt = 0;
    while(sz(adj[cur]) != 1){
        for(int nxt: adj[cur]){
            if(nxt != p[cur]){
                cur = nxt;
                break;
            }
        }
        cnt++;
        if(cnt>= BOUND) assert(false);
    }
    ADD(cur, u, x);
    if(cur == v) return;
    ADD(cur, v, -x);
}

vector<pair<int, pii>> edges;
int main(){
    fast_io();
    int n;
    cin >> n;
    f0r(i, n-1){
        int u, v, x;
        cin >> u >> v >> x;
        u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
        edges.eb(mp(x, mp(u, v)));
    }
    if(n == 2){
        cout << "YES" << endl;
        cout << 1 << endl;
        for(auto e: edges){
            cout << e.s.f + 1 << " " << e.s.s+1<< " " << e.f << endl;
            return 0;
        }
    }
    f0r(i, n){
        if(sz(adj[i]) == 2){
            cout << "NO" << endl;
            return 0;
        }

    }
    dfs(0, -1);
    for(auto e: edges){
        add(e.s.f, e.s.s, e.f);
    }

    cout << "YES" << endl;
    cout << sz(ans) << endl;
    for(auto e:ans){
        cout << e.s.f +1<< " " << e.s.s + 1<< " " << e.f << endl;
    }
    return 0;
}