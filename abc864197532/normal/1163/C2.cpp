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
const int mod = 1e9 + 7, abc = 864197532, N = 1001, K = 111;

struct Pt {
    int x, y;
    bool is;
    Pt (int _x = 0, int _y = 0) : x(_x), y(_y), is(true) {}
    Pt operator - (const Pt &o) {
        return Pt(x - o.x, y - o.y);
    }
    int operator ^ (const Pt &o) {
        return x * o.y - y * o.x;
    }
    bool operator < (const Pt &o) {
        return (*this ^ o) < 0;
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <Pt> a(n);
    for (int i = 0, x, y; i < n; ++i) cin >> x >> y, a[i] = Pt(x, y);
    vector <Pt> v;
    for (int i = 0; i < n; ++i) {
        vector <Pt> tmp;
        for (int j = 0; j < n; ++j) if (i != j) {
            Pt p = a[j] - a[i];
            if (p.x < 0) p.x = -p.x, p.y = -p.y, p.is = false;
            if (p.x == 0 && p.y < 0) p.y = -p.y, p.is = false;
            tmp.pb(p);
        }
        sort(all(tmp));
        for (int i = 0, j = 0; i < n - 1; i = j) {
            int k = 0;
            while (j < n - 1 && (tmp[i] ^ tmp[j]) == 0) k |= 1 << int(tmp[j++].is);
            if (k == 3) continue;
            else v.pb(tmp[i]);
        }
    }
    sort(all(v));
    vector <Pt> tmp;
    int m = v.size();
    for (int i = 0; i < m; i += 2) tmp.pb(v[i]);
    m >>= 1;
    v = tmp;
    lli ans = 1ll * m * (m - 1) / 2;
    for (int i = 0, j = 0; i < m; i = j) {
        while (j < m && (v[i] ^ v[j]) == 0) j++;
        ans -= 1ll * (j - i) * (j - i - 1) / 2;
    }
    cout << ans << endl;
}