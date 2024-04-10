#include <bits/stdc++.h>

#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 10000001ll;
const ll MOD = 1000000007ll;

bool prime[N];

set <ll> divs;
set <ll> :: iterator it;

main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll a, b;
    cin >> a >> b;
    ll ans = (a * (a + 1) / 2) % MOD;
    ans *= b;
    ans %= MOD;
    ans += a;
    ans %= MOD;
    ans *= ((b * (b - 1)) / 2 % MOD);
    ans %= MOD;

    cout << ans;



}