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

const int MN = 2005;

int a[MN], id[MN], b[MN], n, ans;
vector<pii> m;

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], id[a[i]] = i;
    for (int i = 1; i <= n; i++) cin >> b[i], a[id[b[i]]] = i;
    for (int i = 1; i <= n; i++) id[a[i]] = i;
    for (int i = 1; i <= n; i++) {
        int cur = id[i];
        for (int j = cur - 1; j >= i; j--) {
            if (a[j] >= cur) {
                swap(a[j], a[cur]);
                swap(id[a[j]], id[a[cur]]);
                m.push_back({j, cur});
                ans += cur - j;
                cur = j;
            }
        }
        if (cur != i) {
            swap(a[i], a[cur]);
            swap(id[a[i]], id[a[cur]]);
            m.push_back({i, cur});
            ans += cur - i;
            cur = i;
        }
    }
    cout << ans << "\n" << m.size() << "\n";
    for (pii p : m) cout << p.f << " " << p.s << "\n";

    return 0;
}