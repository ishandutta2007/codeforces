#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 3e5 + 10;
const int block = 320;

pair <pii, int> p[maxn];
ll parx[maxn], pary[maxn], x[maxn], y[maxn];
ll ans[maxn];

bool compare (pair <pii, int> fi, pair <pii, int> se) {
	return (fi.F.F - fi.F.S) < (se.F.F - se.F.S);
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		p[i] = {{x[i], y[i]}, i};
	}
	sort (p + 1, p + n + 1, compare);
	for (int i = 1; i <= n; i++)
		parx[i] = parx[i - 1] + p[i].F.F;
	for (int i = n; i >= 1; i--)
		pary[i] = pary[i + 1] + p[i].F.S;
	
	for (int i = 1; i <= n; i++) {
		int idx = p[i].S;
		ans[idx] = pary[i + 1] + 1ll * (n - i) * p[i].F.F + parx[i - 1] + 1ll * (i - 1) * p[i].F.S;
	}
	
	for (int i = 1; i <= m; i++) {
		int fi, se;
		cin >> fi >> se;
		ll q = min (x[fi] + y[se], x[se] + y[fi]);
		ans[fi] -= q;
		ans[se] -= q;
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	cout << endl;
}