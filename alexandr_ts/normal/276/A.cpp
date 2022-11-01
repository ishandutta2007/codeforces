#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 30000ll;
const ll MOD = 1000000007ll;
const ll P = 259ll;
ll a[N];
ll b[N];
bool an[N];
bool am[N];


main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n, k;
    ll maxans = -100000000000;
    cin >> n >> k;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        if (k >= b[i])
            maxans = max(maxans, a[i]);
        else
            maxans = max(maxans, a[i] + k - b[i]);
    }
    cout << maxans;
}