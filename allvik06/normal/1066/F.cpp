#include <bits/stdc++.h>

using namespace std;
#define int long long
bool cmp(pair <int, int> &a, pair <int, int> &b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int f(int x1, int y1, int x2, int y2) {
    return abs(y1 - y2) + abs(x1 - x2);
}

pair <int, int> f1(int x, int y, vector <pair <int, int>> &b) {
    int tmp = f(x, y, b.front().first, b.front().second) +
            f(b.front().first, b.front().second, b.back().first, b.back().second);
    int tmp1 = f(x, y, b.back().first, b.back().second) +
               f(b.front().first, b.front().second, b.back().first, b.back().second);
    return {tmp1, tmp};
}
signed main() {
    int n;
    cin >> n;
    vector <pair <int, int>> a(n);
    map <int, vector <pair <int, int>>> c;
    vector <int> b;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        b.push_back(max(a[i].first, a[i].second));
        c[max(a[i].first, a[i].second)].push_back({a[i].first, a[i].second});
    }
    b.push_back(0);
    c[0].push_back({0, 0});
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    reverse(b.begin(), b.end());
    map <int, pair <int, int>> dp;
    for (int i = 0; i < b.size(); ++i) {
        sort(c[b[i]].begin(), c[b[i]].end(), cmp);
    }
    dp[b.front()] = {f(c[b.front()].front().first, c[b.front()].front().second, c[b.front()].back().first, c[b.front()].back().second),
                     f(c[b.front()].front().first, c[b.front()].front().second, c[b.front()].back().first, c[b.front()].back().second)};
    for (int i = 1; i < b.size(); ++i) {
        pair <int, int> tmp = f1(c[b[i - 1]].front().first, c[b[i - 1]].front().second, c[b[i]]);
        tmp.first += dp[b[i - 1]].first;
        tmp.second += dp[b[i - 1]].first;
        dp[b[i]] = tmp;
        pair <int, int> tmp1 = f1(c[b[i - 1]].back().first, c[b[i - 1]].back().second, c[b[i]]);
        tmp1.first += dp[b[i - 1]].second;
        tmp1.second += dp[b[i - 1]].second;
        dp[b[i]].first = min(dp[b[i]].first, tmp1.first);
        dp[b[i]].second = min(dp[b[i]].second, tmp1.second);
    }
    cout << dp[b.back()].first;
    return 0;
}