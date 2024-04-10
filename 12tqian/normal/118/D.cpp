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
const int MOD = 1e8;
const int MAX = 1e2 + 5;
const int MAXK = 1e1 + 5;
int dp1[MAX][MAX][MAXK];
int dp2[MAX][MAX][MAXK];
int main(){
    fast_io();
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    dp1[1][0][1] = 1;
    dp2[0][1][1] = 1;
    f1r(i, 2, n1 + n2 + 1){
        f0r(j, min(i, n1) + 1){
            int k = i - j;
            if(k>n2){
                continue;
            }
            //j first type, k second type
            f1r(it, 1, k1+ 1){
                if(it == 1){
                    f1r(num, 1, k2+1){
                        if(j>0){
                            dp1[j][k][it] += dp2[j-1][k][num];
                            dp1[j][k][it] = dp1[j][k][it]%MOD;
                        }
                    }
                }
                else{
                    if(j>0){
                        dp1[j][k][it] += dp1[j-1][k][it-1];
                        dp1[j][k][it] = dp1[j][k][it]%MOD;
                    }

                }
            }
            f1r(it, 1, k2+ 1){
                if(it == 1){
                    f1r(num, 1, k1+1){
                        if(k>0){
                            dp2[j][k][it] += dp1[j][k-1][num];
                            dp2[j][k][it] = dp2[j][k][it]%MOD;
                        }
                    }
                }
                else{
                    if(k > 0){
                        dp2[j][k][it] += dp2[j][k-1][it-1];
                        dp2[j][k][it] = dp2[j][k][it]%MOD;
                    }

                }
            }
        }
    }
    int ans = 0;
    f1r(i, 1, k1+1){
        ans += dp1[n1][n2][i];
        ans = ans%MOD;
    }
    f1r(i, 1, k2+1){
        ans += dp2[n1][n2][i];
        ans = ans%MOD;
    }
    cout << ans << endl;
    return 0;
}