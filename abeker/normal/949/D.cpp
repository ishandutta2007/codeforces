#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

int N, D, B;
int a[MAXN];

void load() {
	scanf("%d%d%d", &N, &D, &B);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
}

int lft(int pos) {
	return a[max(pos - (ll)min(pos, N + 1 - pos) * D - 1, 0ll)];
}

int rig(int pos) {
	return a[N] - a[min(pos + (ll)min(pos, N + 1 - pos) * D, (ll)N)];
}

int range(int pos) {
	return a[N] - lft(pos) - rig(pos);
}

bool check(int val) {
	int mx1 = 0;
	for (int i = val + 1; i <= (N + 1) / 2; i++) {
		if (range(i) < (i - val) * B)
			return false;
		mx1 = max(mx1, lft(i) + (i - val) * B);
	}
	
	int mx2 = 0;
	for (int i = N - val; i > (N + 1) / 2; i--) {
		if (range(i) < (N - val - i + 1) * B)
			return false;
		mx2 = max(mx2, rig(i) + (N - val - i + 1) * B);
	}
	
	return mx1 + mx2 <= a[N];
}

int solve() {
	for (int i = 1; i <= N; i++)
		a[i] += a[i - 1];
		
	int lo = 0, hi = (N + 1) / 2;
	while (lo < hi) {
		int mid = (lo + hi) / 2; 	
		if (check(mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	
	return lo;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}