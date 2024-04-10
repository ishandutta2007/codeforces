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

int main() {
    boost();

    int t;
    cin >> t;
    for (; t > 0; t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int len = 0;
        int mx = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == 'A') {
                mx = max(mx, len);
                len = 0;
            } else {
                len++;
            }
        }
        printf("%d\n", mx);
    }

    return 0;
}