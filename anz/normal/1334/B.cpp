#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, x;
ll a[100001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> x;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);

        ll ans = 0;
        ll sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            sum += a[i];
            if (sum / (n - i) >= x) ans = n - i;
        }

        cout << ans << '\n';
    }
}