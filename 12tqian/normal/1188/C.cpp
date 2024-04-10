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
const ll MOD = 998244353;
//const ll MOD = 1e18;
const int MAX = 1e3 + 5;
const int BIG = 105;
ll dp[MAX][MAX];
ll exact[MAX][MAX];
ll sum[MAX][MAX];
ll sume[MAX][MAX];
int a [MAX];
int main(){
    fast_io();
    int n, k;
    scanf("%d %d", &n, &k);
    f0r(i, n){
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    ll mx = a[n-1];
    ll ans = 0;
    f0r(b, mx/(k-1)+4){ //array beauty of b
        f1r(i,1,  k+1){// you've chosen i of them
            f0r(j, n){ //looked at last
                dp[i][j] = 0;
                exact[i][j] = 0;
                sume[i][j] = 0;
                sum[i][j] = 0;
            }
        }
        bool flag = true;
        f1r(i, 1, k+1){
            if(i == 1){
                f0r(j, n){
                    dp[i][j] = 1;
                }
                f0r(j, n){
                    if(j == 0){
                        sum[i][j] = 1;
                    }
                    else{
                        sum[i][j] = sum[i][j-1] + dp[i][j];
                        if(sum[i][j]>= MOD) sum[i][j] -= MOD;
                    }
                }
                continue;
            }
            int diff = -1;
            int bef = 0;
            f0r(j, n){
                while(bef+1 <= j && a[j] - a[bef+1]>= b){
                    bef++;
                }
                while(diff + 1<bef&&a[diff+1] != a[bef]){
                    diff++;
                }
                if(a[j] - a[bef] < b){
                    continue;
                }
                if(a[j] - a[bef] == b){
             //       exact[i][j] += dp[i-1][bef];
                    if(diff == -1){
                        exact[i][j] += sum[i-1][bef];
                    }
                    else{
                        exact[i][j] += (sum[i-1][bef] - sum[i-1][diff]);
                        exact[i][j] %= MOD;
                        exact[i][j] += MOD;
                        exact[i][j] %= MOD;
                    }
                    if(exact[i][j]>= MOD) exact[i][j] -= MOD;
                    if(bef>0 && diff != -1){
                        dp[i][j] += sum[i-1][diff];
                        if(dp[i][j]>= MOD) dp[i][j] -= MOD;
                    }
                }
                else{
                    dp[i][j] += sum[i-1][bef];
                    if(dp[i][j]>= MOD) dp[i][j] -= MOD;
                }
                exact[i][j] += sume[i-1][bef];
                if(exact[i][j]>= MOD) exact[i][j] -= MOD;
                if(j == 0){
                    sum[i][j] = dp[i][j];
                    sume[i][j] = exact[i][j];
                }
                else{
                    sum[i][j] = sum[i][j-1] + dp[i][j];
                    if(sum[i][j]>= MOD) sum[i][j] -= MOD;
                    sume[i][j] = sume[i][j-1] + exact[i][j];
                    if(sume[i][j]>= MOD) sume[i][j] -= MOD;
                }


            }
        }
        ll times = 0;
        f0r(i, n){
            times += exact[k][i];
            if(times >= MOD) times-= MOD;
        }
        ans += (b*times)%MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}