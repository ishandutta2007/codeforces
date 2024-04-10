#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

int n, k;
random_device rd;
mt19937 mt(rd());

bool query(int l, int r) {
    cout << l << " " << r << "\n" << flush;
    string ans;
    cin >> ans;
    if (l == r && ans[0] == 'Y') exit(0);
    if (ans == "Bad") abort();
    if (ans[0] == 'Y') return 1;
    return 0;
}

int randint(int l, int r) {
    if (l == r) return l;
    int add = rand() % (r - l + 1);
    return l + add;
}

int32_t main() {
    boost();
    srand(time(NULL));

    cin >> n >> k;
    int lo = 1, hi = n, mid;
    while (1) {
        while (hi - lo > 4 * k) {
            mid = (lo + hi) >> 1;
            if (query(lo, mid)) lo = max(1ll, lo - k), hi = min(n, mid + k);
            else lo = max(1ll, mid + 1 - k), hi = min(n, hi + k);
        }
        uniform_int_distribution<int> dist(lo, hi);
        int guess = dist(mt);
        if (query(guess, guess)) return 0;
        lo = max(1ll, lo - k);
        hi = min(n, hi + k);
    }

    return 0;
}