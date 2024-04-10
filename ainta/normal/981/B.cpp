#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int n, m;
map<int, int>Map;
long long res;
int main() {
	int i, a, b;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &a, &b);
		Map[a] = b;
	}
	scanf("%d", &m);
	for (i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		if (Map.count(a) && Map[a] > b)continue;
		Map[a] = b;
	}
	for (auto &x : Map) {
		res += x.second;
	}
	printf("%lld\n", res);
}