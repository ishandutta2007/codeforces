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

const int MN = 100005;

int p, n, a[MN], num[MN];

bool check(int x) {
    for (int i = 1; i <= n; i++) num[i] = x + i - 1; //how many she has at pos i;
    int ptr = 1, ways = 1;
    for (int i = 1; i <= n; i++) {
        while (a[ptr] <= num[i]) ptr++;
        ways *= ptr - i;
        ways %= p;
        if (!ways) break;
    }
    ways %= p;
    return ways != 0;
}

int32_t main() {
    boost();

    cin >> n >> p;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    a[n + 1] = 1LL << 60;
    //vector<int> v;

    //maybe x values form contiguous segment?

    int mn = 1;
    for (int i = 1; i <= n; i++) {
        mn = max(mn, a[i] - i + 1);
    }
    //printf("%lld\n", mn);
    int lo = mn - 1, hi = mn + MN, mid;
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo - mn + 1 << "\n";
    for (int i = mn; i <= lo; i++) cout << i << " ";
    cout << "\n";

    /*for (int x = 1; x <= 2000; x++) { //naive
        for (int i = 1; i <= n; i++) num[i] = x + i - 1; //how many she has at pos i;
        int ptr = 1, ways = 1;
        for (int i = 1; i <= n; i++) {
            while (a[ptr] <= num[i]) ptr++;
            ways *= ptr - i;
            ways %= p;
            if (!ways) break;
        }
        ways %= p;
        if (ways) v.push_back(x);
    }*/


    /*cout << v.size() << "\n";
    for (int p : v) cout << p << " ";*/

    return 0;
}