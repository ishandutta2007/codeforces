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

int n, a[MN], ans = 0;
bool cp[MN];
vector<int> v;

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int s = 30; s >= 0; s--) {
        set<int> S;
        for (int i = 1; i <= n; i++) {
            S.insert(a[i] & (1 << s));
        }
        if (S.size() < 2) continue;
        for (int i = 1; i <= n; i++) {
            if (a[i] & (1 << s)) v.push_back(i), cp[i] = 1;
        }
        break;
    }
    for (int p : v) {
        int mx = 0;
        for (int i = p - 1; i > 0; i--) {
            mx = max(mx, a[i]);
            ans = max(ans, a[p] ^ mx);
            if (cp[i]) break;
        }
        mx = 0;
        for (int i = p + 1; i <= n; i++) {
            mx = max(mx, a[i]);
            ans = max(ans, a[p] ^ mx);
            if (cp[i]) break;
        }
    }
    printf("%d\n", ans);

    return 0;
}