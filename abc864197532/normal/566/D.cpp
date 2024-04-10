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
const int mod = 1e9 + 7, abc = 864197532, N = 200087, logN = 17, K = 3e6;

int dsu[N];
set <int> rt;

void init(int n) {
    for (int i = 0; i < n; ++i) {
        rt.insert(i), dsu[i] = i;
    }
}

int Find(int x) {
    if (dsu[x] == x) return x;
    return dsu[x] = Find(dsu[x]);
}

void Union(int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v) return;
    dsu[u] = v;
}

void Union2(int l, int r) {
    vector <int> cur;
    for (auto it = rt.lower_bound(l); it != rt.end() && *it < r; ++it) {
        cur.pb(*it);
    }
    for (int i = 0; i < cur.size(); ++i) {
        if (cur[i] + 1 < r) {
            Union(cur[i], cur[i] + 1), rt.erase(cur[i]);
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    init(n);
    while (q--) {
        int t, u, v;
        cin >> t >> u >> v, u--, v--;
        if (t == 1) {
            Union(u, v);
        } else if (t == 2) {
            Union2(u, v + 1);
        } else {
            cout << (Find(u) == Find(v) ? "YES\n" : "NO\n");
        }
    }
}