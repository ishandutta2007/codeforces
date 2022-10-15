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

int n, r = 1, c = 1;
string ans, ans1, in;

int dist(int r1, int c1, int r2, int c2) {
    return abs(r1 - r2) + abs(c1 - c2);
}

int main() {
    boost();

    cin >> n;
    while (dist(r, c, n, n) > n - 1) {
        if (c + 1 <= n) {
            if (dist(r, c + 1, n, n) >= n - 1) printf("? %d %d %d %d\n", r, c + 1, n, n);
            fflush(stdout);
            cin >> in;
            assert(in != "BAD");
            if (in == "YES") c++, ans += 'R';
            else r++, ans += 'D';
        } else {
            r++, ans += 'D';
        }
    }
    r = c = n;
    while (dist(1, 1, r, c) > n - 1) {
        if (r - 1 > 0) {
            if (dist(1, 1, r - 1, c) >= n - 1) printf("? %d %d %d %d\n", 1, 1, r - 1, c);
            fflush(stdout);
            cin >> in;
            assert(in != "BAD");
            if (in == "YES") r--, ans1 = 'D' + ans1;
            else c--, ans1 = 'R' + ans1;
        } else {
            c--, ans1 = 'R' + ans1;
        }
    }
    printf("! %s%s\n", ans.c_str(), ans1.c_str());
    fflush(stdout);

    return 0;
}