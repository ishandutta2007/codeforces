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

const int MN = 200005;

int n, a, b, k, h[MN];
vector<int> extra;
int ans = 0;

int main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int l = -1, r = n;
        map<pair<int, int>, int> vis;
        pair<int, int> cur = {0, 0};
        vis[cur] = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'L') --cur.first;
            if (s[i] == 'R') ++cur.first;
            if (s[i] == 'U') ++cur.second;
            if (s[i] == 'D') --cur.second;
            if (vis.count(cur)) {
                if (i - vis[cur] + 1 < r - l + 1) {
                    l = vis[cur];
                    r = i;
                }
            }
            vis[cur] = i + 1;
        }
        if (l == -1) {
            cout << -1 << endl;
        } else {
            cout << l + 1 << " " << r + 1 << endl;
        }
    }

    return 0;
}