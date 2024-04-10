#include<bits/stdc++.h>
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
long long a[200001];
int main() {
	int t = read();
	while (t--) {
		int n = read();
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			a[i] = read();
			if (!(i & 1)) ans += a[i], a[i] = -a[i];
			a[i] += a[i-1];

		}
		long long min1 = 0x3f3f3f3f3f3f3f3f, min2 = 0, res = 0;
		for (int i = 0; i < n; i++) {
			res = max(res, i&1?a[i]-min2:a[i]-min1);
			if (i & 1) min2 = min(min2, a[i]);
			else min1 = min(min1, a[i]);
		}
		cout << ans + res << endl;
	}
}