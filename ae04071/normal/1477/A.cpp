#include <bits/stdc++.h>

using namespace std;
using lli = long long;

int n;
lli k,arr[200001];

bool solve() {
	sort(arr, arr+n);
	
	int idx = lower_bound(arr, arr+n, k) - arr;
	if(idx != n && arr[idx] == k) return true;

	lli g = abs(arr[1] - arr[0]);
	for(int i=2;i<n;i++) g = __gcd(g, abs(arr[i] - arr[0]));
	return (k - arr[0]) % g == 0;
}

int main() {
	int test;
	scanf("%d",&test);
	while(test--) {
		scanf("%d%lld",&n,&k);
		for(int i=0;i<n;i++) scanf("%lld",arr+i);

		puts(solve() ? "YES" : "NO");
	}
	return 0;
}