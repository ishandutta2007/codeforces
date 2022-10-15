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

int n, k, cnt[26];
char a[MN];

int main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        int ans = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= k / 2 + 1; i++) {
            memset(cnt, 0, sizeof(cnt));
            int diff = k - i + 1 - i;
            for (int j = i; j <= n; j += k) {
                cnt[a[j] - 'a']++;
                if (diff) cnt[a[j + diff] - 'a']++;
            }
            int mx = 0, sum = 0;
            char b = '^';
            for (int j = 0; j < 26; j++) {
                mx = max(mx, cnt[j]), sum += cnt[j];
                if (mx == cnt[j]) b = 'a' + j;
            }
            for (int j = i; j <= n; j += k) {
                a[j] = b;
                a[j + diff] = b;
            }
            //printf("%d %d\n", mx, sum);
            ans += sum - mx;
        }
        printf("%d\n", ans);
    }

    return 0;
}