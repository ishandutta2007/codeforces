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
const int MOD = 1e9+7;

vi adj[MAX];

int c[MAX];
ll po[MAX];
ll dp[2][MAX];
vi ans;
//returns number of edges to divide up tree with vertex src
int dfs(int src, int par){
    if(c[src] == 0){
        dp[0][src] = 1;
        dp[1][src] = 0;
    }
    else{
        dp[0][src] = 0;
        dp[1][src] = 1;
    }
    for(int neigh: adj[src]){
        ll x = 0;
        ll y = 0;
        if(neigh != par){
            dfs(neigh, src);
            x += dp[0][src]*dp[0][neigh];
            y += (dp[1][src]*dp[0][neigh] + dp[0][src]*dp[1][neigh]);
            x += dp[0][src]*dp[1][neigh];
            y += dp[1][src]* dp[1][neigh];
            x = x%MOD;
            y = y%MOD;
            dp[0][src] = x;
            dp[1][src] = y;
        }

    }
}

int main(){
    fast_io();
    int n;
    cin >> n;
    f0r(i, n-1){
        int pi;
        cin >> pi;
        adj[i+1].eb(pi);
        adj[pi].eb(i+1);
    }
    f0r(i, n){
        cin >> c[i];
    }
    dfs(0, -1);
    cout << dp[1][0] << endl;
    return 0;
}