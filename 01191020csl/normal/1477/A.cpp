#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
	return b ? gcd(b, a%b) : a;
}
long long a[200001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		long long k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) cin >> a[i];
		long long res = 0;
		for (int i = 1; i < n; i++) res = gcd(res, llabs(a[i]-a[n]));
		if ((k-a[n])%res == 0) puts("YES");
		else puts("NO");
	}
}