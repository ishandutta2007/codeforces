#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        long long n, m, k;
        cin >> n >> m >> k;
        if (k < max(n, m))
        {
            cout << -1 << "\n";
            continue;
        }
        if ((n + m) % 2)
        {
            cout << k - 1 << "\n";
        }
        else
        {
            long long ans = max(n, m);
            k -= max(n, m);
            ans += (k / 2) * 2;
            k %= 2;
            if (k)
                ans--;
            cout << ans << "\n";
        }
    }
}