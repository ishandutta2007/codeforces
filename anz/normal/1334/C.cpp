#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
pll a[300001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i].first >> a[i].second;

        ll ans = 0;
        ll min_b = 1e18;

        for (int i = 0; i < n; i++)
        {
            if (a[i].second > a[(i + 1) % n].first)
                a[i].second = a[(i + 1) % n].first;

            ans += a[i].first - a[i].second;
            min_b = min(min_b, a[i].second);
        }

        cout << ans + min_b << '\n';
    }
}