#pragma GCC optimize("O3")
//#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <bitset>
#include <numeric>
#include <cmath>

//#define _USE_MATH_DEFINES
using namespace std;

struct Line {
    long long k, b;

    Line(long long _k, long long _b) { k = _k, b = _b; }

    long long get(long long x) {
        return k * x + b;
    }
};

vector<Line> lines;
vector<long long> dots;

long long intersect(Line a, Line b) {
    if (a.k > b.k) {
        swap(a, b);
    }
    return (a.b - b.b) / (b.k - a.k);
}

void add(Line l) {
    int sz = lines.size();
    while (sz > 1 && intersect(lines[sz - 1], lines[sz - 2]) > intersect(lines[sz - 2], l)) {
        sz--;
        lines.pop_back();
        dots.pop_back();
    }
    if (lines.empty()) {
        dots.push_back(-1);
    } else {
        dots.push_back(intersect(lines.back(), l));
    }
    lines.push_back(l);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<long long> dp(n);
    dp[0] = 0;
    add(Line(b[0], dp[0]));
    for (int i = 1; i < n; ++i) {
        int pos = lower_bound(dots.begin(), dots.end(), a[i]) - dots.begin() - 1;
        dp[i] = lines[pos].get(a[i]);
        add(Line(b[i], dp[i]));
    }
    cout << dp[n - 1];
    return 0;
}