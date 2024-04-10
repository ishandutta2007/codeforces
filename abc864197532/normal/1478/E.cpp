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
const int mod = 998244353, abc = 864197532, N = 500087, logN = 20, K = 333;

struct Seg {
    int l, r, m, val, lz;
    Seg* ch[2];
    Seg (int _l, int _r, string &s) : l(_l), r(_r), m(l + r >> 1), val(0), lz(-1) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m, s);
            ch[1] = new Seg(m, r, s);
            pull();
        } else {
            if (s[l] == '1') val++;
        }
    }
    void pull() {val = ch[0]->val + ch[1]->val;}
    void give_tag(int t) {
        lz = t;
        val = t * (r - l);
    }
    void push() {
        if (~lz) ch[0]->give_tag(lz), ch[1]->give_tag(lz);
        lz = -1;
    }
    void modify(int a, int b, int v) {
        if (a <= l && r <= b) give_tag(v);
        else {
            push();
            if (a < m) ch[0]->modify(a, b, v);
            if (m < b) ch[1]->modify(a, b, v);
            pull();
        }
    }
    int query(int a, int b) {
        if (a <= l && r <= b) return val;
        push();
        int ans = 0;
        if (a < m) ans += ch[0]->query(a, b);
        if (m < b) ans += ch[1]->query(a, b);
        return ans;
    }
};

void solve() {
    int n, m, l, r;
    string s, t;
    cin >> n >> m >> s >> t;
    Seg root(0, n, t);
    vector <pii> Q(m);
    for (int i = 0; i < m; ++i) cin >> Q[i], Q[i].X--;
    for (int i = m - 1; ~i; --i) {
        tie(l, r) = Q[i];
        int sz = r - l, v = root.query(l, r);
        if (v < (sz + 1) / 2) {
            root.modify(l, r, 0);
        } else if (sz - v < (sz + 1) / 2) {
            root.modify(l, r, 1);
        } else {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (root.query(i, i + 1) != s[i] - '0') {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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