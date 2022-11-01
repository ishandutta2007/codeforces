#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <utility>
#include <functional>
#include <set>
#include <algorithm>
#include <ctime>
#include <vector>
#include <memory>
#include <string>
#include <optional>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
const ll MOD = 1e9 + 7;
const ll INF = 5e17 + 10;
const int M = 1e6 + 10;
const int N = 2e5 + 10;
 
struct MON {
    ll x, y, z; 
} mon[N];
 
pair<ll, ll> a[N], b[N];
 
void prep(int& n, int& m) {
	map<ll, ll> ma;
	for (int i = 0; i < n; ++i) {
		if (!ma.count(a[i].first))
			ma[a[i].first] = a[i].second;
		else ma[a[i].first] = min(ma[a[i].first], a[i].second);
	}
	n = ma.size();
	int i = 0;
	for (auto [key, val]: ma) {
		a[i++] = make_pair(key, val);
	}

	map<ll, ll> mb;
	for (int i = 0; i < m; ++i) {
		if (!mb.count(b[i].first)) {
			mb[b[i].first] = b[i].second;
		} else {
			mb[b[i].first] = min(mb[b[i].first], b[i].second);
		}
	}
	m = mb.size();
	i = 0;
	for (auto [key, value]: mb) {
		b[i++] = make_pair(key, value);
	}
}
 
ll ar[M];
ll t[4 * M];
ll add[4 * M];
 
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = ar[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = max(t[2 * v], t[2 * v + 1]);
}
 
void push(int v, int tl, int tr) {
    if (!add[v]) return;
    if (tl != tr) {
        add[2 * v] += add[v];
        add[2 * v + 1] += add[v];
    }
    t[v] += add[v];
    add[v] = 0;
}
 
void add_val(int v, int tl, int tr, int l, int r, ll delta) {
    push(v, tl, tr);
    if (tl > r || l > tr) return;
    if (l <= tl && tr <= r) {
        add[v] += delta;
        push(v, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    add_val(2 * v, tl, tm, l, r, delta);
    add_val(2 * v + 1, tm + 1, tr, l, r, delta);
    t[v] = max(t[2 * v], t[2 * v + 1]);
}
 
ll get_max(int v, int tl, int tr) {
    push(v, tl, tr);
    return t[v];
}
 
void solve() {
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    for (int j = 0; j < m; ++j) {
        cin >> b[j].first >> b[j].second;
    }
    for (int i = 0; i < p; ++i) {
        cin >> mon[i].x >> mon[i].y >> mon[i].z;
    }
    sort(mon, mon + p, [](MON& a, MON& b){return a.x < b.x;});
    prep(n, m);
 
    ll maxbb = b[m - 1].first;
 
    fill(ar, ar + M, -INF); 
    for (int i = 0; i < m; ++i) {
        ar[b[i].first] = -b[i].second;
    }
    //for (int i = 0; i < m; ++i) cout << b[i].first << " " << b[i].second << endl;
    for (int i = M - 2; i >= 0; --i) {
        ar[i] = max(ar[i], ar[i + 1]);
    }
    build(1, 0, M - 1);
 
    int ptr_m = 0;
    ll ans = -a[0].second - b[0].second;
    for (int i = 0; i < n; ++i) {
        while (ptr_m < p && mon[ptr_m].x < a[i].first) {
            if (mon[ptr_m].y < maxbb) {
                add_val(1, 0, M - 1, mon[ptr_m].y + 1, M - 1, mon[ptr_m].z);
            }
            ptr_m++;
        }
        //cout << i << " " << a[i].second << " " << get_max(1, 0, M - 1) << endl;
        ans = max(ans, -a[i].second + get_max(1, 0, M - 1));
    }
    cout << ans << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}