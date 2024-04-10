#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<int> a(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		set<int> S(a.begin(), a.end());
		S.erase(0);
		int ans = (int)S.size();
		printf("%d\n", ans);
	}
}