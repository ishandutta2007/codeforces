#include<bits/stdc++.h>
using namespace std;
long long read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	long long num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
long long a[300001], b[300001];
int main() {
	int t = read();
	while (t--) {
		int n = read();
		long long ans = 0, tmp = 0x3f3f3f3f3f3f3f3f;
		for (int i = 1; i <= n; i++) a[i] = read(), b[i] = read();
		ans += max(0ll, a[1] - b[n]), tmp = min(tmp, a[1] - ans);
		for (int i = 1; i < n; i++) {
			long long x0 = max(0ll, a[i+1] - b[i]);
			ans += x0, tmp = min(tmp, a[i+1] - x0);
		}
		cout << ans + tmp << endl;
	}
}