#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int m = -1;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (t > m + 1) {
            cout << i;
            return 0;
        }
        if (t == m + 1) m = t;
    }
    cout << -1;
    return 0;
}