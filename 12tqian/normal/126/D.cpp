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
const int LOG = 65;
ll dp [LOG][2];
vector<ll> f;
int main(){
    fast_io();
    int t;
    ll a = 1;
    ll b = 1;
    while(b<1e18){
        f.eb(b);
        ll tmp = b;
        b = a+b;
        a = tmp;
    }
    cin >> t;
    f0r(iteration, t){
        ll n; cin >> n;
        ll N = n;
        vector<int> d;
        for(int i = sz(f) - 1; i>= 0; i--){
            if(N >= f[i]){
                N -= f[i];
                d.eb(1);
            }
            else{
                d.eb(0);
            }
        }
        while(d[0] == 0){
            d.erase(d.begin());
        }
        f0r(i, LOG){
            dp[i][0] = 0;
            dp[i][1] = 0;
        }
        reverse(all(d));
        vi v;
        ll run = 0;
        f0r(i, sz(d)){
            if(d[i] == 0){
                if(run != 0){
                    if(run == 1){
                        v.eb(1);
                    }
                    else{
                        v.eb(2);
                    }
                    run = 0;
                }
                v.eb(0);
            }
            else{
                run++;
            }
        }
        if(run != 0){
            if(run == 1){
                v.eb(1);
            }
            else{
                v.eb(2);
            }
            run = 0;
        }
        int prev = -1;
        int idx = -1;
        f0r(i, sz(v)){
            if(v[i] == 0){
                run++;
            }
            else if(v[i] == 1){
                if(prev == -1){
                    dp[i][0] = 1;
                    dp[i][1] = run/2;

                }
                else{
                    if(prev == 1){
                        dp[i][0] = dp[idx][0] + dp[idx][1];
                        dp[i][1] = dp[idx][0]*(run/2) + dp[idx][1]*((run+1)/2);
                    }
                    else{
                        dp[1][0] = dp[idx][0] + dp[idx][1];
                        dp[i][1] = dp[idx][0]*(run/2);
                    }
                }
                prev = 1;
                idx = i;
                run = 0;
            }
            else{
                if(prev == -1){
                    dp[i][0] = 1;
                    dp[i][1] = run/2;

                }
                else{
                    if(prev == 1){
                        dp[i][0] = dp[idx][0] + dp[idx][1];
                        dp[i][1] = dp[idx][0]*(run/2) + dp[idx][1]*((run+1)/2);
                    }
                    else{
                        dp[1][0] = dp[idx][0] + dp[idx][1];
                        dp[i][1] = dp[idx][0]*(run/2);
                    }
                }
                prev = 2;
                idx = i;
                run = 0;
            }
        }
        ll ans = 0;
        ans = dp[sz(v) - 1][0] + dp[sz(v) - 1][1];
        cout << ans << endl;
    }
    return 0;
}