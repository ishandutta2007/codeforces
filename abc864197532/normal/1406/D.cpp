#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pdd pair<ld,ld>
typedef long double ld;
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 50087, logN = 17, K = 222;

vector <int> lastPrime (int n) {
    vector <int> ans(n + 1, 0), prime;
    for (int i = 2; i <= n; ++i) {
        if (!ans[i]) {
            prime.push_back(i);
            ans[i] = i;
        }
        for (int j = 0; 1ll * prime[j] * i <= n; j++) {
            ans[prime[j] * i] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
    return ans;
}

vector <int> make_mobius (int n) {
    vector <int> LPrime = lastPrime(n), mobius(n + 1);
    mobius[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (LPrime[i] == LPrime[i / LPrime[i]]) mobius[i] = 0;
        else mobius[i] = mobius[i / LPrime[i]] * -1;
    }
    return mobius;
}

vector <int> Prime (int n) { // Generate a prime table
    vector <int> LPrime = lastPrime(n), ans;
    for (int i = 2; i <= n; ++i) {
        if (LPrime[i] == i) ans.push_back(i);
    }
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, l, r, x, q;
    cin >> n;
    vector <lli> a(n + 1, 0), d(n);
    fop (i,0,n) cin >> a[i + 1];
    fop (i,1,n + 1) d[i - 1] = a[i] - a[i - 1];
    lli cur_ans = 0;
    fop (i,1,n) cur_ans += max(d[i], 0ll);
    cout << (cur_ans + d[0] + (cur_ans + d[0] > 0)) / 2 << endl;
    cin >> q;
    while (q--) {
        cin >> l >> r >> x; l--;
        if (l) {
            cur_ans -= max(d[l], 0ll);
            d[l] += x;
            cur_ans += max(d[l], 0ll);
        } else {
            d[l] += x;
        }
        if (r < n) {
            cur_ans -= max(d[r], 0ll);
            d[r] -= x;
            cur_ans += max(d[r], 0ll);
        }
        cout << (cur_ans + d[0] + (cur_ans + d[0] > 0)) / 2 << endl;
    }
}