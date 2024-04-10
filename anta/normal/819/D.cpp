#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

template<typename T>T gcd(T x, T y) { if (y == 0)return x; else return gcd(y, x%y); }
int inverse(signed a, const int MOD) {
	a %= MOD;
	if (a < 0) a += MOD;
	signed b = MOD, u = 1, v = 0;
	while (b) {
		signed t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	if (u < 0) u += MOD;
	return u;
}

int main() {
	int M; int n;
	while (~scanf("%d%d", &M, &n)) {
		vector<int> a(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		int A = 0;
		rep(i, n)
			(A += a[i]) %= M;
		int g = gcd(A, M);
		int M_g = M / g;
		int c = inverse(A / g, M_g);
		map<int, vector<pair<int, int>>> poses;
		{
			int sum = 0;
			rep(i, n) {
				int x = sum % g;
				int y = (ll)(sum / g) * c % M_g;
				poses[x].emplace_back(y, i);
				(sum += a[(i + 1) % n]) %= M;
			}
		}
		vector<int> ans(n, 0);
		for (auto &&p : poses) {
			auto &v = p.second;
			sort(v.begin(), v.end());
			for (int i = (int)v.size() - 1; i > 0; -- i) {
				if (v[i - 1].first == v[i].first)
					v[i] = make_pair(-1, -1);
			}
			v.erase(remove(v.begin(), v.end(), make_pair(-1, -1)), v.end());
			bool zero = true;
			rep(i, v.size()) {
				int x = v[i].first, y = v[(i + 1) % v.size()].first;
				int d = (y - x + M_g) % M_g;
				ans[v[i].second] = d == 0 ? M_g : d;
			}
		}
		for (int i = 0; i < (int)ans.size(); ++ i) {
			if (i != 0) putchar(' ');
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}