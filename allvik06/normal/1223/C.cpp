#include <bits/stdc++.h>

using namespace std;

#define int long long

int check(vector <int> &s, int k, int middle, int a, int b, int x, int y) {
    int cnt = 0;
    int ans = 0;
    if (x < y) {
        swap(x, y);
        swap(a, b);
    }
    for (int i = 0; i <= middle; ++i) {
        if (((i + 1) % a == 0) && ((i + 1) % b == 0)) {
            ans += s[cnt] * (x + y) / 100;
            ++cnt;
        }
    }
    for (int i = 0; i <= middle; ++i) {
        if (((i + 1) % a == 0) && ((i + 1) % b != 0)) {
            ans += s[cnt] * x / 100;
            ++cnt;
        }
    }
    for (int i = 0; i <= middle; ++i) {
        if (((i + 1) % b == 0) && ((i + 1) % a != 0)) {
            ans += s[cnt] * y / 100;
            ++cnt;
        }
    }
    return (middle + 1) * (ans >= k);
}

signed main()
{
    int q;
    cin >> q;
    for (int w = 0; w < q; ++w) {
        int n, x, y, a, b, k, cnt = 0, res = 1e9;
        cin >> n;
        vector <int> s(n);
        for (int i = 0; i < n ; ++i) {
           cin >> s[i];
        }
        cin >> x >> a;
        cin >> y >> b;
        cin >> k;
        sort(s.rbegin(), s.rend());
        int left = 0, right = n;
        while (right - left > 1) {
            int middle = (left + right) / 2;
            int tmp = check(s, k, middle, a, b, x, y);
            if (tmp > 0 && tmp < res) {
                right = middle;
                res = tmp;
            }
            else {
                left = middle;
            }
        }
        int tmp = check(s, k, left, a, b, x, y);
        if (tmp < res && tmp > 0) {
            res = tmp;
        }
        if (res == 1e9) {
            cout << -1 << "\n";
        }
        else {
            cout << res << "\n";
        }
        s.clear();
    }
}