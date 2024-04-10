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
const int mod = 1e9 + 7, x = 864197532, N = 400008, logN = 18, K = 500, C = 100;

struct Dsu {
    int dsu[N << 1], size[N << 1], n, cc;
    Dsu () {
        for (int i = 0; i < N << 1; ++i) dsu[i] = i, size[i] = 1;
    }
    int Find(int v) {
        if (dsu[v] == v) return v;
        return dsu[v] = Find(dsu[v]);
    }
    bool Union(int v, int u) {
        int x = Find(v), y = Find(u);
        if (x == y) return false;
        if (size[x] > size[y]) swap(x, y);
        dsu[x] = y;
        size[y] += size[x];
        size[x] = 0;
        cc--;
        return true;
    }
    bool same(int u, int v) {
        return Find(u) == Find(v);
    }
} D[30];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    map <int, int> m1;
    int _id = 0, last = 0;
    while (q--) {
        int t, l, r, x;
        cin >> t >> l >> r;
        l ^= last;
        r ^= last;
        if (l > r) swap(l, r);
        l--;
        if (t == 1) {
            cin >> x;
            x ^= last;
            if (!m1.count(r)) m1[r] = _id++;
            if (!m1.count(l)) m1[l] = _id++;
            int a = m1[l], b = m1[r];
            if (D[0].same(a, b) || D[0].same(a, b + N)) continue;
            for (int i = 0; i < 30; ++i) {
                if (x & (1 << i)) {
                    D[i].Union(a + N, b);
                    D[i].Union(a, b + N);
                } else {
                    D[i].Union(a, b);
                    D[i].Union(a + N, b + N);
                }
            }
        } else {
            if (!m1.count(r) || !m1.count(l)) {
                cout << -1 << '\n';
                last = 1;
            } else {
                int a = m1[l], b = m1[r];
                int ans = 0;
                for (int i = 0; i < 30; ++i) {
                    if (D[i].same(a, b + N)) {
                        ans |= 1 << i;
                    } else if (D[i].same(a, b)) {

                    } else {
                        ans = -1;
                        break;
                    }
                }
                cout << ans << '\n';
                last = ans;
                if (ans == -1) last = 1;
            }
        }
    }
}