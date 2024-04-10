#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#define N_ 501000
using namespace std;
int n, m;
long long w[N_], S[N_];
vector<int>E[N_];
long long gcd(long long a, long long b) {
	return b ? gcd(b, a%b) : a;
}
int main() {
	int i, TC, j;
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; i++) {
			scanf("%lld", &w[i]);
			E[i].clear();
		}
		for (i = 0; i < m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			E[b].push_back(a);
		}
		map<vector<int>, int>Map;
		int cnt = 0;
		for (i = 1; i <= n; i++) {
			if (E[i].empty())continue;
			sort(E[i].begin(), E[i].end());
			if (!Map.count(E[i])) {
				Map[E[i]] = ++cnt;
				S[cnt] = 0;
			}
			S[Map[E[i]]] += w[i];
		}
		long long r = 0;
		for (i = 1; i <= cnt; i++)r = gcd(r, S[i]);
		printf("%lld\n", r);
	}

}