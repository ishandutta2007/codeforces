#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

void subsetSum(int N, const vector<int> &sizes, vector<bool> &result) {
	vector<int> counts(N + 1);
	for(int size : sizes)
		++ counts[size];
	vector<int> v;
	for (int i = 1; i <= N; ++ i) {
		int n = counts[i];
		while (n > 0) {
			int m = (n + 1) / 2;
			v.emplace_back(i * m);
			n -= m;
		}
	}
	using BitSet = bitset<1000001>;
	BitSet dp;
	dp.set(0);
	for (int x : v)
		dp |= dp << x;
	result.assign(N + 1, false);
	rep(i, N + 1)
		result[i] = dp[i];
}

int main() {
	int n; int k;
	while (~scanf("%d%d", &n, &k)) {
		vector<int> p(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &p[i]), -- p[i];
		vector<bool> vis(n);
		vector<int> cycles;
		rep(i, n) if (!vis[i]) {
			int j = i, len = 0;
			while (!vis[j]) {
				vis[j] = true;
				j = p[j];
				++ len;
			}
			cycles.push_back(len);
		}
		sort(cycles.begin(), cycles.end());
		vector<bool> canMake;
		subsetSum(n, cycles, canMake);
		int ansMin = canMake[k] ? k : k + 1;
		int ansMax = 0;
		{
			int remK = k, odds = 0;
			for (int x : cycles) {
				int t = min(remK, x / 2);
				ansMax += t * 2;
				remK -= t;
				odds += x % 2;
			}
			ansMax += min(remK, odds);
		}
		printf("%d %d\n", ansMin, ansMax);
	}
	return 0;
}