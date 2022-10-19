#pragma GCC target("popcnt")
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <array>
#include <algorithm>
#include <cmath>

using namespace std;
#define ll long long

vector <ll> a, mx, mn;
vector <int> c, val;
ll answer = 0;

inline int get_c(ll b) {
    return __builtin_popcountll(b);
}

void calc(int l, int r) {
    if (l == r) {
        ++answer;
        return;
    }
    int m = (l + r) / 2;
    mx[m] = mn[m] = a[m];
    for (int i = m - 1; i >= l; --i) {
        mn[i] = min(mn[i + 1], a[i]);
        mx[i] = max(mx[i + 1], a[i]);
    }
    mx[m + 1] = mn[m + 1] = a[m + 1];
    for (int i = m + 2; i <= r; ++i) {
        mx[i] = max(mx[i - 1], a[i]);
        mn[i] = min(mn[i - 1], a[i]);
    }
    c[m] = 1;
    for (int i = m - 1; i >= l; --i) c[i] = c[i + 1] + (get_c(mx[i]) == get_c(mn[i]));
    int mxc = m + 1, mnc = m + 1;
    val.assign(64, 0);
    for (int i = m + 1; i <= r; ++i) {
        while (mxc - 1 >= l && mx[mxc - 1] <= mx[i]) {
            --mxc;
            if (mxc < mnc) ++val[get_c(mn[mxc])];
            else --val[get_c(mx[mxc])];
        }
        while (mnc - 1 >= l && mn[mnc - 1] >= mn[i]) {
            --mnc;
            if (mnc < mxc) ++val[get_c(mx[mnc])];
            else --val[get_c(mn[mnc])];
        }
        answer += (get_c(mx[i]) == get_c(mn[i])) * (m - max(mnc, mxc) + 1);
        if (mnc < mxc) answer += val[get_c(mn[i])];
        else answer += val[get_c(mx[i])];
        int prev = 0;
        if (min(mnc, mxc) != m + 1) prev = c[min(mnc, mxc)];
        answer += c[l] - prev;
    }
    calc(l, m);
    calc(m + 1, r);
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    mx.resize(n);
    mn.resize(n);
    c.resize(n);
    calc(0, n - 1);
    cout << answer;
}