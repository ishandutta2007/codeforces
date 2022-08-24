#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int w[100010];
vector<int> E[100010];
int n, m, mid;
long long M, S1, S2, R;
int main()
{
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++){
		scanf("%d", &w[i]);
	}
	for (i = 1; i < m; i++){
		if (w[i] != w[i + 1]){
			E[w[i]].push_back(w[i + 1]);
			E[w[i + 1]].push_back(w[i]);
		}
		R = R + abs(w[i + 1] - w[i]);
	}
	for (i = 1; i <= n; i++){
		if (E[i].empty())continue;
		sort(E[i].begin(), E[i].end());
		mid = E[i][E[i].size() / 2];
		S1 = S2 = 0;
		for (j = 0; j < E[i].size(); j++){
			S1 += abs(E[i][j] - i);
			S2 += abs(E[i][j] - mid);
		}
		if (M < S1 - S2) M = S1 - S2;
	}
	printf("%lld\n", R - M);
}