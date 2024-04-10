#include <math.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 500;
long long dp[maxn], a[maxn], b[maxn];

int main(){
	long long n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= q; i++){
		long long l, r;
		cin >> l >> r;
		b[l] ++;
		b[r + 1] --;
	}
	long long l = 0;
	for (int i = 1; i <= n; i++){
		l += b[i];
		if (l < 0)
			l = 0;
		dp[i] = l;
	}
	sort(dp + 1, dp + n + 1, greater <long long>());
	sort(a + 1, a + n + 1, greater <long long>());
	long long k = 0;
	for (int i = 1; i <= n; i++){
		if (dp[i] > 0)
			k += 1ll * dp[i] * a[i];
		else
			break;
	}
	cout << k << endl;
}