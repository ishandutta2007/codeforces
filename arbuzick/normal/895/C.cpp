#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int dp[71][1<<19];
vector<int> mask(70);
vector<int> pr = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67 };
const int mod = 1000000007;
int main() {
	int i;
	int n;
	cin >> n;
	for (i = 0; i < 70; i++) {
		mask[i] = 0;
		int j;
		for (j = 0; j < 19; j++) {
			int d, c;
			c = i + 1;
			d = 0;
			while (c % pr[j] == 0) {
				c = c / pr[j];
				d += 1;
			}
			mask[i] += (1 << j) * (d % 2);
		}
	}
	vector<int> a(n);
	for (i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	vector<int> f0(70), f1(70);
	int ind;
	ind = 0;
	for (i = 0; i < 70; i++) {
		if (ind == n) {
			f0[i] = 1;
			f1[i] = 0;
		}
		else if (a[ind] == (i + 1)) {
			int ind1;
			ind1 = ind;
			f0[i] = 1;
			while (a[ind] == (i + 1)) {
				ind += 1;
				if (ind - ind1 == 1)
					f1[i] = 1;
				else {
					int a;
					a = f0[i];
					f0[i]=((ll)f0[i]+f1[i])%mod;
					f1[i] = ((ll)f1[i]+a)%mod;
				}
				if (ind == n)
					break;
			}
		}
		else {
			f0[i] = 1;
			f1[i] = 0;
		}
	}
	dp[0][0] = 1;
	int j;
	j = 0;
	for (i = 1; i <= 70; i++) {
		for (j = 0; j < (1 << 19); ++j) {
			dp[i][j] =(dp[i][j] + ((ll) dp[i - 1][j] * f0[i-1]) % mod) % mod;
			dp[i][j ^ mask[i-1]] =(dp[i][j ^ mask[i-1]] + ((ll)dp[i - 1][j] * f1[i-1]) % mod) % mod;
		}
	}
	cout << dp[70][0]-1;
}