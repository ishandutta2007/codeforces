#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
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
const int mod = 1e9 + 7, abc = 864197532, N = 1000001, logN = 17;

vector <int> a;
vector <int> d, lp;

struct Seg {
    int l, r, m;
    lli val = 0;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
            pull();
        } else {
            val = a[l];
        }
    }
    void pull() {val = ch[0]->val + ch[1]->val;}
    void set(int p) {
        if (r - l == 1) val = d[val];
        else ch[p >= m]->set(p), pull();
    }
    lli query(int a, int b) {
        if (a <= l && r <= b) return val;
        lli ans = 0;
        if (a < m) ans += ch[0]->query(a, b);
        if (m < b) ans += ch[1]->query(a, b);
        return ans;
    }
};

void build() {
    d.assign(N, 1);
    lp.assign(N, 0);
    for (int i = 2; i < N; ++i) if (lp[i] == 0) {
        for (int j = i; j < N; j += i) lp[j] = i;
    }
    for (int i = 2; i < N; ++i) {
        int p = lp[i], tmp = i, cnt = 0;
        while (tmp % p == 0) tmp /= p, cnt++;
        d[i] = d[tmp] * (cnt + 1);
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    build();
    int n, q, t, l, r;
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    Seg root(0, n);
    set <int> s;
    for (int i = 0; i < n; ++i) if (a[i] > 2) s.insert(i);
    vector <int> eras;
    while (q--) {
        cin >> t >> l >> r, l--;
        if (t == 1) {
            for (auto it = s.lower_bound(l); it != s.end() && *it < r; ++it) {
                int p = *it;
                root.set(p);
                a[p] = d[a[p]];
                if (a[p] <= 2) eras.pb(p);
            }
            while (eras.size()) {
                s.erase(eras.back());
                eras.pop_back();
            }
        } else {
            cout << root.query(l, r) << '\n';
        }
    }
}