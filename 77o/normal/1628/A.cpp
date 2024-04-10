#include <bits/stdc++.h>
#include <cassert>
#include <functional>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n + 5);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int mex = 0;
    while (cnt[mex])
        ++mex;
    vector<int> b;
    vector<int> pref(n + 5);
    vector<int> upd(n + 5);
    int timer = 0;
    auto touch = [&](int pos) {
        if (timer != upd[pos]) {
            upd[pos] = timer;
            pref[pos] = 0;
        }
        return pref[pos];
    };
    for (int i = 0; i < n; i++) {
        ++timer;
        int j = i;
        int cur = 0;
        int nxtmex = mex;
        while (j == i || cur < mex) {
            assert(j < n);
            touch(a[j]);
            ++pref[a[j]];
            if (--cnt[a[j]] == 0) {
                nxtmex = min(nxtmex, a[j]);
            }
            while (touch(cur))
                ++cur;
            j++;
        }
        b.push_back(cur);
        mex = nxtmex;
        i = j - 1;
    }
    cout << b.size() << '\n';
    for (int i = 0; i < b.size(); i++)
        cout << b[i] << " \n"[i + 1 == b.size()];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}