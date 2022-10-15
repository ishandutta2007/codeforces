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

const ll MN = 200005, MOD = 998244353;

int n; ll cnt[MN];

ll fpow(ll b, ll p) {
    if (p == 0) return 1;
    ll ret = fpow(b, p / 2);
    if (p & 1) return ret * ret % MOD * b % MOD;
    return ret * ret % MOD;
}

int main() {
    boost();

    cin >> n;
//    for (int i = 0; i < pow(10, n); i++) {
//        string s = to_string(i);
//        while (s.length() < n) s = '0' + s;
//        int len = 0; char c = 'l';
//        for (int j = 0; j < n; j++) {
//            if (s[j] != c) cnt[len]++, len = 1, c = s[j];
//            else len++;
//        }
//        cnt[len]++;
//    }
//    for (int i = 1; i <= n; i++) printf("%d %lld\n", cnt[i], i * fpow(10, i));
    ll sum = 10;
    cnt[1] = 10;
    for (ll i = 2; i <= n; i++) {
        ll digs = i * fpow(10, i) % MOD;
        ll pdigs = (i - 1) * fpow(10, i - 1) % MOD;
        cnt[i] = digs - pdigs - sum;
        cnt[i] %= MOD;
        cnt[i] += MOD;
        cnt[i] %= MOD;
        sum += cnt[i];
        sum %= MOD;
    }
    for (int i = n; i > 0; i--) printf("%lld ", cnt[i] % MOD);

    return 0;
}