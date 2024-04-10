#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

struct Problem {
    int time, a, index;
    bool operator<(const Problem& o) const {
        return a < o.a;
    }
};

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    vector<Problem> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].a >> a[i].time;
        a[i].index = i;
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    int pos = 0;
    multiset<pair<int, int>> s1, s2;
    int64_t cost = 0;
    auto balance = [&](int k) {
        while (SZ(s1) < k && !s2.empty()) {
            pair<int, int> v = *s2.begin();
            s2.erase(s2.begin());
            s1.insert(v);
            cost += v.first;
        }
        while (SZ(s1) > k) {
            auto it = s1.end();
            --it;
            cost -= it->first;
            s2.insert(*it);
            s1.erase(it);
        }
    };
    for (int k = n; k >= 1; --k) {
        while (pos < n && a[pos].a >= k) {
            if (s2.empty() || a[pos].time < s2.begin()->first) {
                s1.insert(make_pair(a[pos].time, a[pos].index));
                cost += a[pos].time;
            } else {
                s2.insert(make_pair(a[pos].time, a[pos].index));
            }
            pos++;
        }
        balance(k);
        if (SZ(s1) == k && cost <= t) {
            cout << k << '\n';
            cout << k << '\n';
            for (const pair<int, int>& p: s1) {
                cout << p.second + 1 << ' ';
            }
            cout << '\n';
            return 0;
        }
    }
    cout << "0\n";
    cout << "0\n";
}