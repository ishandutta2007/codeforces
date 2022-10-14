#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 100008, logN = 18, K = 500, C = 100;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector <lli> a(n), b(m), pre(m - n + 1, 0);
    lli sum = 0;
    fop (i,0,n) cin >> a[i], sum += a[i] * (i & 1 ? -1 : 1);
    fop (i,0,m) {
        cin >> b[i];
        if (i < n) pre[0] += b[i] * (i & 1 ? 1 : -1);
        else {
            pre[i - n + 1] = -pre[i - n] - b[i - n] + b[i] * (n & 1 ? -1 : 1);
        }
    }
    set <lli> s;
    fop (i,0,m - n + 1) s.insert(pre[i]);
    auto ask = [&]() {
        auto it = s.lower_bound(-sum);
        if (it == s.end()) {
            return abs(sum + *(--it));
        }
        if (it == s.begin()) {
            return abs(sum + *(it));
        }
        lli a = abs(sum + *(it));
        lli b = abs(sum + *(--it));
        return min(a, b);
    };
    cout << ask() << endl;
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x, l--;
        if (l % 2 != r % 2) {
            if (l % 2 == 0) sum += x;
            else sum -= x;
        }
        cout << ask() << endl;
    }
}