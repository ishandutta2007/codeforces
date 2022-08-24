#include<cstdio>
#include<algorithm>
#include<map>
#include<set>
#define N_ 301000
#define pii pair<int,int>
using namespace std;
map<pii, int>Map;
set<pii>Set;
int n, w[N_];
int T[N_];
long long Res;
int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		Res += w[i];
	}
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (Set.find({ a,b }) != Set.end()) {
			Set.erase({ a,b });
			int t = Map[{a, b}];
			Map[{a, b}] = 0;
			if (T[t] <= w[t]) {
				Res++;
			}
			T[t]--;
		}
		if (c == 0) {
			printf("%lld\n", Res);
			continue;
		}
		Map[{a, b}] = c;
		Set.insert({ a,b });
		T[c]++;
		if (T[c] <= w[c])Res--;
		printf("%lld\n", Res);
	}
}