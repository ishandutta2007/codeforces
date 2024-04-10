#include<bits/stdc++.h>
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*2+c-'0',c=getchar();
	return num;
}
inline int popcount(int x) {
	int ans = 0;
	while (x) ++ans, x ^= x & -x;
	return ans;
}
int f[2001][2001];
int work[1<<7][10];
const int nums[] = {119,18,93,91,58,107,111,82,127,123};
void init() {
	for (int i = 0; i < (1 << 7); i++)
		for (int j = 0; j < 10; j++)
			if ((nums[j] & i) == i) work[i][j] = popcount(nums[j]^i);
			else work[i][j] = -1;
}
int num[2001];
int main() {
	init();
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) num[i] = read();
	for (int i = 1; i <= k; i++) f[n][i] = -1;
	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j <= k; j++) {
			f[i][j] = -1;
			for (int m = 9; m >= 0; m--)
				if (work[num[i+1]][m] != -1 && j >= work[num[i+1]][m]  && f[i+1][j-work[num[i+1]][m]] != -1) {
					f[i][j] = m;
					break;
				}
		}
	if (f[0][k] == -1) cout << -1 << endl;
	else
		for (int i = 0; i < n; i++) {
			putchar(f[i][k] + '0');
			k -= work[num[i+1]][f[i][k]];
		}
}