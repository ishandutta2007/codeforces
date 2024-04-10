#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 1e8 + 7, abc = 864197532, N = 200087, K = 111;

struct Seg {
    int l, r, m, val;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), val(0) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
    }
    void pull() {
        val = ch[0]->val + ch[1]->val;
    }
    void add(int p, int v) {
        if (r - l == 1) val += v;
        else ch[p >= m]->add(p, v), pull();
    }
    int query(int a, int b) {
        if (a >= b) return 0;
        if (a <= l && r <= b) return val;
        int ans = 0;
        if (a < m) ans += ch[0]->query(a, b);
        if (m < b) ans += ch[1]->query(a, b);
        return ans;
    }
} root(-5000, 5001);

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    lli ans = 0;
    vector <pair<int, pii>> row, col;
    for (int i = 0, x1, y1, x2, y2; i < n; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            if (y1 > y2) swap(y1, y2);
            col.pb(mp(x1, mp(y1, y2 + 1)));
        } else {
            if (x1 > x2) swap(x1, x2);
            row.pb(mp(y1, mp(x1, x2 + 1)));
        }
    }
    sort(all(col));
    for (int i = 0; i < col.size(); ++i) {
        int j = 0;
        vector <pair<int, pii>> v;
        for (auto A : row) {
            if (A.Y.X <= col[i].X) {
                v.pb(mp(A.Y.X, mp(1, A.X)));
                v.pb(mp(A.Y.Y, mp(-1, A.X)));
            }
        }
        sort(all(v));
        for (int k = i + 1; k < col.size(); ++k) {
            for (; j < v.size() && v[j].X <= col[k].X; ++j) {
                root.add(v[j].Y.Y, v[j].Y.X);
            }
            int cnt = root.query(max(col[i].Y.X, col[k].Y.X), min(col[i].Y.Y, col[k].Y.Y));
            ans += cnt * (cnt - 1) / 2;
        }
        for (; j < v.size(); ++j) {
            root.add(v[j].Y.Y, v[j].Y.X);
        }
    }
    cout << ans << endl;
}