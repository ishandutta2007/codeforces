#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N;
int a[MAXN];
vector <int> who[MAXN];
int ans[MAXN];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		who[N - x].push_back(i);
	}
	
	int curr = 1;
	for (int i = 1; i <= N; i++) {
		int cnt = who[i].size();
		if (cnt % i) {
			puts("Impossible");
			return 0;
		}
		for (int j = 0; j < cnt / i; j++)
			for (int k = 0; k < i; k++)
				ans[who[i][j * i + k]] = curr + j;
		curr += cnt / i;
	}
	
	puts("Possible");
	for (int i = 0; i < N; i++)
		printf("%d ", ans[i]);
	puts("");
	
	return 0;
}