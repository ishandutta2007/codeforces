#include <bits/stdc++.h>
using namespace std;

int p[5010][5010], a[5010], b[5010], Ans[5010];
int ans = 0;
bool appear = 0, fff[5010];

int main() {
	
	memset(Ans, 0, sizeof Ans);
	
	int n;
	scanf("%d", &n);
	printf("? 0 0\n");
	fflush(stdout);
	scanf("%d", &p[0][0]);
	for (int i = 1; i < n; ++i) {
		printf("? %d 0\n", i);
		fflush(stdout);
		scanf("%d", &p[i][0]);
		printf("? 0 %d\n", i);
		fflush(stdout);
		scanf("%d", &p[0][i]);
	}
	
	for (int i = 1; i < n; ++i)
		for (int j = 1; j < n; ++j)
			p[i][j] = ((p[i][0] ^ p[0][j]) ^ p[0][0]);
	
	for (int i = 0; i < n; ++i) {
		bool flag = 1;
		a[0] = i;
		for (int j = 0; j < n; ++j)
			b[j] = (a[0] ^ p[0][j]);
		for (int j = 1; j < n; ++j)
			a[j] = (b[j] ^ p[j][j]);
		memset(fff, 0, sizeof fff);
		for (int j = 0; j < n; ++j)	
			if (b[j] >= n || fff[b[j]] || a[b[j]] != j) {
				flag = 0;
				break;
			}
			else fff[b[j]] = 1;
		for (int j = 0; j < n; ++j) 
			if ((a[0] ^ b[j]) != p[0][j]) {
				flag=0; 
				break;
			}
		for (int j = 0; j < n; ++j) 
			if ((a[j] ^ b[0]) != p[j][0]) {
				flag=0; 
				break;
			}
		if (flag) {
			ans ++;
			if (!appear) {
				for (int j = 0; j < n; ++j)
					Ans[j] = a[j];
				appear = 1;
			}
		}
	}
	
	printf("!\n");
	printf("%d\n", ans);
	for (int i = 0; i < n; ++i)
		printf("%d ", Ans[i]);
	return 0;
	
}