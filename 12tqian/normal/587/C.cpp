#pragma comment(linker, "/stack:200000000")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Tree;

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

#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)

#define read1(a) int a; scanf("%d", &a)
#define read2(a,b) int a,b; scanf("%d %d", &a, &b)
#define read3(a,b,c) int a,b,c; scanf("%d %d %d", &a, &b, &c)
#define read(n,arr) int arr[n]; f0r(i,n){ scanf("%d", &arr[i]); }
#define print1(a) printf("%d \n", a)
#define print2(a, b) printf("%d %d \n", a, b)
#define print3(a, b, c) printf("%d %d %d \n", a, b, c)
#define print(v) for (int i : v) { printf("%d ", i); } printf("\n")

#define debug printf("asdf\n");
#define newl printf("\n");
#define usaco(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
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
const int LOG = 18;

static int n, m, q;

static vector<int> adj[MAX];
static int depth[MAX];
static int par[MAX][LOG];
vector<int> people [MAX][LOG];
vector<int> city[MAX];
inline vi merge(vi a, vi b) {
    for (int x : a)
        b.eb(x);
    sort(b.begin(), b.end());
  //  b.erase( unique( all(b) ), b.end() );
    if (b.size() <= 10)
        return b;
    b.resize(10);
    return b;
}

void dfs(int cur, int prev) {
    par[cur][0] = prev;
   // people[cur][0] = merge(people[cur][0], city[prev]);
    if(city[cur].size() >10){
        city[cur].resize(10);
    }
    people[cur][0] = city[cur];
    for (int nxt : adj[cur]) {
        if (nxt == prev)
            continue;

        depth[nxt] = depth[cur] + 1;
        dfs(nxt, cur);
    }
}


void process() {
    depth[0] = 0;
    dfs(0, 0);
    for (int lvl = 0; lvl < LOG - 1; lvl ++) for (int cur = 0; cur< n; cur++) {
        int mid = par[cur][lvl];
        //pushAll(cur, lvl+1, cur, lvl);
        //pushAll(cur, lvl+1, mid, lvl);
        people[cur][lvl+1] = merge( people[mid][lvl], people[cur][lvl]);
        par[cur][lvl + 1] = par[mid][lvl];
    }
}
void lca(int u, int v, int a) {
    set<int> ans;
    if (depth[u] < depth[v])
        swap(u, v);
    for (int it = LOG - 1; it >= 0; it--)
        if (depth[u] - depth[v] >= (1 << it)){
            //addAll(u, it);
            for(int x: people[u][it]){
                ans.insert(x);
            }
           // cout << u+1 << " df " << (1<< it) << endl;
            u = par[u][it];
        }
    if(u!= v){
        int idx = -1;
        for (int it = LOG - 1; it >= 0; it--) {
            idx = it;
            if (par[u][it] != par[v][it]) {
               // cout << u+1 << " df " << v+1 << " "<<(1<< it) << endl;
                for(int x: people[u][it]){
                    ans.insert(x);
                }
                for(int x: people[v][it]){
                    ans.insert(x);
                }
                u = par[u][it];
                v = par[v][it];
            }
        }
        if(u!= v && idx>= 0){
            for(int x: people[u][idx]){
                    ans.insert(x);
                }
            for(int x: people[v][idx]){
                ans.insert(x);
            }
           // cout << u+1 << " df " << v+1 << " "<< (1<< idx) << endl;
            u = par[u][idx];
            v = par[v][idx];


        }
    }
    for(int x: people[u][0]){
                ans.insert(x);
            }
    int k = min(a, sz(ans));
    printf("%d ", k);
    int num = 0;
    for(auto x: ans){
        printf("%d ", x+1);
        num++;
        if(num == k){
            break;
        }
    }
    printf("\n");
}
inline int LCA(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);

    for (int it = LOG - 1; it >= 0; it--)
        if (depth[u] - depth[v] >= (1 << it))
            u = par[u][it];

    if (u == v)
        return u;

    for (int it = LOG - 1; it >= 0; it--) {
        if (par[u][it] != par[v][it]) {
            u = par[u][it];
            v = par[v][it];
        }
    }

    return par[u][0];
}
int main(){
    fast_io();
    scanf("%d %d %d", &n, &m, &q);
    f0r(i, n-1){
        int u, v;
        scanf("%d %d", &u, &v); ;
        u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    f0r(i, m){
        int c;
        scanf("%d", &c);
        c--;
        city[c].eb(i);
       //push(c, 0, i);
    }
    process();
    f0r(i, q){
        int u, v, a;
        scanf("%d %d %d", &u, &v, &a);
        u--; v--;
        lca(u, v, a);
       /* vi lhs, rhs;
        int l = LCA(u, v);

        for (int it = LOG - 1; it >= 0; it--) {
            if (depth[u] - depth[l] >= (1 << it)) {
                lhs = merge(lhs, people[u][it]);
                u = par[u][it];
            }
        }
        for (int it = LOG - 1; it >= 0; it--) {
            if (depth[v] - depth[l] >= (1 << it)) {
                rhs = merge(rhs, people[v][it]);
                v = par[v][it];
            }
        }

        //cout << u << ' ' << v << ' ' << lca << endl;
        //print(lhs);
        //print(rhs);

        vi ans = merge(merge(lhs, rhs), people[l][0]);
        int k = ans.size();
        k = min(k, a);
        cout << k << ' ';
        f0r (i, k)
            cout << ans[i] + 1 << ' ';
        cout << endl;*/

    }
    return 0;
}