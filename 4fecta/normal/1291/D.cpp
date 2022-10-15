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

string s;
int n, q, l, r, psa[MN][26];
char a[MN];

int main() {
    boost();

    cin >> s >> q;
    n = s.length();
    for (int i = 1; i <= n; i++) a[i] = s[i - 1];
    for (int i = 1; i <= n; i++) {
        psa[i][a[i] - 'a']++;
        for (int j = 0; j < 26; j++) psa[i][j] += psa[i - 1][j];
    }
    while (q--) {
        cin >> l >> r;
        if (a[l] != a[r] || l == r) {
            printf("Yes\n"); continue;
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (psa[r][i] - psa[l - 1][i] > 0) cnt++;
        }
        if (cnt > 2) {printf("Yes\n"); continue;}
        printf("No\n");
    }

    return 0;
}