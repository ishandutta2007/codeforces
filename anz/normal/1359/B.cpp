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

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> m >> x >> y;
        y = min(y, 2 * x);

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            string board; cin >> board;

            int cnt = 0;
            for (int j = 0; j < m; j++)
            {
                if (board[j] == '.') cnt++;
                else
                {
                    ans += cnt / 2 * y + cnt % 2 * x;
                    cnt = 0;
                }
            }

            ans += cnt / 2 * y + cnt % 2 * x;
        }

        cout << ans << '\n';
    }
}