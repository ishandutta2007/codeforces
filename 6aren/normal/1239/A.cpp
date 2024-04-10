#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
const int MOD = 1000000007;

int f[100005];
int m, n;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> m >> n;
	f[1] = 2;
	f[0] = 2;
	for (int i = 2; i <= max(m, n); i++) {
		f[i] = f[i - 1] + f[i - 2];
		f[i] %= MOD;
		//cout << f[i] << endl;
	}
	//cout << f[n] << ' ' << f[m] << endl;
	cout << (1LL * f[m] + f[n] - 2 + MOD) % MOD;
	return 0;
}