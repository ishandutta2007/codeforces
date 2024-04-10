#include <bits/stdc++.h>

using namespace std;

int k = 475, m, n;
int a[100009];
pair <int, int> b[100009];

void build() {
    for (int i = n - 1; i >= 0; --i) {
        int nowb = i / k, newb = (i + a[i]) / k;
        if (newb > nowb || i + a[i] >= n) {
            b[i] = {i + a[i], 1};
        }
        else {
            b[i] = {b[i + a[i]].first, b[i + a[i]].second + 1};
        }
    }
}

inline pair <int, int> get(int i) {
    int nowans = 0;
    while (true) {
        nowans += b[i].second;
        if (b[i].first >= n) {
            int ans = i;
            while (ans + a[ans] < n) {
                ans += a[ans];
            }
            return {ans, nowans};
        }
        i = b[i].first;
    }
}

inline void update(int i, int v) {
    a[i] = v;
    int bl = i / k, newb = (i + v) / k;
    if (newb > bl || i + v >= n) {
        b[i] = {i + v, 1};
    }
    else {
        b[i] = {b[i + v].first, b[i + v].second + 1};
    }
    --i;
    for (; i >= 0; --i) {
        int nowb = i / k;
        if (nowb < bl) {
            return;
        }
        if (i + a[i] >= n || (i + a[i]) / k > nowb) {
            b[i] = {i + a[i], 1};
            continue;
        }
        b[i] = {b[a[i] + i].first, b[a[i] + i].second + 1};
    }
}
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    m = (n + k - 1) / k;
    build();
    while (q--) {
        int c, aa, bb;
        cin >> c;
        if (c == 0) {
            cin >> aa >> bb;
            update(aa - 1, bb);
        }
        else {
            cin >> aa;
            cout << get(aa - 1).first + 1 << " " << get(aa - 1).second << "\n";
        }
    }
    return 0;
}