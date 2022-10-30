#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    long long n, m;
    cin >> n >> m;
    if (2 * m >= n) cout << 0 << " ";
    else cout << n - 2 * m << " ";
    for (long long i = 0; i <= n; i++) {
        if (i * (i - 1) / 2 >= m) {
            cout << n - i << " ";
            return 0;
        }
    }
    return 0;
}