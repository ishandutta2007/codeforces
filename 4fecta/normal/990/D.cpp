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

const int MN = 1005;

int n, a, b, ans[MN][MN];

int main() {
    boost();

    cin >> n >> a >> b;
    if ((a != 1 && b != 1) || (a == 1 && b == 1 && (n == 2 || n == 3))) return 0 * printf("NO\n");
    else printf("YES\n");
    int req = max(a, b);
    for (int i = 2; i <= n - req + 1; i++) {
        ans[i][i - 1] = ans[i - 1][i] = 1;
    }
    if (b == 1) for (int i = 1; i <= n; i++) {for(int j = 1; j <= n; j++) printf("%d", ans[i][j]); printf("\n");}
    else for (int i = 1; i <= n; i++) {for(int j = 1; j <= n; j++) printf("%d", ans[i][j] ^ 1 ^ (i == j)); printf("\n");}

    return 0;
}