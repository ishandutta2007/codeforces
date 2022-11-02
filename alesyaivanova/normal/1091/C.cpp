#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    set<int> ans;
    ans.insert((n + 1) * n / 2);
    ans.insert(1);
    for (int k = 2; k * k <= n; k++)
    {
        if (n % k != 0)
            continue;
        ans.insert((n / k - 1) * k * (n / k) / 2 + n / k);
        int u = n / k;
        ans.insert((n / u - 1) * u * (n / u) / 2 + n / u);
    }
    for (int q : ans)
        cout << q << " ";
}