#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int maxx = 1e5 + 1;

int solve1(int n, vector <int> &a) {
    vector <int> kol(n);
    set <pair <int, int>> s;
    for (int i = 0; i < n; ++i) a[i]--;
    for (int i = 0; i < n; ++i) {
        kol[a[i]]++;
    }
    int l = 0, r = n;
    vector <int> kkol;
    while (r - l > 1) {
        int m = (l + r) / 2;
        deque<int> all;
        kkol = kol;
        bool f = true;
        s.clear();
        for (int i = 0; i < n; ++i) {
            s.insert({kol[i], i});
        }
        for (int i = 0; i < m; ++i) {
            auto now = *s.rbegin();
            if (now.first == 0) {
                f = false;
                break;
            }
            else {
                kkol[now.second]--;
                s.erase(now);
                all.push_back(now.second);
            }
        }
        if (!f) {
            r = m;
            continue;
        }
        for (int i = 0; i < n - m; ++i) {
            auto now = *s.rbegin();
            if (now.first == 0) {
                f = false;
                break;
            }
            s.insert({kkol[all.front()], all.front()});
            s.erase(now);
            all.pop_front();
            all.push_back(now.second);
            kkol[now.second]--;
        }
        if (!f) r = m;
        else l = m;
    }
    return l;
}

template <typename T> T solve2() {

}

signed main() {
    srand(time(nullptr));
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            vector<int> a(n);
            for (int i = 0; i < n; ++i) cin >> a[i];
            cout << solve1(n, a) << "\n";
        }
    }
    else {
        int t;
        cin >> t;
        while (t--) {

        }
    }
}