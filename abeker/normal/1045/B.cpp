#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 2e5 + 5;
const int BASE1 = 3137;
const int BASE2 = 10007;
const int MOD = 1e9 + 7;

int N, M;
int a[MAXN], b[MAXN];
pii A[MAXN], B[MAXN];
int pot1[MAXN], pot2[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	else if (x < 0)
		x += MOD;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

void build_pref(int *arr, pii *pref) {
	for (int i = 1; i < N; i++) {
		pref[i].first = pref[i - 1].first * BASE1 + arr[i] - arr[i - 1];
		pref[i].second = add(mul(pref[i - 1].second, BASE2), arr[i] - arr[i - 1]);
	}
}

pii get(pii *pref, int lo, int hi) {
	return {pref[hi].first - pot1[hi - lo + 1] * pref[lo - 1].first, add(pref[hi].second, -mul(pot2[hi - lo + 1], pref[lo - 1].second))};
}

bool check(int x) {
	bool res = true;
	if (x)
		res &= (b[0] - b[N - 1] + M) % M == a[N - x] - a[N - x - 1];
	if (x < N - 1)
		res &= get(B, x + 1, N - 1) == get(A, 1, N - x - 1);
	if (x > 1)
		res &= get(B, 1, x - 1) == get(A, N - x + 1, N - 1);
	return res;
}

void solve() {
	for (int i = 0; i < N; i++)
		b[i] = (M - a[i]) % M;
	
	sort(b, b + N);
	
	build_pref(a, A);
	build_pref(b, B);
	
	pot1[0] = pot2[0] = 1;
	for (int i = 1; i <= N; i++) {
		pot1[i] = pot1[i - 1] * BASE1;
		pot2[i] = mul(pot2[i - 1], BASE2);
	}
	
	vector <int> ans;
	for (int i = 0; i < N; i++)
		if (check(i))
			ans.push_back((a[0] - b[i] + M) % M);
		
	sort(ans.begin(), ans.end());
	
	printf("%d\n", ans.size());
	if (ans.empty())
		return;
	for (auto it : ans)
		printf("%d ", it);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}