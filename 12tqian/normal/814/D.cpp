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
const int MAX = 1e3+5;
vector<pair<pair<ll, ll>, ll>> circles;
bool surround(int i, int j){
    double dist2 = sqrt((circles[i].f.f - circles[j].f.f)*(circles[i].f.f - circles[j].f.f) + (circles[i].f.s - circles[j].f.s)*(circles[i].f.s - circles[j].f.s));
    if(dist2 + circles[j].s <= circles[i].s){
        return true;
    }
    return false;

}

vi adj[MAX];
ll area[MAX];
int par[MAX];
ll dp[2][2][MAX];

int no(int i){
    if(i == 0){
        return 1;
    }
    return 0;
}

void dfs(int src){
    ll tmp[2][2];
    f0r(i, 2){
        f0r(j, 2){
            tmp[i][j] = 0;
        }
    }
    for(int neigh: adj[src]){
        if(par[src] != neigh){
            dfs(neigh);
            f0r(i, 2){
                f0r(j, 2){
                    tmp[i][j] += dp[i][j][neigh];
                }
            }
        }

    }
    f0r(i, 2){
        f0r(j, 2){
            int m1, m2;
            if(i == 0){
                m1 = 1;
            }
            else{
                m1 = -1;
            }
            if(j == 0){
                m2 = 1;
            }
            else{
                m2 = -1;
            }
            dp[i][j][src] = max(tmp[no(i)][j] + area[src]*m1, tmp[i][no(j)]+ area[src]*m2);
        }
    }
}
int main(){
    fast_io();
    int n;
    cin >> n;
    f0r(i, n){
        ll xi, yi, ri;
        cin >> xi >> yi >> ri;
        circles.eb(mp(mp(xi, yi), ri));
    }
    f0r(i, MAX) par[i] = -1;
    f0r(i, n){
        area[i] = circles[i].s * circles[i].s;
        ll rad = 1e18;
        int idx = -1;
        f0r(j, n){
            if(i == j) continue;
            if(surround(j, i)){
                if(rad>circles[j].s){
                    rad = circles[j].s;
                    idx = j;
                }
            }
        }
        par[i] = idx;
        adj[par[i]].eb(i);
    }
    ll ans = 0;
    f0r(i, n){
        if(par[i] == -1){
            dfs(i);
            ans += dp[0][0][i];
        }

    }

    double fin = ans;
    fin = fin*PI;
    cout << setprecision(50)  << fin << endl;
    return 0;
}