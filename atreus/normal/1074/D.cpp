#include <bits/stdc++.h>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int mod = (int)1e9 + 7;
const int maxn = 4e5 + 4;
const ll inf = 1e18;

unordered_map <int, int> dp, p;

int get_par (int v) {
	if (!p.count(v))
		return v;
	int u = p[v];
	p[v] = get_par (p[v]);
	dp[v] ^= dp[u];
	return p[v];
}

int get (int l, int r) {
	if (get_par(l) != get_par(r))
		return -1;
	int ret = 0;
	int diff = dp[l] ^ dp[r];
	for (int i = 0; i < 30; i++)
		ret += (1 << i) & diff;
	return ret;
}

void merge (int v, int u, int x) {
	int vpar = get_par (v), upar = get_par (u);
	if (vpar == upar)
		return;
	p[upar] = vpar;
	dp[upar] = dp[v] ^ dp[u] ^ x;
}

int main (){
	int n;
	scanf ("%d", &n);
	int last = 0;
	for (int i = 0; i < n; i++) {
		int type;
		scanf ("%d", &type);
		if (type == 1) {
			int l, r, x;
			scanf ("%d%d%d", &l, &r, &x);
			l ^= last, r ^= last, x ^= last;
			if (l > r)
				swap (l, r);
			r ++;
			merge (l, r, x);
		}
		else {
			int l, r;
			scanf ("%d%d", &l, &r);
			l ^= last, r ^= last;
			if (l > r)
				swap (l, r);
			r ++;
			int x = get (l, r);
			printf ("%d\n", x);
			if (x == -1)
				last = 1;
			else
				last = x;
		}
	}
}