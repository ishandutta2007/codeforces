/**
 *    author:  Atreus
 *    created: 28.01.2019 16:31
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e6 + 100;
int mod = 1e9 + 7;
int base = 37;
int hsh[maxn], pw[maxn];

int get_hsh(int L, int R){
	return (1ll * hsh[R] - 1ll * hsh[L - 1] * pw[R - L + 1] % mod + mod) % mod;
}

int ans[maxn];

int main(){
	int n;
	string s;
	cin >> n >> s;
	s = " " + s;
	pw[0] = 1;
	for (int i = 1; i <= n; i++){
		hsh[i] = (1ll * base * hsh[i - 1] + (s[i] - 'a' + 1)) % mod;
		pw[i] = 1ll * base * pw[i - 1] % mod;
	}
	memset(ans, -1, sizeof ans);
	for (int i = 1; i <= n; i++){
		int j = n - i + 1;
		if (j <= i)
			continue;
		int lo = -1, hi = i;
		while (hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if (get_hsh(i - mid, i + mid) == get_hsh(j - mid, j + mid))
				lo = mid;
			else
				hi = mid;
		}
		if (lo != -1)
			ans[i - lo] = max(ans[i - lo], 2 * lo + 1);
	}
	for (int i = 1; i <= n; i++)
		ans[i] = max(ans[i], ans[i - 1] - 2);
	for (int i = 1; i <= (n + 1) >> 1; i++)
		cout << ans[i] << ' ';
}