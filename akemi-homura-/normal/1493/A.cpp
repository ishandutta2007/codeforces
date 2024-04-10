#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, k;
		scanf("%d%d", &n, &k);
		vector<int> vec;
		for (int i = k + 1; i <= n; i++) vec.push_back(i);
		for (int i = (k % 2 == 0 ? k / 2 : k / 2 + 1); i < k; i++) vec.push_back(i);
		printf("%d\n", (int)vec.size());
		for (int x : vec) printf("%d ", x);
		puts("");
	}
	return 0;
}