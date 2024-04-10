#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int64_t ans = 0;
    for(int i = 1; i <= k && 2 * i <= n; i++)
    {
        ans += 2 * (n - 2 * (i - 1) - 1) - 1;
    }
    cout << ans << "\n";
}