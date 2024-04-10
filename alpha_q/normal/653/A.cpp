#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x; vector <int> a;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x, a.push_back(x);
    sort (a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();
    for (int i = 0; i < n - 2; i++)
    if (a[i + 2] - a[i + 1] <= 2 and a[i + 1] - a[i] <= 2 and a[i + 2] - a[i] <= 2) {
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
    return 0;
}