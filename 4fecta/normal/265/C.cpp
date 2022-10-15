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
int ans[1000005];
int main() {
    boost();

    string s;
    cin >> s;
    int lo = 1, hi = s.length();

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'l') ans[hi] = i + 1, hi--;
        else ans[lo] = i + 1, lo++;
    }
    for (int i = 1; i <= s.length(); i++) printf("%d\n", ans[i]);

    return 0;
}