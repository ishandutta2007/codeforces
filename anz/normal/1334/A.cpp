#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;

        bool ans = true;
        int p, c; cin >> p >> c;

        if (p < c) ans = false;
        for (int i = 1; i < n; i++)
        {
            int tp, tc; cin >> tp >> tc;
            if (p > tp || c > tc) ans = false;
            if (tp - p < tc - c) ans = false;

            p = tp, c = tc;
        }

        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
}