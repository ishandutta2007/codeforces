#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <bool> points(m + 1, 1);
    while (n --> 0) {
        int t1, t2;
        cin >> t1 >> t2;
        for (int i = t1; i <= t2; i++)
            points[i] = 0;
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
        ans += points[i];
    cout << ans << "\n";
    for (int i = 1; i <= m; i++)
        if (points[i])
            cout << i << " ";
    return 0;
}