#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector <int> b = a;
    sort(b.begin(), b.end());
    multiset <int> s;
    for (int i = n - m * k; i < n; i++) {
        s.insert(b[i]);
    }
    int now = 0;
    int g = 0;
    long long ans = 0;
    for (auto &c : s) {
        ans += c;
    }
    cout << ans << "\n";
    for (int i = 0; i < n; i++) {
        if (s.find(a[i]) != s.end()) {
            now++;
            s.erase(s.find(a[i]));
        }
        if (now == m) {
            now = 0;
            g++;
            cout << i + 1 << " ";
        }
        if (g == k - 1) {
            break;
        }
    }
    return 0;
}