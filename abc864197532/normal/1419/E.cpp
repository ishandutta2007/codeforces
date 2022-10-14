#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 1000005, logN = 17, K = 90002;

void solve() {
    int n;
    cin >> n;
    vector <pii> factor;
    int tmp = n;
    for (int i = 2; i * i <= tmp; ++i) if (tmp % i == 0) {
        factor.eb(i, 0);
        while (tmp % i == 0) factor.back().Y++, tmp /= i;
    }
    if (tmp > 1) factor.eb(tmp, 1);
    sort(all(factor), [](pii a, pii b) {return a.Y > b.Y;});
    set <int> s;
    for (int i = 2; i * i <= n; ++i) if (n % i == 0) {
        s.insert(i);
        s.insert(n / i);
    }
    s.insert(n);
    int m = factor.size();
    if (m == 1) {
        printv(s);
        cout << 0 << endl;
        return;
    }
    int v[m];
    if (m == 2) {
        if (s.size() == 3) {
            printv(s);
            cout << 1 << endl;
            return;
        }
        v[0] = factor[0].X * factor[1].X;
        v[1] = factor[0].X * factor[0].X * factor[1].X;
    } else {
        fop (i,0,m) {
            int j = (i + 1) % m;
            v[i] = factor[i].X * factor[j].X;
        }
    }
    fop (i,0,m) {
        s.erase(factor[i].X);
        s.erase(v[i]);
    }
    fop (i,0,m) {
        int now = factor[i].X;
        cout << now << ' ';
        vector <int> add;
        for (int i : s) if (i % now == 0 && s.count(i)) {
            add.pb(i);
            cout << i << ' ';
        }
        for (int i : add) s.erase(i);
        cout << v[i] << ' ';
    }
    cout << endl << 0 << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}