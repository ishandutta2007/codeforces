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
const int mod = 998244353, x = 864197532, N = 1001, logN = 18, K = 500, C = 100;

struct Seg {
    int l, r, m, val, lz;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), lz(0) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
            pull();
        } else {
            val = l + 1;
        }
    }
    void pull() {val = max(ch[0]->val, ch[1]->val);}
    void push() {
        if (r - l > 1 && lz) {
            ch[0]->lz += lz;
            ch[0]->val += lz;
            ch[1]->lz += lz;
            ch[1]->val += lz;
        }
        lz = 0;
    }
    void add(int a, int b, int v) {
        if (a >= b) return;
        if (a <= l && r <= b) val += v, lz += v;
        else {
            push();
            if (a < m) ch[0]->add(a, b, v);
            if (m < b) ch[1]->add(a, b, v);
            pull();
        }
    }
    int query(int a, int b) {
        if (a <= l && r <= b) return val;
        int ans = 0;
        push();
        if (a < m) ans = max(ans, ch[0]->query(a, b));
        if (m < b) ans = max(ans, ch[1]->query(a, b));
        return ans;
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, k, x, y;
    cin >> n >> k >> q, k--;
    Seg root(0, n * 2 + 1);
    multiset <int> s;
    s.insert(n);
    set <pii> pt;
    while (q--) {
        cin >> x >> y, x--, y--;
        int r = y + abs(x - k);
        if (pt.count({x, y})) {
            pt.erase({x, y});
            root.add(0, r, -1);
            if (r >= n) s.erase(s.lower_bound(r + 1));
        } else {
            pt.insert({x, y});
            root.add(0, r, 1);
            if (r >= n) s.insert(r + 1);
        }
        cout << root.query(0, *(--s.end())) - n << '\n';
    }
}