#include <iostream>

using namespace std;

int main (){
	long long n, k, l = 0, r;
	cin >> n >> k;
	if (k * (k - 1) / 2 + 1 < n)
		return cout << -1, 0;
	k --;
	n --;
	r = k + 1;
	long long sig = k * (k + 1) / 2;
	while (r - l > 1){	
		long long mid = (l + r) / 2;
		if (n - (sig - mid * (mid + 1) / 2) <= mid)
			l = mid;
		else
			r = mid;
	}
	long long ans = k - r + 1;
	n -= sig - l * (l + 1) / 2;
	if (n > 0)
		ans ++;
	cout << ans << endl;
}