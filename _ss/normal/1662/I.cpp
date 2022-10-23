#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, m, a[N], pos[N], x[N];
int l[N], r[N];
long long s[N];

long long get(int l, int r) { // [l, r]
    assert(l <= r);

    l = lower_bound(pos, pos + n, l) - pos;
    r = upper_bound(pos, pos + n, r) - pos - 1;
    if (l > r) {
        return 0;
    }

    long long res = s[r];
    if (l) {
        res -= s[l - 1];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s[i] += a[i];
        if (i) {
            s[i] += s[i - 1];
        }
        pos[i] = i * 100;
    }
    for (int i = 0; i < m; ++i) {
        cin >> x[i];
    }
    sort(x, x + m);
    int ptr = 0;
    for (int i = 0; i < n; ++i) {
        while (ptr < m && x[ptr] <= pos[i]) {
            ++ptr;
        }
        if (ptr - 1 >= 0) {
            l[i] = x[ptr - 1];
        } else {
            l[i] = -1;
        }
    }

    ptr = m - 1;
    for (int i = n - 1; i >= 0; --i) {
        while (ptr >= 0 && pos[i] <= x[ptr]) {
            --ptr;
        }
        if (ptr + 1 < m) {
            r[i] = x[ptr + 1];
        } else {
            r[i] = 2e9;
        }
    }

//    for (int i = 0; i < n; ++i) {
//        cerr << pos[i] << ' ' << l[i] << ' ' << r[i] << endl;
//    }

    long long res = 0;
    for (int i = 0; i < n; ++i) {
        if (l[i] == pos[i]) {
            continue;
        }
        if (l[i] == -1) {
            res = max(res, get(pos[i], r[i] - 1));
        } else {
            int shop = min(r[i], 2 * pos[i] - l[i]);
            res = max(res, get(pos[i], min(r[i] - 1, shop + (r[i] - shop - 1) / 2)));
        }
    }
    cout << res << '\n';
    return 0;
}