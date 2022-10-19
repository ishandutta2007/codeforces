#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <cmath>
#include <cassert>
#include <array>

using namespace std;
#define int long long
string result;
vector <int> s;

void calc(int l, int r, vector <vector <int>>& b, multiset <int>& act) {
    if (l == r) {
        for (int i : b[l]) {
            int v = ceil((double)(s[l] - i) / ((int)b[l].size() - 1));
            if (*act.rbegin() >= v) {
                result += "1";
            } else {
                result += "0";
            }
        }
        return;
    }
    int m = (l + r) / 2;
    vector <int> tmp;
    bool ok = true;
    for (int i = m + 1; i <= r; ++i) {
        int v = ceil((double)s[i] / (int)b[i].size());
        auto it = act.lower_bound(v);
        if (it == act.end()) {
            ok = false;
            break;
        } else {
            tmp.push_back(*it);
            act.erase(it);
        }
    }
    if (ok) {
        calc(l, m, b, act);
    } else {
        for (int i = l; i <= m; ++i) {
            for (int j = 0; j < (int)b[i].size(); ++j) {
                result += "0";
            }
        }
    }
    for (int i : tmp) act.insert(i);
    ok = true;
    tmp.clear();
    for (int i = l; i <= m; ++i) {
        int v = ceil((double)s[i] / (int)b[i].size());
        auto it = act.lower_bound(v);
        if (it == act.end()) {
            ok = false;
            break;
        } else {
            tmp.push_back(*it);
            act.erase(it);
        }
    }
    if (ok) {
        calc(m + 1, r, b, act);
    } else {
        for (int i = m + 1; i <= r; ++i) {
            for (int j = 0; j < (int)b[i].size(); ++j) {
                result += "0";
            }
        }
    }
    for (int i : tmp) act.insert(i);
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        s.assign(m, 0);
        multiset <int> act;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            act.insert(x);
        }
        vector <vector <int>> b(m);
        for (int i = 0; i < m; ++i) {
            int k;
            cin >> k;
            b[i].resize(k);
            for (int j = 0; j < k; ++j) {
                cin >> b[i][j];
                s[i] += b[i][j];
            }
        }
        result = "";
        calc(0, m - 1, b, act);
        cout << result << "\n";
    }
}

/*

 */