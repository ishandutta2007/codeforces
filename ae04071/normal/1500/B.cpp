#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii = pair<int,int>;

int n,m,a[500000],b[500000],ai[1000001];
int ci[1000001];

int main() {
	long long k;
	scanf("%d%d%lld",&n,&m,&k);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	for(int i=0;i<m;i++) scanf("%d",b+i);

	if (n > m) {
		for (int i = 0; i < n; i++) swap(a[i], b[i]);
		swap(n, m);
	}
	
	for(int i = 1, c = n % m; c != 0; c = (c + n)%m, i++) {
		ci[c] = i;
	}
	
	long long gcd = __gcd(n, m), cs = 1ll * n * m / gcd;
	vector<long long> arr;
	memset(ai, -1, sizeof(ai));
	for(int i=0; i<n; i++) ai[a[i]] = i;
	for(int i=0; i<m; i++) if(ai[b[i]] != -1) {
		int diff = ((i - ai[b[i]])%gcd + gcd)%gcd;
		if(diff == 0) {
			int v = (i - ai[b[i]] + m) % m;
			arr.push_back(1ll*ci[v]*n + ai[b[i]] + 1);
		}
	}
	sort(arr.begin(), arr.end());

	long long dcs = cs - arr.size();
	long long ans = k / dcs * cs;
	k %= dcs;
	
	if (k == 0) {
		ans -= cs;
		for(int i = (int)arr.size() - 1; i>=0; i--) {
			if(arr[i] != cs) break;
			cs--;
		}
		printf("%lld\n", ans + cs);
		return 0;
	}

	for(int i=0;i<arr.size();i++) {
		if(k < arr[i] - i) {
			printf("%lld\n", ans + k + i);
			return 0;
		}
	}
	printf("%lld\n", ans + k + arr.size());
	
	return 0;
}