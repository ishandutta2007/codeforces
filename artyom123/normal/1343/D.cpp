#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

const int INF = 1e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &c : a) {
            cin >> c;
        }
        multiset<int> s1;
        multiset<pair<int, int>> s2;
        multiset<pair<int, int>> sum_less;
        multiset<int> sum_more;
        for (int i = 0; i < n / 2; i++) {
            s2.insert({min(a[i], a[n - i - 1]), a[i] + a[n - i - 1]});
            sum_less.insert({a[i] + a[n - i - 1], i});
        }
        int now = 0;
        int ans = INF;
        for (int p = 2; p <= 2 * k; p++) {
            while (sum_less.size() && sum_less.begin()->fi < p) {
                int i = sum_less.begin()->se;
                sum_less.erase(sum_less.begin());
                s1.insert(max(a[i], a[n - i - 1]));
            }
            while (s1.size() && *s1.begin() + k < p) {
                now++;
                s1.erase(s1.begin());
            }
            while (s2.size() && s2.begin()->fi + 1 <= p) {
                sum_more.insert(s2.begin()->se);
                s2.erase(s2.begin());
            }
            while (sum_more.size() && *sum_more.begin() <= p) {
                sum_more.erase(sum_more.begin());
            }
            ans = min(ans, now * 2 + (int)s2.size() * 2 + (int)s1.size() + (int)sum_more.size());
        }
        cout << ans << "\n";
    }
    return 0;
}