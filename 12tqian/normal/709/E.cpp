#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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
const int MAX = 4e5+5;
static int n;
vi adj [MAX];
static int par [MAX];
static int depth[MAX];
static int under [MAX];
static int vis[MAX];
static int ans [MAX];
int mx1 = 0;
int mx2 = 0;
int idx = -1;
int dfs(int src){
    if(src == 0){
        depth[src] = 0;
    }
    int ans = 1;
    vis[src] = 1;
    for(int neigh: adj[src]){
        if(vis[neigh] == 0){
            par[neigh] = src;
            depth[neigh] = depth[src] +1;
            ans += dfs(neigh);
        }
    }
    under[src] = ans;
    return ans;
}
int getCentroid(int src){
    bool isTrue = true;
    vis[src] = 1;
    int heavy = 0;
    for(int neigh: adj[src]){
        if(vis[neigh] == 0){
            if(under[neigh] >n/2){
                isTrue = false;
            }
            if(heavy == 0 || under[heavy] <under[neigh]){
                heavy = neigh;
            }
        }
    }
    if(isTrue && n-under[src] <= n/2){
        return src;
    }
    return getCentroid(heavy);
}
void dfs1(int src, int par){
    vis[src] = 1;

    for(int neigh: adj[src]){
        if(vis[neigh] == 0){
            if(par == -1){
                dfs1(neigh, neigh);
            }
            else{
                dfs1(neigh, par);
            }

        }
    }
    if(par == -1){
        return;
    }
    if(idx == par){
        if(n-under[src] - mx2 <= n/2){
            ans[src] = 1;
            return;
        }
    }
    else{
        if(n-under[src] - mx1 <= n/2){
            ans[src] = 1;
            return;
        }
    }
    if(under[par] == n - n/2){
        ans[src] = 1;
        return;
    }
    ans[src] = 0;
    return;
}
int main(){
    fast_io();
    cin >> n;
    f0r(i, n-1){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    dfs(0);
    f0r(i, n){
        vis[i] = 0;
    }
    int root = getCentroid(0);
    f0r(i, n){
        vis[i] = 0;
        par[i] = 0;
        under[i] = 0;
        depth[i] = 0;
    }
    dfs(root);
    f0r(i, n){
        vis[i] = 0;
    }
    ans[root] = 1;
    int times = 0;
    for(int neigh:adj[root]){
        if(under[neigh] > mx1){
            mx1 = under[neigh];
            times = 1;
            idx = neigh;
        }
        else if(under[neigh] == mx1){
            times += 1;
        }
    }
    if(times > 1){
        mx2 = mx1;
    }
    else{
        for(int neigh:adj[root]){
            if(under[neigh] == mx1){
                continue;
            }
            if(under[neigh] >mx2){
                mx2 = under[neigh];
            }
        }
    }
    dfs1(root, -1);
  //  cout << root << endl;
    f0r(i, n){
        cout << ans[i] << " " ;
    }
}