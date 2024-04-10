#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

using cd = complex<double>;

const int lg = 20, maxn = 1 << lg;

cd w[maxn];

void precalc() {
    w[0] = 1;
    w[1] = cd(cos(M_PI * 2 / maxn), sin(M_PI * 2 / maxn));
    for (int i = 2; i < maxn; ++i) {
        // w[i] = w[i - 1] * w[1];
        w[i] = cd(cos(M_PI * 2 * i / maxn), sin(M_PI * 2 * i / maxn));
    }
}

vector<cd> fft(vector<cd> a) {
    int sz = a.size();
    vector<int> rev(sz);
    int k = 0;
    for (int i = 0;; ++i) {
        if ((1 << i) == sz) {
            k = i;
            break;
        }
    }
    for (int i = 1; i < sz; ++i) {
        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (k - 1));
    }
    for (int i = 0; i < sz; ++i) {
        if (rev[i] < i) {
            swap(a[rev[i]], a[i]);
        }
    }
    for (int lvl = 0; lvl < k; ++lvl) {
        int len = (1 << lvl);
        for (int start = 0; start < sz; start += len * 2) {
            for (int i = 0; i < len; ++i) {
                cd u = a[start + i], v = a[start + i + len];
                a[start + i] = u + w[i << (lg - lvl - 1)] * v;
                a[start + i + len] = u - w[i << (lg - lvl - 1)] * v;
            }
        }
    }
    return a;
}

vector<long long> mul(vector<int> &a, vector<int> &b) {
    int sz = a.size() + b.size();
    while (sz & (sz - 1)) {
        sz++;
    }
    vector<cd> a_nw(sz, cd(0, 0)), b_nw(sz, cd(0, 0));
    for (int i = 0; i < (int)a.size(); ++i) {
        a_nw[i] = cd(a[i], 0);
    }
    for (int i = 0; i < (int)b.size(); ++i) {
        b_nw[i] = cd(b[i], 0);
    }
    a_nw = fft(a_nw);
    b_nw = fft(b_nw);
    for (int i = 0; i < sz; ++i) {
        a_nw[i] *= b_nw[i];
    }
    a_nw = fft(a_nw);
    reverse(a_nw.begin() + 1, a_nw.end());
    vector<long long> ans(sz + 1);
    for (int i = 0; i < sz; ++i) {
        a_nw[i] /= sz;
        ans[i] += round(a_nw[i].real());
    }
    while (ans.size() > 1 && ans.back() == 0) {
        ans.pop_back();
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'V') {
            a[i + 1] = 1;
        }
        if (s[i] == 'K') {
            b[n - i - 1] = 1;
        }
    }
    auto c = mul(a, b);
    while (c.size() < n * 2) {
        c.push_back(0);
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        bool ch = true;
        for (int d = i; d < n; d += i) {
            if (c[n + d] != 0 || c[n - d] != 0) {
                ch = false;
            }
        }
        if (ch) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    for (auto val : ans) {
        cout << val << ' ';
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    precalc();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}