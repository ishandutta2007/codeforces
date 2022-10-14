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
const int mod = 1e9 + 7, abc = 864197532, N = 200001, logN = 17;

struct edge {
    int u, v, w;
    bool operator < (const edge& o) {
        return w > o.w;
    }
};

int dsu[N];

void init() {
    iota(dsu, dsu + N, 0);
}

int Find(int v) {
    if (v == dsu[v]) return v;
    return dsu[v] = Find(dsu[v]);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    vector <int> a(m), b(n);
    for (int i = 0; i < m; ++i) cin >> a[i];
    lli al = 0;
    for (int i = 0; i < n; ++i) cin >> b[i];
    vector <edge> E;
    for (int i = 0, sz; i < m; ++i) {
        cin >> sz;
        for (int j = 0, tmp; j < sz; ++j) {
            cin >> tmp, --tmp;
            E.pb({i + n, tmp, a[i] + b[tmp]});
            al += a[i] + b[tmp];
        }
    }
    sort(all(E));
    init();
    for (edge &e : E) {
        if (Find(e.u) == Find(e.v)) continue;
        al -= e.w;
        dsu[Find(e.u)] = Find(e.v);
    }
    cout << al << endl;
}