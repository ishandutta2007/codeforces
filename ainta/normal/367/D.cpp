#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
bool v[1048577];
int C[21];
int n, m, d, w[100010];
int main()
{
	int i, c, a, j, t;
	scanf("%d%d%d", &n, &m, &d);
	for (i = 0; i < m; i++){
		scanf("%d", &c);
		while (c--){
			scanf("%d", &a);
			w[a] = i;
		}
	}
	for (i = 1; i < d; i++){
		C[w[i]]++;
	}
	for (i = d; i <= n; i++){
		C[w[i]]++;
		t = 0;
		for (j = 0; j < m; j++){
			if (!C[j]){
				t += (1 << j);
			}
		}
		v[t] = true;
		C[w[i - d + 1]]--;
	}
	int res = m + 1;
	for (i = (1 << m) - 1; i >= 0; i--){
		if (!v[i]){
			t = 0;
			for (j = 0; j < m; j++){
				if ((1 << j)&i)t++;
			}
			if (res > t)res = t;
			continue;
		}
		for (j = 0; j < m; j++){
			if ((1 << j)&i){
				if (!v[i ^ (1 << j)])v[i ^ (1 << j)] = true;
			}
		}
	}
	printf("%d\n", res);
}