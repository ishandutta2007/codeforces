#include<cstdio>
#include<algorithm>
#include<set>
#define pii pair<int,int>
using namespace std;
int n, m, res;
set<pii>Set[101000];
void Put(int a, int b, int c) {
	auto it = Set[a].lower_bound({ c,-1 });
	if (it == Set[a].begin())return;
	it--;
	pii tp = *it;
	Set[b].insert({ c, tp.second + 1 });
	it = Set[b].find({ c, tp.second + 1 });
	res = max(res, tp.second + 1);
	auto it2 = it;
	it2++;
	if (it2 != Set[b].end() && it2->first == it->first) {
		Set[b].erase(it);
		return;
	}
	it2 = it;
	if (it2 != Set[b].begin()) {
		it2--;
		if (it2->second >= it->second) {
			Set[b].erase(it);
			return;
		}
		if (it2->first == it->first) {
			Set[b].erase(it2);
		}
	}
	while (1) {
		it2 = it;
		it2++;
		if (it2 == Set[b].end()) break;
		if (it2->second > it->second)break;
		Set[b].erase(it2);
	}
}
int main() {
	int i, a, b, c;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		Set[i].insert({ -1,0 });
	}
	for (i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		Put(a, b, c);
	}
	printf("%d\n", res);
}