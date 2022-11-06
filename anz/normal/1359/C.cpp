#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m, x, y;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while (T--)
    {
        ll h, c, t; cin >> h >> c >> t;
        if (h + c >= t * 2)
        {
            cout << "2\n";
            continue;
        }

        ll cnt = (t - h) / (h + c - 2 * t) + 1;

        ll v1 = (t * (cnt * 2 + 1) - (h + (h + c) * cnt)) * ((cnt - 1) * 2 + 1);
        ll v2 = (h + (h + c) * (cnt - 1) - t * ((cnt - 1) * 2 + 1)) * (cnt * 2 + 1);

        if (v1 < v2) cout << cnt * 2 + 1 << '\n';
        else cout << cnt * 2 - 1 << '\n';
    }
}