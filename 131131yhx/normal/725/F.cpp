#include <bits/stdc++.h>
#define int long long

using namespace std;

priority_queue <int> hsh;

#undef int
int main()
#define int long long
{
	int sum = 0, n;
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) {
		int a, b, c, d;
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		if(a <= d && b <= c) continue;
		if(a <= d && a - d <= c - b) {sum += c - b; continue;}
		if(b <= c && b - c <= d - a) {sum += a - d; continue;}
		hsh.push(a + b), hsh.push(c + d), sum += a + c;
	}
	while(!hsh.empty()) hsh.pop(), sum -= hsh.top(), hsh.pop();
	return printf("%lld\n", sum), 0;
}