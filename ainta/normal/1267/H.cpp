#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#define N_ 8600
#define pii pair<int,int>
using namespace std;
int n, P[N_], w[N_], chk[N_], Ans[N_];
void Solve() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &P[i]);
		w[P[i]] = i;
		Ans[i] = 0;
	}
	for (int col = 1;; col++) {
		vector<pii>V;
		set<int>Set;
		for (i = 1; i <= n; i++) {
			chk[i] = 0;
			if (Ans[i])continue;
			V.push_back({ w[i],i });
			Set.insert(i);
		}
		if (V.empty())break;
		sort(V.begin(), V.end());
		reverse(V.begin(), V.end());
		for (auto &t : V) {
			int x = t.second;
			Set.erase(x);
			if (chk[x])continue;
			chk[x] = 1;
			Ans[x] = col;
			auto it = Set.lower_bound(x);
			if (it != Set.end())chk[*it] = 1;
			if (it != Set.begin())chk[*(prev(it))] = 1;
		}
	}
	for (i = 1; i <= n; i++)printf("%d ", Ans[i]);
	puts("");
}
int main() {
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}