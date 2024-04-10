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
        ll n, x, t; cin >> n >> x >> t;
        ll a = t / x;
        if (a + 1 <= n)
            cout << a * (a + 1) / 2 + (n - a - 1) * a << '\n';
        else
            cout << n * (n - 1) / 2 << '\n';
    }
}