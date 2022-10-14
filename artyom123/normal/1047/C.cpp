#include <bits/stdc++.h>

using namespace std;

#define int long long 

int gcd(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    while (b > 0) {
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
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(a[i], mx);
    }
    int now = a[0];
    for (int i = 1; i < n; i++) {
        now = gcd(now, a[i]);
    }
    for (int i = 0; i < n; i++) {
        a[i] /= now;
    }
    vector<int> e(mx + 1);
    e[mx] = mx;
    for (int i = 2; i < mx; i++) {
        if (e[i] == 0) {
            e[i] = i;
            for (int j = i * i; j <= mx; j += i) {
                e[j] = i;
            }
        }
    }
    map <int, int> m;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        while (x > 1) {
            int temp = e[x];
            while (x % temp == 0) {
                x /= temp;
            }
            m[temp]++;
        }
    }
    int ans = 0;
    for (auto &c : m) {
        ans = max(ans, c.second);
    }
    if (ans == 0) {
        cout << -1;
        return 0;
    }
    cout << n - ans;
    return 0;
}