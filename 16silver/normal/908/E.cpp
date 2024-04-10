#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define P 1000000007LL
using namespace std;
long long stng[1003][1003], sttot[1003];
int cncn[1003][1003], chkd[1003];
char c[50][1111];
int main() {
	int m, n, i, j, k, temp;
	long long ans = 1LL;
	scanf("%d%d", &m, &n);
	for (i = 0; i < n; i++) scanf("%s", c[i]);
	for (i = 0; i < m - 1; i++) {
		for (j = i + 1; j < m; j++) {
			for (k = 0; k < n; k++) {
				if (c[k][i] != c[k][j]) break;
			}
			if (k == n) {
				cncn[i][j] = 1;
				cncn[j][i] = 1;
			}
			else {
				cncn[i][j] = 0;
				cncn[j][i] = 0;
			}
		}
	}
	for (i = 0; i < m; i++) cncn[i][i] = 1;
	for (i = 1; i < 1002; i++) stng[i][1] = 1LL;
	for (i = 2; i < 1002; i++) {
		stng[i][i] = 1LL;
		for (j = i + 1; j < 1002; j++) {
			stng[j][i] = (stng[j - 1][i - 1] + ((long long)i)*stng[j - 1][i]) % P;
		}
	}
	for (i = 1; i < 1002; i++) {
		sttot[i] = 0LL;
		for (j = 1; j <= i; j++) {
			sttot[i] = (sttot[i] + stng[i][j]) % P;
		}
	}
	for (i = 0; i < m; i++) chkd[i] = 0;
	for (i = 0; i < m;) {
		chkd[i] = 1;
		temp = 1;
		for (j = i + 1; j < m; j++) {
			if (cncn[i][j] == 1) {
				chkd[j] = 1;
				temp++;
			}
		}
		ans = (ans*sttot[temp]) % P;
		for (;i<m && chkd[i] == 1; i++);
	}
	printf("%I64d", ans%P);
}