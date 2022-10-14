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
const int mod = 998244353, abc = 864197532, N = 200005, K = 111;

struct Seg {
    int l, r, m;
    lli mn, lz;
    Seg* ch[2];
    Seg (int _l, int _r, vector <lli> &a) : l(_l), r(_r), m(l + r >> 1), lz(0) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m, a);
            ch[1] = new Seg(m, r, a);
            pull();
        } else {
            mn = a[l];
        }
    }
    void pull() {mn = min(ch[0]->mn, ch[1]->mn);}
    void give(lli t) {
        mn += t;
        lz += t;
    }
    void push() {
        ch[0]->give(lz), ch[1]->give(lz);
        lz = 0;
    }
    void add(int a, int b, lli v) {
        if (a <= l && r <= b) give(v);
        else {
            push();
            if (a < m) ch[0]->add(a, b, v);
            if (m < b) ch[1]->add(a, b, v);
            pull();
        }
    }
    int query() {
        if (r - l == 1) return l;
        push();
        return ch[ch[1]->mn == 0]->query();
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, cur = 1;
    cin >> n;
    vector <lli> s(n);
    vector <int> p(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    Seg root(0, n, s);
    while (cur <= n) {
        int i = root.query();
        p[i] = cur++;
        root.add(i, n, -p[i]);
        root.add(i, i + 1, 1ll << 60);
    }
    printv(p);
}