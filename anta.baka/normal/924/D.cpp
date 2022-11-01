#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const int maxn = 1e5;

struct fenwick {
	int n; vector<int> t;
	fenwick(int n) : n(n), t(n, 0) {}
	void upd(int v, int x) {
		for(int i = v; i < n; i |= i + 1) t[i] += x;
	}
	int get(int v) {
		int ret = 0;
		for(int i = v; i >= 0; i = (i & (i + 1)) - 1) ret += t[i];
		return ret;
	}
};

int n, w;
ll ans;

struct plane {
	int x, v;
	pair<int, int> n1, n2; // norm(t(-w)), norm(t(w))
	bool operator < (const plane &he) const {
		return ll(n1.first) * he.n1.second < ll(he.n1.first) * n1.second;
	}
} a[maxn];

pair<int, int> norm(int a, int b) {
	if(a < 0) a = -a;
	if(b < 0) b = -b;
	int g = __gcd(a, b);
	a /= g; b /= g;
	return {a, b};
}

auto cmp = [](pair<int, int> a, pair<int, int> b){ return ll(a.first) * b.second < ll(b.first) * a.second; };
map<pair<int, int>, int, decltype(cmp)> re(cmp);

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> w;
	for(int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].v;
		a[i].n1 = norm(a[i].x, a[i].v - w);
		a[i].n2 = norm(a[i].x, a[i].v + w);
		re[a[i].n2];
	}
	sort(a, a + n);
	int dif = 0;
	for(auto it = re.begin(); it != re.end(); it++) it->second = dif++;
	fenwick t(dif);
	for(int i = n - 1; i >= 0; i--) {
		int j = i;
		while(j > 0 && a[j - 1].n1 == a[i].n1) j--;
		ans += ll(i - j + 1) * (i - j) / 2;
		for(int k = i; k >= j; k--) ans += t.get(re[a[k].n2]);
		for(int k = i; k >= j; k--) t.upd(re[a[k].n2], 1);
		i = j;
	}
	cout << ans;
}