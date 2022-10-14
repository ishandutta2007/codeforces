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
const int mod = 998244353, abc = 864197532, N = 80002, logN = 17, K = 333;

const long long INF = 1ll << 60;

struct Seg {
    int l, r, m, mx;
    lli sum;
    Seg* ch[2];
    Seg (int _l ,int _r, vector <int> &a) : l(_l), r(_r), m(l + r >> 1) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m, a);
            ch[1] = new Seg(m, r, a);
            pull();
        } else {
            sum = mx = a[l];
        }
    }
    void pull() {
        sum = ch[0]->sum + ch[1]->sum;
        mx = max(ch[0]->mx, ch[1]->mx);
    }
    void modify(int a, int b, int x) {
        if (r - l == 1) {
            int tmp = mx % x;
            mx = sum = tmp;
        } else {
            if (a < m && ch[0]->mx >= x) ch[0]->modify(a, b, x);
            if (m < b && ch[1]->mx >= x) ch[1]->modify(a, b, x);
            pull();
        }
    }
    void set(int p, int x) {
        if (r - l == 1) mx = sum = x;
        else {
            ch[p >= m]->set(p, x);
            pull();
        }
    }
    lli query(int a, int b) {
        if (a <= l && r <= b) return sum;
        lli ans = 0;
        if (a < m) ans += ch[0]->query(a, b);
        if (m < b) ans += ch[1]->query(a, b);
        return ans;
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, t, l, r, v;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    Seg root(0, n, a);
    while (q--) {
        cin >> t >> l >> r, l--;
        if (t == 1) {
            cout << root.query(l, r) << '\n';
        } else if (t == 2) {
            cin >> v;
            root.modify(l, r, v);
        } else {
            root.set(l, r);
        }
    }
}