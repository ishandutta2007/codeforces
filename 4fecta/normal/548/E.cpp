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

const int MN = 500005;

vector<int> primes[MN];
int n, q, x, cnt[MN], val[MN], a[MN], ex[MN], ans;

void add(int num, int sgn) {
    for (int msk = 0; msk < 1 << primes[num].size(); msk++) { //loop thru all masks, inclusion exclusion principle.
        if (!msk) val[msk] = 1;
        else val[msk] = val[msk & (msk - 1)] * primes[num][__builtin_ctz(msk)];
        if (sgn < 0) cnt[val[msk]]--;
        if (__builtin_popcount(msk) & 1) ans -= cnt[val[msk]] * sgn;
        else ans += cnt[val[msk]] * sgn;
        if (sgn > 0) cnt[val[msk]]++;
    }
}

int32_t main() {
    boost();

    for (int i = 2; i < MN; i++) {
        if (primes[i].size()) continue;
        for (int j = i; j < MN; j += i) primes[j].push_back(i);
    }
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i], ex[i] = 1;
    while (q--) {
        cin >> x;
        add(a[x], ex[x]);
        ex[x] *= -1;
        printf("%lld\n", ans);
    }

    return 0;
}