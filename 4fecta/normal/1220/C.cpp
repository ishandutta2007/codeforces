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

const int MN = 500005;

string s;
int n, k, ans[MN];

bool cmp(int best, int cur) {
    int d = cur - best;
    for (int i = cur; i <= n; i++) {
        int j = i - d;
        if (s[j] < s[i]) return 1;
        if (s[j] > s[i]) return 0;
    }
    return 0;
}

int main() {
    boost();

    cin >> s;
    n = s.size();
    ans[1] = 1;
    int best = 1;
    char mn = s[0];

    for (int i = 2; i <= n; i++) {
        if (mn < s[i - 1]) ans[i] = 0;
        else {
            mn = s[i - 1];
            ans[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i]) printf("Mike\n");
        else printf("Ann\n");
    }

    return 0;
}