#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1000000007ll;

ll a[1000000];
ll ans[1000000];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++)
        cin >> a[i];
    for(ll i = 1; i <= n; i++)
        ans[i] = (((ll)(2)) * ans[i - 1] + ((ll)(2)) - ans[a[i] - 1] + ((ll)(3)) * MOD) % MOD;
    cout << ans[n];
    return 0;
}