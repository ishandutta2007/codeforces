#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;

int N;
int price[MAXN];
int X, A;
int Y, B;
ll K;

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", price + i);
		price[i] /= 100;
	}
	scanf("%d%d", &X, &A);
	scanf("%d%d", &Y, &B);
	scanf("%lld", &K);
}

bool check(int val) {
	vector <int> cnt(val, 0);
	for (int i = A - 1; i < val; i += A)
		cnt[i] += X;
	for (int i = B - 1; i < val; i += B)
		cnt[i] += Y;
	
	sort(cnt.begin(), cnt.end(), greater <int> ());
	
	ll sum = 0;
	for (int i = 0; i < val; i++)
		sum += (ll)price[i] * cnt[i];
	
	return sum >= K;
}

int solve() {
	sort(price, price + N, greater <int> ());
	int lo = 1, hi = N + 1;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (check(mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	return lo == N + 1 ? -1 : lo;
}

int main() {
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		load();
		printf("%d\n", solve());
	}
	return 0;
}