#include<bits/stdc++.h>
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
inline long long func(int a, int b, int c) {
	return 1ll*(a-b)*(a-b)+1ll*(b-c)*(b-c)+1ll*(c-a)*(c-a);
}
inline long long solve(int a[], int b[], int c[], int n1, int n2, int n3) {
	long long ans = 5000000000000000000;
	int p = 0, q = 0;
	for (int i = 1; i <= n1; i++) {
		while (q <= n2 && b[q] < a[i]) ++q;
		while (p < n3 && c[p+1] <= a[i]) ++p;
		if (p && q <= n2) ans = min(ans, func(a[i], b[q], c[p]));
	}
	return ans;
}
int a[100001], b[100001], c[100001];
int main() {
	int t = read();
	while (t--) {
		int n1, n2, n3;
		n1 = read(), n2 = read(), n3 = read();
		for (int i = 1; i <= n1; i++) a[i] = read();
		for (int i = 1; i <= n2; i++) b[i] = read();
		for (int i = 1; i <= n3; i++) c[i] = read();
		sort(a + 1, a + n1 + 1);
		sort(b + 1, b + n2 + 1);
		sort(c + 1, c + n3 + 1);
		long long ans = 5000000000000000000;
		ans = min(ans, solve(a, b, c, n1, n2, n3));
		ans = min(ans, solve(a, c, b, n1, n3, n2));
		ans = min(ans, solve(b, a, c, n2, n1, n3));
		ans = min(ans, solve(b, c, a, n2, n3, n1));
		ans = min(ans, solve(c, a, b, n3, n1, n2));
		ans = min(ans, solve(c, b, a, n3, n2, n1));
		cout << ans << endl;
	}
}