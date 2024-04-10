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

int n, a[MN], ans, mx, mp[MN];

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i], a[i]++;
        if (a[i] == i) ans++;
    }
    for (int i = 1; i <= n; i++) {
        if (mp[i] == a[i]) mx = max(mx, 2);
        mp[a[i]] = i;
        if (a[i] != i) mx = max(mx, 1);
    }
    cout << ans + mx;

    return 0;
}