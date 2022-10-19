#include <bits/stdc++.h>
// #define int long long

using namespace std;

long long cost(int val, int p) {
    return (val / p) * 1LL * (val / p) * (p - val % p) + (val / p + 1) * 1LL * (val / p + 1) * (val % p);
}

long long delt(int val, int p) {
    return cost(val, p) - cost(val, p + 1);
}

int lw(long long d, int val) {
    int l = 0, r = val;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (delt(val, m) > d) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

long long count(long long d, long long e, int n, vector<int> &val) {
    long long sum = 0, ans = 0, count = 0;
    for (int i = 0; i < n; ++i) {
        // int c = lw(d, val[i]) + 1;
        // ans += c - 1;
        // while (c < val[i] && delt(val[i], c) > d) {
        //     c++;
        //     ans++;
        // }
        // sum += cost(val[i], c);
        // while (c < val[i] && delt(val[i], c) == d) {
        //     c++;
        //     count++;
        // }
        // int prv_c = c;
        // c = lw(d - 1, val[i]) + 1;
        // count += c - prv_c;
        int lw1 = lw(d, val[i]), lw2 = lw(d - 1, val[i]);
        count += lw2 - lw1;
        ans += lw1;
        sum += cost(val[i], lw1 + 1);
    }
    if (sum - d * count > e) {
        return -1;
    }
    if (sum > e) {
        ans += (sum - e - 1) / d + 1;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int prv = 0;
    vector<int> val;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        val.push_back(a - prv);
        prv = a;
    }
    long long e;
    cin >> e;
    long long l = 0, r = 1e18 + 10;
    while (l < r - 1) {
        long long m = (l + r) / 2;
        if (count(m, e, n, val) == -1) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << count(l, e, n, val) << '\n';
    return 0;
}