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
const int mod = 1e9 + 7, x = 864197532, N = 100008, logN = 18, K = 500, C = 100;

struct ans {
    lli v;
    int x, y;
    ans (lli _v, int _x, int _y) {
        v = _v, x = _x, y = _y;
    }
    bool operator > (const ans& o) {
        if (v != o.v) return v > o.v;
        return false;
    }
};

struct E {
    int x, y, v;
    bool operator < (const E o) {
        if (x != o.x) return x < o.x;
        return false;
    }
};

vector <int> dis;


struct Seg {
    int l, r, m;
    long long lz;
    pair <long long, int> val;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
            pull();
        }
        val = mp(-dis[l], l);
        lz = 0;
    }
    void pull() {
        val = max(ch[0]->val, ch[1]->val);
    }
    void push() {
        if (r - l > 1 && lz) {
            ch[0]->lz += lz;
            ch[0]->val.X += lz;
            ch[1]->lz += lz;
            ch[1]->val.X += lz;
        }
        lz = 0;
    }
    void add(int a, int b, long long v) {
        if (a <= l && r <= b) val.X += v, lz += v;
        else {
            push();
            if (a < m) ch[0]->add(a, b, v);
            if (m < b) ch[1]->add(a, b, v);
            pull();
        }
    }
    pair <long long, int> query(int a, int b) {
        if (a <= l && r <= b) return val;
        push();
        pair <long long, int> ans = mp(-1ll << 60, -1);
        if (a < m) ans = max(ans, ch[0]->query(a, b));
        if (m < b) ans = max(ans, ch[1]->query(a, b));
        return ans;
    }
};

int f(int x) {
    return lower_bound(all(dis), x) - dis.begin();
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, y, v;
    cin >> n;
    lli al = 0;
    vector <E> event;
    fop (i,0,n) {
        cin >> x >> y >> v;
        if (x > y) swap(x, y);
        al += v;
        dis.pb(x);
        dis.pb(y);
        event.pb({x, y, v});
    }
    sort(all(event));
    sort(all(dis));
    dis.resize(unique(all(dis)) - dis.begin());
    ans best = ans(0, 1000000001, 1000000001);
    Seg root(0, dis.size());
    for (E e : event) {
        root.add(f(e.y), dis.size(), e.v);
    }
    for (int i = 0, j = 0; i < dis.size(); ++i) {
        for (; j < n && event[j].x < dis[i]; j++) {
            root.add(f(event[j].y), dis.size(), -event[j].v);
        }
        pair <long long, int> q = root.query(i, dis.size());
        ans re = ans(q.X + dis[i], dis[i], dis[q.Y]);
        if (re > best) best = re;
    }
    cout << best.v << endl << best.x << ' ' << best.x << ' ' << best.y << ' ' << best.y << endl;
}