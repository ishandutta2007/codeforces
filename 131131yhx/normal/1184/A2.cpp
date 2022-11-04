#include <bits/stdc++.h>

using namespace std;

int n;

char ch[400010];

int phi[400010];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) phi[i] = i;
	for(int i = 1; i <= n; i++)
		for(int j = i + i; j <= n; j += i) phi[j] -= phi[i];
	scanf("%s", ch);
	int tot = 0;
	for(int i = 1; i <= n; i++) if(n % i == 0) {
		int ans = 1;
		for(int j = 0; j < i; j++) {
			int flag = 0;
			for(int k = j; k < n; k += i) flag ^= ch[k] - '0';
			if(flag == 1) {ans = 0; break;}
		}
		tot += phi[n / i] * ans;
	}
	printf("%d\n", tot);
	return 0;
}