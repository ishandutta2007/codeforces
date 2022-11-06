#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const int maxN = 1000011;
const ll mod = 998244353;

ll n, i;
ll a[maxN];
ll poww[maxN];
ll ans;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld", &n);
    poww[0] = 1;
    for (i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i] += a[i - 1];
        a[i] %= mod;
        poww[i] = (poww[i - 1] << 1) % mod;
    }

    ans = a[n];

    for (i = 1; i < n; i++) {
        //! prima
        ans += poww[n - i - 1] * a[i];
        ans %= mod;

        //! intre
        if (i + 1 < n) {
            ans += (( poww[n - i - 2] * a[i]  ) % mod) * (n - i - 1); 
            ans %= mod;
        }

        //! ultima
        ans += poww[n - i - 1] * a[i];
        ans %= mod;
    }
    
    cout << ans;


    return 0;
}