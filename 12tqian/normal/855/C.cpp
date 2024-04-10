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
const int MAXK = 15;

int n, m, k, x;
vi adj[MAX];
ll dp [MAX][3][MAXK];
ll run[MAXK];
void dfs(int src, int par){
    dp[src][0][0] = k-1;
    dp[src][1][1] = 1;
    dp[src][2][0] = m-k;
    for(int i: adj[src]){
        if(i!= par){
            dfs(i, src);
            memset(run, 0, sizeof run);
            f0r(ii, 11){
                f0r(jj, 11-ii){
                    run[ii + jj] += (dp[src][0][ii]*(dp[i][0][jj] + dp[i][1][jj] + dp[i][2][jj]));
                    run[ii + jj] = run[ii+jj]%MOD;
                }
            }
            f0r(ii, 11){
                dp[src][0][ii] = run[ii];
            }
            memset(run, 0, sizeof run);
            f0r(ii, 11){
                f0r(jj, 11-ii){
                    run[ii + jj] += (dp[src][1][ii]*(dp[i][0][jj]));
                    run[ii + jj] = run[ii+jj]%MOD;
                }
            }
            f0r(ii, 11){
                dp[src][1][ii] = run[ii];
            }
            memset(run, 0, sizeof run);
            f0r(ii, 11){
                f0r(jj, 11-ii){
                    run[ii + jj] += (dp[src][2][ii]*(dp[i][0][jj] + dp[i][2][jj]));
                    run[ii + jj] = run[ii+jj]%MOD;
                }
            }
            f0r(ii, 11){
                dp[src][2][ii] = run[ii];
            }
        }
    }
}
int main(){
    fast_io();
    cin >> n >> m;
    f0r(i, n-1){
        int u, v;
        cin >> u >> v;
      //  u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    cin >> k >> x;
    dfs(1, 0);
    ll ans = 0;
    f0r(i, x+1){
        f0r(it, 3){
            ans += dp[1][it][i];
            ans = ans%MOD;
        }
    }
    cout << ans << endl;
    return 0;
}