#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;
const int INF = 0x3f3f3f3f;

int N;
int a[MAXN];
int f[MAXN];
int ans[MAXN];
vector <int> comp;

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
}

void update(int x, int val) {
	for (x++; x < MAXN; x += x & -x)
		f[x] = min(f[x], val);
}

int get(int x) {
	int res = INF;
	for (x++; x; x -= x & -x)
		res = min(res, f[x]);
	return res;
}

int compress(int val) {
	return lower_bound(comp.begin(), comp.end(), val) - comp.begin();
}

void solve() {
	memset(f, INF, sizeof f);
	
	for (int i = 0; i < 2 * N; i++)
		a[i + N] = a[i];
	
	for (int i = 0; i < N; i++) {
		comp.push_back(a[i]);
		comp.push_back((a[i] - 1) / 2);
	}
	sort(comp.begin(), comp.end());
	
	int mini = INF;
	for (int i = 3 * N - 1; i >= 0; i--) {
		mini = min(mini, get(compress((a[i] - 1) / 2)));
		ans[i] = mini - i;
		update(compress(a[i]), i);
	}
	
	for (int i = 0; i < N; i++)
		printf("%d ", ans[i] > MAXN ? -1 : ans[i]);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}