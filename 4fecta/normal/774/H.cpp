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

int n, a[MN], num = 0;
string ans;

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i > 0; i--) {
        if (!a[i]) continue;
        for (int j = 0; j < a[i]; j++) {
            for (int k = 0; k < i; k++) {
                ans += num % 2 ? 'a' : 'b';
            }
            num++;
        }
        for (int j = i - 1; j > 0; j--) {
            a[j] -= (i - j + 1) * a[i];
        }
    }
    printf("%s\n", ans.c_str());

    return 0;
}