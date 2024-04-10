#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
int C[101000], CC[101000], cnt, res;
int n, w[101000];
set<int>Set;
int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		if (!C[w[i]]) {
			cnt++;
		}
		else {
			CC[C[w[i]]]--;
			if (!CC[C[w[i]]])Set.erase(C[w[i]]);
		}
		C[w[i]]++;
		CC[C[w[i]]]++;
		Set.insert(C[w[i]]);
		if (cnt == 1) {
			res = i;
			continue;
		}
		if (CC[1] == cnt) {
			res = i;
			continue;
		}
		int t = C[w[i]];
		if (Set.size() == 2) {
			if (CC[1] == 1) {
				res = i;
			}
			else {
				auto it = Set.end();
				it--;
				int x = *it;
				if (CC[x] == 1 && CC[x - 1] == cnt - 1)res = i;
			}
		}
	}
	printf("%d\n", res);
}