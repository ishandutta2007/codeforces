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

int n, a[MN], ans[MN];
vector<int> inc, decc;

int main() {
    boost();

    cin >> n;
    inc.push_back(-0x3f3f3f3f), decc.push_back(0x3f3f3f3f);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        if (a[i] > inc.back() && a[i] < decc.back()) {
            if (a[i + 1] > a[i]) inc.push_back(a[i]);
            else decc.push_back(a[i]), ans[i] = 1;
        } else if (a[i] > inc.back()) inc.push_back(a[i]);
        else if (a[i] < decc.back()) decc.push_back(a[i]), ans[i] = 1;
        else ans[0] = 1;
    }
    if (ans[0]) printf("NO\n");
    else {printf("YES\n"); for (int i = 1; i <= n; i++) printf("%d ", ans[i]);}

    return 0;
}