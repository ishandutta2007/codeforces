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
const int mod = 1e9 + 7, abc = 864197532, N = 200001, K = 111, logN = 18;

int ST[N][logN];

int query(int l, int r) {
    int g = __lg(r - l);
    return __gcd(ST[l][g], ST[r - (1 << g)][g]);
}

void solve() {
    int n, p;
    cin >> n >> p;
    vector <int> a(n), l(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ST[i][0] = a[i];
    }
    for (int j = 1; j < logN; ++j) {
        for (int i = 0; i + (1 << j) <= n; ++i) {
            ST[i][j] = __gcd(ST[i][j - 1], ST[i + (1 << j - 1)][j - 1]);
        }
    }
    for (int i = 0; i < n; ++i) {
        int tl = -1, tr = i + 1;
        while (tr - tl > 1) {
            int m = tl + tr >> 1;
            if (query(m, i + 1) % a[i] == 0) tr = m;
            else tl = m;
        }
        l[i] = tr;
        tl = i, tr = n + 1;
        while (tr - tl > 1) {
            int m = tl + tr >> 1;
            if (query(i, m) % a[i] == 0) tl = m;
            else tr = m;
        }
        r[i] = tl;
    }
    vector <int> ord(n), dsu(n + 1);
    iota(all(ord), 0);
    iota(all(dsu), 0);
    function<int(int)> Find = [&](int x) {
        if (dsu[x] == x) return x;
        return dsu[x] = Find(dsu[x]);
    };
    sort(all(ord), [&](int i, int j) {
        return a[i] < a[j];
    });
    lli ans = 0;
    for (int i : ord) if (a[i] < p) {
        int tl = l[i], tr = r[i];
        vector <int> rt;
        for (int j = tl; j < tr; ++j) rt.pb(Find(j)), j = Find(j);
        if (rt.empty()) continue;
        ans += 1ll * a[i] * (rt.size() - 1);
        for (int j = 1; j < rt.size(); ++j) dsu[Find(rt[j - 1])] = Find(rt[j]);
    }
    for (int i = 0; i < n; ++i) if (dsu[i] == i) ans += p;
    cout << ans - p << endl;
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