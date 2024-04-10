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
const int mod = 1e9 + 7, x = 864197532, N = 200000, logN = 18, K = 500, C = 100, M = 1e9;

struct Seg {
    int l, r, m;
    lli val1 = 0, val2 = 0;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
            pull();
        }
    }
    Seg (Seg *i) : l(i->l), r(i->r), m(i->m), ch{i->ch[0], i->ch[1]}, val1(i->val1), val2(i->val2) {}
    void pull() {
        val1 = ch[0]->val1 + ch[1]->val1;
        val2 = ch[0]->val2 + ch[1]->val2;
    }
    Seg* modify(int p, lli c, lli d) {
        Seg *ans = new Seg(this);
        if (r - l == 1) {
            ans->val1 += c;
            ans->val2 += d;
            return ans;
        }
        if (p < m) ans->ch[0] = ch[0]->modify(p, c, d);
        else ans->ch[1] = ch[1]->modify(p, c, d);
        ans->pull();
        return ans;
    }
    pll query(int a, int b) {
        if (a <= l && r <= b) return mp(val1, val2);
        pll ans = {0, 0};
        if (a < m) {
            pll tmp = ch[0]->query(a, b);
            ans.X += tmp.X; ans.Y += tmp.Y;
        }
        if (m < b) {
            pll tmp = ch[1]->query(a, b);
            ans.X += tmp.X; ans.Y += tmp.Y;
        }
        return ans;
    }
};

vector <Seg*> rts;

lli query(int l, int r, int x) {
    if (x > 200000) x = 200001;
    pll ans = rts[r]->query(0, x + 1), tmp = rts[l]->query(0, x + 1);
    return (ans.X - tmp.X) * x + (ans.Y - tmp.Y);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, x1, x2, y1, a, b, y2;
    cin >> n;
    Seg *rt = new Seg(0, N + 2);
    rts.pb(rt);
    fop (i,0,n) {
        cin >> x1 >> x2 >> y1 >> a >> b >> y2;
        Seg *cur = new Seg(rts.back());
        cur = cur->modify(0, 0, y1);
        cur = cur->modify(x1 + 1, a, b - y1);
        cur = cur->modify(x2 + 1, -a, y2 - b);
        rts.pb(cur);
    }
    lli last = 0;
    cin >> q;
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        x = (last + x) % M;
        last = query(l - 1, r, x);
        cout << last << '\n';
    }
}