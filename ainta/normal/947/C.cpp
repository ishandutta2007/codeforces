#include<cstdio>
#include<algorithm>
#include<set>
#define N_ 301000
using namespace std;
int w[N_];
multiset<int>Set;
int n;
int main() {
	int i, a, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	for (i = 1; i <= n; i++) {
		scanf("%d", &a);
		Set.insert(a);
	}
	for (i = 1; i <= n; i++) {
		int s = 0;
		for (j = 29; j >= 0; j--) {
			int t = ((1 << j)&w[i]);
			s ^= t;

			auto it = Set.lower_bound(s);
			if (it == Set.end() || *it >= s + (1 << j)) s ^= (1 << j);
		}
		printf("%d ", s^w[i]);
		Set.erase(Set.find(s));
	}
}