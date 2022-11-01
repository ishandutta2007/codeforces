#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

ll a[10000];

ll bitDiff(ll a, ll b)
{
    ll ans = 0;
    ll c = a xor b;
    //cout << c << " " << (1ll << 32ll) << endl;
    for (ll i = 1; i <= (1ll << 32ll); (i <<= 1ll))
        if (c & i)
            ans++;
    return ans;
}

main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n, k, m;
    cin >> n >> m >> k;
    ll answer = 0;
    for (ll i = 0; i <= m; i++)
        cin >> a[i];
    for (ll i = 0; i < m; i++)
        if (bitDiff(a[i], a[m]) <= k)
            answer++;
    cout << answer;

}