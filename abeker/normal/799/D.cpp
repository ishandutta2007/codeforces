#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair <ll, int> pii;

const int MAXN = 100005;

int A, B, H, W, N;
int a[MAXN];

void load() {
	scanf("%d%d%d%d%d", &A, &B, &H, &W, &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
}

bool check(int val) {
	vector <pii> left, right;
	for (int i = 0; i < 1 << val / 2; i++) {
		ll prod = 1;
		for (int j = 0; j < val / 2 && prod < MAXN; j++)
			if (i >> j & 1)
				prod *= a[j];
		left.push_back({prod, i});
	}
	
	for (int i = 0; i < 1 << (val + 1) / 2; i++) {
		ll prod = 1;
		for (int j = 0; j < (val + 1) / 2 && prod < MAXN; j++)
			if (i >> j & 1)
				prod *= a[val / 2 + j];
		right.push_back({prod, i});
	}
	
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());
	
	for (int it = 0; it < 2; it++) {
		int need_h = (A - 1) / H + 1;
		int need_w = (B - 1) / W + 1;
		ll mini = 1e18;
		ll opt_left = 0, opt_right = 0;
		for (auto it : left) {
			auto pos = lower_bound(right.begin(), right.end(), pii((need_h - 1) / it.first + 1, 0));
			if (pos == right.end())
				continue;
			ll tmp = it.first * (pos -> first);
			if (tmp < mini) {
				opt_left = it.second;
				opt_right = pos -> second;
				mini = tmp;
			}
		}
		ll tmp = 1;
		for (int i = 0; i < val / 2 && tmp < MAXN; i++)
			if (!(opt_left >> i & 1))
				tmp *= a[i];
		for (int i = 0; i < (val + 1) / 2 && tmp < MAXN; i++)
			if (!(opt_right >> i & 1))
				tmp *= a[val / 2 + i];
		if (mini < 1e18 && tmp >= need_w)
			return true;
		swap(A, B);
	}
	
	return false;
}

int solve() {
	sort(a, a + N, greater <int> ());
	N = min(N, 34);
	
	int lo = 0, hi = N;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (check(mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	
	return check(lo) ? lo : -1;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}