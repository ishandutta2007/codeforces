#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
const int MAX = 2e5  +5;
vi adj [MAX];
int color [MAX];
int under[MAX];
int par[MAX];
int vis[MAX];
int dfs(int src){
    vis[src] = 1;
    if(color[src] == -1){
        under[src] += 1;
    }
    for(int neigh: adj[src]){
        if(vis[neigh] == 0){
            par[neigh] = src;
            under[src] += dfs(neigh);
        }
    }
    return under[src];
}
vi path;
void change(int x){
    under[x] += color[x];
    color[x]*= -1;
}
void dfs1(int src){
    if(under[src] == 0){
        return;
    }
    vis[src] = 1;
    for(int neigh: adj[src]){
        if(vis[neigh] == 0 && under[neigh]>0){
            change(neigh);
            path.eb(neigh);
            dfs1(neigh);
            path.eb(src);
            change(src);
            if(color[src] == -1 && src != 0){
                path.eb(par[src]);
                path.eb(src);
                change(src);
                change(par[src]);
            }
        }
    }
}
int main(){
    fast_io();
    int n;
    cin >> n;
    f0r(i, n){
        int d;
        cin >> d;
        color[i] = d;

    }
    f0r(i, n-1){
        int a, b;
        cin >> a >> b;
        adj[a-1].eb(b-1);
        adj[b-1].eb(a-1);
    }
    path.eb(0);
    dfs(0);
    f0r(i, n){
        vis[i] = 0;
    }
    dfs1(0);
    if(color[0] == -1){
        int neigh = adj[0][0];
        path.eb(neigh);
        path.eb(0);
        path.eb(neigh);
        path.eb(0);
        path.eb(neigh);
        path.eb(0);
        path.eb(neigh);
    }
    for(int i: path){
        cout << i + 1 <<  " ";
    }
    return 0;
}