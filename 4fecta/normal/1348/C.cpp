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

const int MN = 100005;
char a[MN];
string v[MN];

int main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        //for (int i = 1; i <= n; i++) printf("%c", a[i]);
        int id = 1, cols = k;
        while (id <= n) {
            for (int i = 1; i <= cols; i++) {
                v[i] += a[id++];
                if (id > n) break;
            }
            if (id > n) break;
            char c = v[1].back();
            int ncl = 1;
            for (int i = 2; i <= cols; i++) {
                if (v[i].back() == c) ncl = i;
                else break;
            }
            cols = ncl;
        }
        string ans2 = "";
        ans2 += v[k][0];
        if (v[1][0] == v[k][0]) for (int i = k + 1; i <= n; i++) ans2 += a[i];
        string ans = "";
        for (int i = 1; i <= k; i++) ans = max(ans, v[i]), v[i] = "";
        printf("%s\n", min(ans, ans2).c_str());
        //printf("%s %s\n", ans.c_str(), ans2.c_str());
    }

    return 0;
}