#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <numeric>
#include <map>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cmath>
#include <random>
#include <sstream>
#include <string>
#include <memory>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const int N = 1e6 + 10;


void solve() {
    string s;
    cin >> s;
    vector<int> a, b;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '(') {
            a.push_back(i);
        }
        else {
            b.push_back(i);
        }
    }

    reverse(b.begin(), b.end());

    vector<int> ans;
    for (size_t i = 0; i < min(a.size(), b.size()); ++i) {
        if (a[i] < b[i]) {
            ans.push_back(a[i]);
            ans.push_back(b[i]);
        }
        else {
            break;
        }
    }

    if (ans.empty()) {
        cout << 0 << endl;
    }
    else {
        sort(ans.begin(), ans.end());
        cout << 1 << endl;
        cout << ans.size() << endl;
        for (auto el : ans) {
            cout << el + 1 << " ";
        }
        cout << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    //    freopen("a.in", "r", stdin);
    solve();
}