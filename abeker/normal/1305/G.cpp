#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
 
const int MAXN = 1 << 18;
const int LOG = 18;
 
int N;
int a[MAXN];
int dad[MAXN], rnk[MAXN];
int comp[MAXN];
 
void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
}
 
int find(int x) {
	return dad[x] == x ? x : dad[x] = find(dad[x]);
}
 
bool join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return false;
	if (rnk[x] > rnk[y])
		swap(x, y);
	dad[x] = y;
	rnk[y] += rnk[x] == rnk[y];
	return true;
}
 
ll solve() {
	N++;
	ll sol = 0;
	for (int i = 0; i < N; i++) {
		sol -= a[i];
		dad[i] = i;
	}
		
	for (int num = N; num > 1; ) {
		vector <int> mx1(MAXN, -1), opt1(MAXN, -1);
		vector <int> mx2(MAXN, -1), opt2(MAXN, -1);
		for (int i = 0; i < N; i++) {
			comp[i] = find(i);
			if (opt1[a[i]] == -1) {
				opt1[a[i]] = comp[i];
				mx1[a[i]] = a[i];
			}
			else if (comp[i] != opt1[a[i]]) {
				opt2[a[i]] = comp[i];
				mx2[a[i]] = a[i];
			}
		}
		for (int i = 0; i < MAXN; i++) {
			vector <int> ch;
			for (int j = 0; j < LOG; j++) 
				if (i >> j & 1)
					ch.push_back(i ^ (1 << j));
			for (auto it : ch)
				if (mx1[it] > mx1[i]) {
					mx1[i] = mx1[it];
					opt1[i] = opt1[it];
				}
			for (auto it : ch) {
				if (opt1[it] == opt1[i] && mx2[it] > mx2[i]) {
					mx2[i] = mx2[it];
					opt2[i] = opt2[it];
				}
				if (opt1[it] != opt1[i] && mx1[it] > mx2[i]) {
					mx2[i] = mx1[it];
					opt2[i] = opt1[it];
				}
			}
		}
		vector <pii> best(N, {-1, -1});
		for (int i = 0; i < N; i++) {
			int cpl = a[i] ^ (MAXN - 1);
			for (auto cand : {pii(mx1[cpl], opt1[cpl]), pii(mx2[cpl], opt2[cpl])})
				if (cand.second != -1 && cand.second != comp[i])
					best[comp[i]] = max(best[comp[i]], {a[i] + cand.first, cand.second});
		}
		for (int i = 0; i < N; i++)
			if (best[i].second != -1 && join(i, best[i].second)) {
				sol += best[i].first;	
				num--;
			}
	}
	
	return sol;
}
 
int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}