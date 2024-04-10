//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <random>
#include <iomanip>
#include <chrono>

using namespace std;

vector <char> get_left_part(int n) {
    if (n == 0) return {};
    if (n == 1) {
        cout << "? 1 1" << endl;
        char c;
        cin >> c;
        return {c};
    }
    multiset<vector <int>> s;
    cout << "? " << 2 << " " << n << endl;
    for (int _ = 0; _ < n * (n - 1) / 2; ++_) {
        vector <int> flex(26);
        string cur;
        cin >> cur;
        for (char c : cur) ++flex[c - 'a'];
        s.insert(flex);
    }
    vector <vector <int>> kek(n + 1, vector <int> (26));
    cout << "? " << 1 << " " << n << endl;
    for (int _ = 0; _ < n * (n + 1) / 2; ++_) {
        vector <int> flex(26);
        string cur;
        cin >> cur;
        for (char c : cur) ++flex[c - 'a'];
        if (s.count(flex)) s.erase(s.find(flex));
        else kek[(int)cur.size()] = flex;
    }
    vector <char> res;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (kek[i][j] - kek[i - 1][j]) res.push_back('a' + j);
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    auto lef = get_left_part(n / 2);
    cout << "? 1 " << n << endl;
    vector <vector <int>> a(n + 1, vector <int> (26));
    for (int i = 0; i < n * (n + 1) / 2; ++i) {
        string cur;
        cin >> cur;
        for (char c : cur) ++a[(int)cur.size()][c - 'a'];
    }
    vector <pair <char, char>> flex;
    for (int i = 0; i < n / 2; ++i) {
        int x = n - i - 1;
        vector <int> now = a[n];
        for (int j = 0; j < 26; ++j) {
            now[j] += a[x + 1][j] - a[x][j];
        }
        for (auto j : flex) {
            now[j.first - 'a']--;
            now[j.second - 'a']--;
        }
        char f = 'a' - 1;
        char s = 'a' - 1;
        for (int j = 0; j < 26; ++j) {
            if (now[j]) {
                if (f == 'a' - 1) f = 'a' + j;
                else s = 'a' + j;
                now[j]--;
            }
            if (now[j]) {
                if (f == 'a' - 1) f = 'a' + j;
                else s = 'a' + j;
                now[j]--;
            }
        }
        flex.emplace_back(f, s);
    }
    vector <char> ans(n);
    for (int i = 0; i < n / 2; ++i) {
        if (lef[i] == flex[i].first) {
            ans[i] = flex[i].first;
            ans[n - i - 1] = flex[i].second;
        } else {
            ans[i] = flex[i].second;
            ans[n - i - 1] = flex[i].first;
        }
    }
    if (n & 1) {
        for (int i = 0; i < n / 2; ++i) {
            --a[n][ans[i] - 'a'];
            --a[n][ans[n - i - 1] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (a[n][i]) ans[n / 2] = 'a' + i;
        }
    }
    cout << "! ";
    for (char c : ans) cout << c;
    cout << endl;
}

signed main() {
    if (0) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
        //  cin >> t;
        while (t--) {
            solve();
        }
    }
}

/*
=
 */