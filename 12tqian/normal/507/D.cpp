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
const int MAX = 1e3 + 5;
ll dp[MAX][MAX];//i j length i suffix j mod k no 0 o r0
ll zero[MAX][MAX];
ll po [MAX];
int main(){
    fast_io();
    ll n, m, k;
    cin >> n >> k >> m;
    po[0] = 1;
    f0r(i, n+4){
        if(i == 0) continue;
        po[i] = po[i-1]*10;
        po[i]%= k;
    }
    f0r(i, n-1){
        if(i == 0){
            f0r(j, 10){
                dp[i][j%k]++;
            }
            continue;
        }
        f0r(j, 10){
            ll add = j*po[i];
            add %= k;
            f0r(pre, k){
                if(pre == 0){
                    dp[i][pre] += dp[i-1][pre];
                    dp[i][pre]%= m;
                    continue;
                }
                dp[i][(pre + add)%k] += dp[i-1][pre];
                dp[i][(pre + add)%k] %= m;
            }
        }
        if(i == 1){
            f0r(j, 10){
                ll add = po[i] * j;
                zero[i][add%k]++;
                zero[i][add%k]%= m;
            }

            continue;
        }
        f0r(j, 10){
            ll add = po[i] * j;
            zero[i][add%k]++;
            zero[i][add%k]%= m;
        }
        f0r(j, 10){
            ll add = j*po[i];
            add%= k;

            f0r(pre, k){
                if(pre == 0){
                    zero[i][pre] += zero[i-1][pre];
                    zero[i][pre]%= m;
                    continue;
                }
                zero[i][(pre + add)%k] += zero[i-1][pre];
                zero[i][(pre + add)%k] %= m;
            }
        }
    }
    ll ans = 0;

    if(n == 1){
        f1r(i, 1, 10){
            if(i%k == 0){
                ans++;
            }
        }
        cout << ans%m << endl;
        return 0;
    }
    f1r(i,1,  10){
        ll add = i*po[n-1];
        add %= k;
        f0r(pre, k){
            if(pre == 0){
                ans += dp[n-2][pre];
                ans %= m;
            }
            else{
                if((pre + add)%k == 0){
                    ans += dp[n-2][pre];
                    ans %= m;
                }
            }
        }
    }
    ll sub = 0;

    if(n == 2){
        f1r(i, 1, 10){
            ll add = i*po[n-1];
            add%= k;
            if(add%k != 0){
                sub++;
                sub%= m;
            }
        }
    }
    else{
        f0r(j, 10){
            ll add = po[n-1] * j;
            if(add%k!=0){
                sub++;
            }
        }
        f1r(i,1,  10){
            ll add = i*po[n-1];
            add %= k;
            f0r(pre, k){
                if(pre == 0){
                    continue;
                }
                else if((pre + add)%k != 0){
                    sub += zero[n-2][pre];
                    sub %= m;
                }

            }
        }
    }
   // cout << ans << " " << sub << endl;
    cout << ((ans - sub)%m + m)%m << endl;
    return 0;
}