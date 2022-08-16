#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
#define  x                     first                 
#define  y                     second                
 
const ll   N     =  1e6+5;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
#define maxBits 22
#define maxMask (1<<maxBits)
 
const int MAXN = 1 * 1000 + 10;
 
int ans[MAXN][MAXN];
 
int main ()
{
    ios::sync_with_stdio(false);
 
    int n, d, k;
    cin >> n >> k >> d;
 
    ll tmp = 1;
    bool check = false;
    for (int i = 0; i < d; i ++)
    {
        tmp *= k;
        if (tmp >= n)
        {
            check = true;
            break;
        }
    }
 
    if (!check) 
    {
        cout << -1 << endl;
        return 0;
    }
 
    for (int i = 1; i < n; i ++) 
    {
        for (int j = 0; j < d; j ++) ans[i][j] = ans[i - 1][j];
        for (int j = d - 1; j >= 0; j --)
        {
            ans[i][j] = (ans[i][j] + 1) % k;
            if (ans[i][j]) break;
        }
    }
 
    for (int i = 0; i < d; i ++, cout << endl)
        for (int j = 0; j < n; j ++)
            cout << ans[j][i] + 1 << ' ';
    return 0;
}