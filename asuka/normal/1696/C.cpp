#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int t, n, m, k;

vector<pair<int, ll>> fk(vector<int> vec) {
	vector<pair<int, ll>> ans;

	for (int x : vec) {
		int c = 1, v = x;

		while (v % m == 0) v /= m, c *= m;

		if (!ans.empty()) {
			if (ans.back().fi == v) ans.back().se += c;
			else ans.eb(v, c);

		} else ans.eb(v, c);
	}

	return ans;
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d", &t);

	while (t--) {
		scanf("%d%d", &n, &m);
		vector<int> a(n);

		rep(i, 0, n - 1) scanf("%d", &a[i]);

		scanf("%d", &k);

		vector<int> b(k);

		rep(i, 0, k - 1) scanf("%d", &b[i]);

		puts(fk(a) == fk(b) ? "Yes" : "No");
	}

	return 0;
}