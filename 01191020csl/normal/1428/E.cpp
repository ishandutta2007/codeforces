#include<bits/stdc++.h>
using namespace std;
int a[100001], id[100001];
long long calc(int n, int k) {
	int b = n/k, tot = n%k;
	return 1ll*b*b*(k-tot)+1ll*(b+1)*(b+1)*tot;
}
int main() {
	int n, k;
	cin >> n >> k;
	long long ans = 0;
	priority_queue<pair<long long, int> > pq;
	for (int i = 1; i <= n; i++) {
		cin >> a[i], id[i] = 1;
		ans += 1ll * a[i] * a[i];
		if (a[i] > 1) pq.push(make_pair(1ll*a[i]*a[i]-1ll*(a[i]/2)*(a[i]/2)-1ll*((a[i]+1)/2)*((a[i]+1)/2), i));
	}
	while (n < k) {
		int p = pq.top().second;
		ans -= pq.top().first;
		pq.pop(), ++id[p];
		if (id[p] < a[p]) pq.push(make_pair(calc(a[p], id[p]) - calc(a[p], id[p]+1), p));
		++n;
	}
	cout << ans << endl;
}