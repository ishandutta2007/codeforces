#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

int gcd(int a, int b) {
    while (b != 0) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}
signed main() {
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> b;
    b.push_back(-1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    for (int i = 1; i < n; i++) {
        if (b.back() != a[i - 1] - a[i] && a[i - 1] - a[i] > 0) {
            b.push_back(a[i - 1] - a[i]);
        }
    }
    if (b.size() == 1) {
        cout << 0 << " " << 0;
        return 0;
    }
    int g = b[1];
    for (int i = 1; i < b.size(); i++) {
        g = gcd(g, b[i]);
    }
    int p = 0;
    for (int i = 0; i < n; i++) {
        p += (a[0] - a[i]) / g;
    }
    cout << p << " " << g;
}