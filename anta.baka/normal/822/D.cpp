#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int maxn = 5e6 + 1;

int t, l, r;
vector<int> lo(maxn, -1);
int f[maxn];
int ans;

int main() {
	for(int i = 2; i * i < maxn; i++)
		if(lo[i] == -1)
			for(int j = i * i; j < maxn; j += i)
				if(lo[j] == -1)
					lo[j] = i;
	for(int i = 2; i < maxn; i++)
		if(lo[i] == -1)
			f[i] = (1LL * i * (i - 1) / 2) % mod;
		else {
			int x = i;
			int y = lo[i];
			f[i] = (1LL * x / y * f[y] + f[x / y]) % mod;
		}
	cin >> t >> l >> r;
	int w = 1;
	for(int i = l; i <= r; i++) {
		ans = (ans + 1LL * f[i] * w) % mod;
		w = (1LL * w * t) % mod;
	}
	cout << ans;
}