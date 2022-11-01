#include <bits/stdc++.h>

using namespace std;

const int N = 500005;

string S;
long long n, a, b, T, ara[N], rev[N], asum[N], rsum[N];

int main() {
	scanf("%I64d %I64d %I64d %I64d", &n, &a, &b, &T);
	cin >> S; ara[0] = (S[0] == 'h' ? 1 : b + 1);
	asum[0] = ara[0], rsum[0] = ara[0], rev[0] = ara[0];
	for (int i = 1; i < n; i++) {
		if (S[i] == 'w') ara[i] = a + b + 1;
		else ara[i] = a + 1;
		asum[i] = asum[i - 1] + ara[i];
		rev[i] = ara[i];
	}
	reverse(rev + 1, rev + n);
	for (int i = 1; i < n; i++) rsum[i] = rsum[i - 1] + rev[i];
	//for(int i = 0; i < n; i++) cout << ara[i] << " ";cout<<endl;
	
	if (ara[0] > T) {
		cout << 0 << endl;
		return 0;
	}
	
	long long ret1 = (upper_bound(asum, asum + n, T) - asum) - 1;
	ret1 = min(ret1 + 1, n);
	
	long long ret2 = (upper_bound(rsum, rsum + n, T) - rsum) - 1;
	ret2 = min(ret2 + 1, n);
	
	long long ret3 = 1, sum = 0;
	for (long long i = 1; i < n; i++) {
		if (asum[i] + i * a > T) break;
		long long lft = T - asum[i] - i * a + ara[0];
		long long tmp = (upper_bound(rsum, rsum + n, lft) - rsum) - 1;
		ret3 = max(ret3, min(n, i + tmp + 1));
	}
	
	for (long long i = 1; i < n; i++) {
		if (rsum[i] + i * a > T) break;
		long long lft = T - rsum[i] - i * a + rev[0];
		long long tmp = (upper_bound(asum, asum + n, lft) - asum) - 1;
		ret3 = max(ret3, min(n, i + tmp + 1));
	}
	
	printf("%I64d\n", max(ret1, max(ret2, ret3)));
	return 0;
}