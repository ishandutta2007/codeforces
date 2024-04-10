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
const int mod = 1e9 + 7, abc = 864197532, N = 100087, logN = 17, K = 333;

struct Seg {
    int l, r, m, mn, cnt, lz;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), mn(0), cnt(1), lz(0) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
    }
    void pull() {
        if (ch[0]->mn < ch[1]->mn) {
            tie(mn, cnt) = mp(ch[0]->mn, ch[0]->cnt);
        } else if (ch[0]->mn > ch[1]->mn) {
            tie(mn, cnt) = mp(ch[1]->mn, ch[1]->cnt);
        } else {
            tie(mn, cnt) = mp(ch[1]->mn, ch[0]->cnt + ch[1]->cnt);
        }
    }
    void give_tag(int v) {
        mn += v;
        lz += v;
    }
    void push() {
        ch[0]->give_tag(lz);
        ch[1]->give_tag(lz);
        lz = 0;
    }
    void add(int a, int b, int v) {
        if (a <= l && r <= b) {
            give_tag(v);
        } else {
            push();
            if (a < m) ch[0]->add(a, b, v);
            if (m < b) ch[1]->add(a, b, v);
            pull();
        }
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a( n + 2, n + 2), p(n + 1);
    for (int i = 0, x, y; i < n; ++i) cin >> x >> y, a[x] = y, p[y] = x;
    Seg root(0, n + 2);
    auto update = [&](int i, int v) {
        int x = a[i], y = a[i + 1];
        if (x > y) swap(x, y);
        if (x < y) root.add(x, y, v);
    };
    for (int i = 0; i < n + 1; ++i) {
        update(i, 1);
    }
    root.add(n + 1, n + 2, abc);
    root.add(0, 1, abc);
    lli ans = root.cnt;
    for (int i = 1; i <= n; ++i) {
        int j = p[i];
        update(j - 1, -1);
        update(j, -1);
        a[j] = n + 1;
        update(j - 1, 1);
        update(j, 1);
        root.add(i, i + 1, abc);
        if (root.mn == 2) ans += root.cnt;
    }
    cout << ans << endl;
}