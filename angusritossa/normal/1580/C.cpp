#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
#define MAXN 200010
#define SQRT 500
int onDay[MAXN+4*SQRT][SQRT+3], n, m, ans, x[MAXN], y[MAXN], startTime[MAXN], add[MAXN], tot;
vector<array<int, 3> > events;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
	for (int i = 1; i <= m; i++) {
		int op, a;
		scanf("%d%d", &op, &a);
		if (op == 2) {
			events.push_back({startTime[a], i, a});
			add[i]--;
			startTime[a] = 0;
		} else {
			startTime[a] = i;
			add[i]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (startTime[i]) {
			events.push_back({startTime[i], m+1, i});
		}
	}
	for (auto e : events) {
		int a = e[2];
		int sum = x[a]+y[a];
		if (sum >= SQRT) {
			int at = e[0];
			while (at <= e[1]) {
				D("at %d, %d\n", at, x[a]);
				onDay[at][0]++;
				if (at+x[a] <= e[1]) onDay[at+x[a]][0]--;
				at += sum;
			}
		} else {
			onDay[e[0]][sum]++;

			// then, do a minus on the last one
			// we want smallest z s.t. e[0] + z*(x+y) < e[1]
			// z*(x+y) <= e[1]-e[0]
			int z = (e[1]-e[0])/(sum);
			z++;
			onDay[e[0] + z*(sum)][sum]--;

			if (e[1] >= e[0]+x[a]) {
				onDay[e[0]+x[a]][sum]--;

				int z = (e[1]-e[0]-x[a])/sum;
				z++;
				onDay[e[0]+x[a]+z*sum][sum]++;
			}
			z = (e[1]-e[0]-x[a]-1)/(sum);
		}
		// finally, check whether the train is being maintained when it dies
		int deadRelative = e[1]-e[0];
		deadRelative %= sum;
		if (deadRelative < x[a]) {
			// is being maintained
			onDay[e[1]][0]--;
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= SQRT; j++) {
			ans += onDay[i][j];
			// D("%d %d: %d\n", i, j, onDay[i][j]);
			onDay[i+j][j] += onDay[i][j];
		}
		tot += add[i];
		D("tot %d ans %d\n", tot, ans);
		printf("%d\n", tot-ans);
	}
}