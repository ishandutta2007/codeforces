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
const int MOD = 1e9 + 7;
template <int SZ> struct tarjan{
    int timer , top;
    vector<int>  adj [SZ];
    int dfsn[SZ] , pila[SZ] , inpila[SZ] , comp[SZ];
    int idx [SZ];
    int N;
    vector<vector<int>> components;
    void addEdge(int u, int v){
        adj[u].emplace_back(v);
    }
    int dfs(int u){
        int low = dfsn[u] = ++timer;
        inpila[pila[top++] = u] = 1;
        for(int v: adj[u]){
            if(dfsn[v] == 0){
                low = min(low, dfs(v));
            }
            else if(inpila[v]){
                low = min(low, dfsn[v]);
            }
        }
        if(low == dfsn[u]){
            int fin;
            do
            {
                fin = pila[--top];
                inpila[fin] = 0;
                comp[fin] = u;
            }while(fin != u);
        }
        return low;
    }

    void SCC(){
        timer = 0;
        for(int i = 0; i <SZ; i++){
            if(!dfsn[i]){
                dfs(i);
            }
        }
        for(int i =0 ; i<N; i++){
            idx[i] = -1;
        }
        int cur = 0;
        for(int i = 0; i<N; i++){
            if(idx[comp[i]] == -1){
                idx[comp[i]] = cur;
                cur++;
                vector<int> temp;
                components.emplace_back(temp);
            }
            components[idx[comp[i]]].emplace_back(i);
        }

    }

};
vi cost;
const int MAX =  1e5 + 5;
tarjan<MAX> s;
int main(){
    fast_io();
    int n, m;
    cin >> n;
    s.N = n;
    f0r(i, n){
        int d;
        cin >> d;
        cost.eb(d);
    }
    cin >> m;
    f0r(i, m){
        int u, v;
        cin >> u >> v;
        u--; v--;
        s.addEdge(u, v);
    }
    s.SCC();
    ll ans = 1;
    ll total = 0;
    f0r(i, sz(s.components)){
        int mn = 1e9;
        int num = 0;
        f0r(j, sz(s.components[i])){
            if(mn == cost[s.components[i][j]]){
                num++;
            }
            else if(mn>cost[s.components[i][j]]){
                num = 1;
            }
            mn = min(mn, cost[s.components[i][j]]);
        }
        total += mn;
        ans = ans*num;
        ans = ans%MOD;
    }
    cout << total << " " << ans << endl;
    return 0;
}