#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, w[110], sum, ss;
int main() {
	int i;
	scanf("%d", &n);
	vector<int>T;
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		sum += w[i];
	}
	for (i = 1; i <= n; i++) {
		if (i == 1 || w[i] * 2 <= w[1]) {
			ss += w[i];
			T.push_back(i);
		}
	}
	if (ss * 2 > sum) {
		printf("%d\n", T.size());
		for (auto &x : T)printf("%d ", x);
	}
	else{
		puts("0");
	}
}