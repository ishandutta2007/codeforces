#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll a[101];

bool f(const int k) {
	int diff = 0;
	for(int i = 0; i < n; ++i) {
		if(a[i] > k)
			return false;
		diff += k - a[i];
		diff -= a[i];
	}
	return diff > 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int lo = 0;
	int hi =500;
	while(lo < hi) {
		int mid = (lo + hi) / 2;
		if(f(mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	cout << lo;
	return 0;
}