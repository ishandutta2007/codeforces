#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    set<int> s;
    multiset<int> seg;
    vector<int> p(n);
    for (auto &c : p) {
        cin >> c;
        s.insert(c);
    }
    sort(all(p));
    for (int i = 1; i < n; i++) {
        seg.insert(p[i] - p[i - 1]);
    }
    cout << *s.rbegin() - *s.begin() - (seg.size() ? *seg.rbegin() : 0) << "\n";
    while (q--) {
        int t, x;
        cin >> t >> x;
        if (t == 0) { /// del
            auto it1 = s.lower_bound(x), it2 = s.upper_bound(x);
            int left = -INF, right = INF;
            if (it1 != s.begin()) {
                it1--;
                left = *it1;
            }
            if (it2 != s.end()) {
                right = *it2;
            }
            s.erase(x);
            if (left != -INF && right != INF) {
                seg.erase(seg.find(right - x));
                seg.erase(seg.find(x - left));
                seg.insert(right - left);
            } else if (left == -INF && right != INF) {
                seg.erase(seg.find(right - x));
            } else if (left != -INF && right == INF) {
                seg.erase(seg.find(x - left));
            }
        } else { /// add
            auto it1 = s.lower_bound(x), it2 = s.upper_bound(x);
            int left = -INF, right = INF;
            if (it1 != s.begin()) {
                it1--;
                left = *it1;
            }
            if (it2 != s.end()) {
                right = *it2;
            }
            s.insert(x);
            if (left != -INF && right != INF) {
                seg.erase(seg.find(right - left));
                seg.insert(right - x);
                seg.insert(x - left);
            } else if (left == -INF && right != INF) {
                seg.insert(right - x);
            } else if (left != -INF && right == INF) {
                seg.insert(x - left);
            }
        }
        if (s.size() == 0) cout << 0 << "\n";
        else cout << *s.rbegin() - *s.begin() - (seg.size() ? *seg.rbegin() : 0) << "\n";
    }
    return 0;
}