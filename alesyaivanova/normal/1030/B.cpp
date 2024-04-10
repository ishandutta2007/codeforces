#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, d, m;
    cin >> n >> d >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (y >= -d + x && y <= d + x && y >= d - x && y <= (2 * n - d) - x)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}