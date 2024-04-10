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
const int mod = 1e9 + 7, abc = 864197532, N = 200087, logN = 17, K = 333;

void add(pii &a, pii b) {
    a.X = min(a.X, b.X);
    a.Y = max(a.Y, b.Y);
}

struct Seg {
    int l, r, m, mn, mx;
    Seg* ch[2];
    Seg (int _l, int _r, vector <int> &a) : l(_l), r(_r), m(l + r >> 1), mn(0), mx(0) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m, a);
            ch[1] = new Seg(m, r, a);
            pull();
        } else {
            mn = mx = a[l];
        }
    }
    void pull() {mx = max(ch[0]->mx, ch[1]->mx), mn = min(ch[0]->mn, ch[1]->mn);}
    pii query(int a, int b) {
        if (a <= l && r <= b) return mp(mn, mx);
        pii ans = mp(1 << 30, -1 << 30);
        if (a < m) add(ans, ch[0]->query(a, b));
        if (m < b) add(ans, ch[1]->query(a, b));
        return ans;
    }
};

void solve() {
    int n, q, l, r;
    string s;
    cin >> n >> q >> s;
    vector <int> a(n + 1, 0);
    for (int i = 0; i < n; ++i) a[i + 1] = a[i] + (s[i] == '+' ? 1 : -1);
    Seg root(0, n + 1, a);
    while (q--) {
        cin >> l >> r, r++;
        if (r == n + 1) {
            pii ans = root.query(0, l);
            cout << ans.Y - ans.X + 1 << endl;
        } else {
            pii left = root.query(0, l), right = root.query(r, n + 1);
            right.X -= a[r - 1] - a[l - 1];
            right.Y -= a[r - 1] - a[l - 1];
            cout << max(left.Y, right.Y) - min(left.X, right.X) + 1 << endl;
        }
    }
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