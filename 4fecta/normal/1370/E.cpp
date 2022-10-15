#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 1000005;

int n;
string s, t;
set<int> p1, p2;

int main() {
    boost();

    cin >> n >> s >> t;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1' && t[i] == '0') p1.insert(i);
        if (s[i] == '0' && t[i] == '1') p2.insert(i);
    }
    if (p1.size() != p2.size()) return 0 * printf("-1\n");
    while (p1.size() && p2.size()) {
        ans++;
        vector<int> v;
        int t = 1, cur = *p1.begin();
        if (*p2.begin() < *p1.begin()) t = 2, cur = *p2.begin();
        v.push_back(cur);
        while (1) {
            if (t == 1) {
                auto nxt = p2.upper_bound(cur);
                if (nxt == p2.end()) break;
                cur = *nxt;
                t = 2;
                v.push_back(cur);
            } else {
                auto nxt = p1.upper_bound(cur);
                if (nxt == p1.end()) break;
                cur = *nxt;
                t = 1;
                v.push_back(cur);
            }
        }
        if (v.size() % 2) v.pop_back();
        for (int p : v) p1.erase(p), p2.erase(p);
    }
    printf("%d\n", ans);

    return 0;
}