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

int psa[MN][5];
string s;

bool check(int len) {
    for (int i = len; i <= s.size(); i++) {
        int lft = i - len + 1;
        if (psa[i][1] - psa[lft - 1][1] > 0 && psa[i][2] - psa[lft - 1][2] > 0 && psa[i][3] - psa[lft - 1][3] > 0) return true;
    }
    return false;
}

int main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        for (int i = 1; i <= s.size(); i++) {
            psa[i][1] = psa[i][2] = psa[i][3] = 0;
            psa[i][s[i - 1] - '0']++;
            psa[i][1] += psa[i - 1][1];
            psa[i][2] += psa[i - 1][2];
            psa[i][3] += psa[i - 1][3];
        }
        int lo = 3, hi = s.size(), mid;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (check(mid)) hi = mid;
            else lo = mid + 1;
        }
        if (psa[s.size()][1] == 0 || psa[s.size()][2] == 0 || psa[s.size()][3] == 0) printf("0\n");
        else printf("%d\n", lo);
    }

    return 0;
}