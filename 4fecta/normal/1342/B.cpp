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
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        int c0 = 0, c1 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') c0++;
            else c1++;
        }
        if (!c0 || !c1) printf("%s\n", s.c_str());
        else {
            if (s[0] == '1') for (int i = 1; i <= n; i++) printf("10");
            else for (int i = 1; i <= n; i++) printf("01");
            printf("\n");
        }
    }

    return 0;
}