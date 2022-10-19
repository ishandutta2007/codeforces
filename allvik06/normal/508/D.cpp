#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <chrono>
#include <set>
#include <map>
#include <cassert>
#include <string>
#include <iomanip>
#include <array>
#include <deque>
#include <cmath>
#include <complex>
#include <queue>
#include <iomanip>

using namespace std;
vector <multiset <int>> g;
deque <int> ans;

void find_ans(int v) {
    while (!g[v].empty()) {
        int to = *g[v].begin();
        g[v].erase(g[v].begin());
        find_ans(to);
        ans.push_front(to);
    }
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    vector <string> a(n), all;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        all.push_back(a[i].substr(0, 2));
        all.push_back(a[i].substr(1, 2));
    }
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    map <string, int> d;
    int len = (int)all.size();
    for (int i = 0; i < len; ++i) d[all[i]] = i;
    g.resize(n + len);
    vector <int> cnt_in(n + len);
    for (int i = 0; i < n; ++i) {
        g[d[a[i].substr(0, 2)] + n].insert(i);
        g[i].insert(d[a[i].substr(1, 2)] + n);
        ++cnt_in[i];
        ++cnt_in[d[a[i].substr(1, 2)] + n];
    }
    int start = -1, cnt1 = 0, cnt2 = 0;
    bool ok = true;
    for (int i = 0; i < n + len; ++i) {
        if ((int)g[i].size() == cnt_in[i] + 1) {
            ++cnt1;
            start = i;
        } else if ((int)g[i].size() == cnt_in[i] - 1) {
            ++cnt2;
        } else if ((int)g[i].size() != cnt_in[i]) {
            ok = false;
        }
    }
    if (cnt1 == 0 && cnt2 == 0 && ok) {
        for (int i = 0; i < n + len; ++i) {
            if (!g[i].empty()) start = i;
        }
    } else if (cnt1 != 1 || cnt2 != 1 || !ok) {
        cout << "NO";
        return 0;
    }
    find_ans(start);
    ans.push_front(start);
    if ((int)ans.size() != 2 * n + 1) {
        cout << "NO";
        return 0;
    }
    string res = all[ans[0] - n];
    for (int i = 1; i < 2 * n + 1; ++i) {
        if (ans[i] >= n) res.push_back(all[ans[i] - n][1]);
    }
    cout << "YES\n" << res;
}

/*

 */