#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    int m = INT_MIN;
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m = max(m, a[i]);
        s += a[i];
    }
    for (int i = m;; i++) {
        if (s < n * i - s) {
            cout << i;
            return 0;
        }
    }
    return 0;
}