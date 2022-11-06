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

#define maxN 5017
#define mod 1000000007

ll n, k, i, j, a, b, c, limit;
ll dp[maxN][maxN];

ll poww(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> k;

    limit = min(k + 1, n);
    for (b = 0; b <= limit; b++) dp[0][b] = poww(2, n - b);

    for (a = 1; a <= k; a++) {
        for (b = 0; b <= limit; b++) {
            c = n - b;

            if (b > 0) {
                dp[a][b] += b * dp[a - 1][b];
                dp[a][b] %= mod;
            }

            if (c > 0) {
                dp[a][b] += c * dp[a - 1][b + 1];
                dp[a][b] %= mod;
            }
        }
    }

    cout << dp[k][0];


    return 0;
}