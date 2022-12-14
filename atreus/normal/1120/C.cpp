#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 5e3 + 10;
const int base = 37;
const int mod = 1e9 + 7;

int n;
string s;
int pw[maxn], hsh[maxn];

int getHash(int L, int R){
	int tmp = 0;
	if (L > 0)
		tmp = 1ll * hsh[L - 1] * pw[R - L + 1] % mod;
	return (hsh[R] - tmp + mod) % mod;
}

bool check(int L, int R){
	int len = R - L + 1;
	int x = getHash(L, R);
	for (int i = 0; i + len - 1 < L; i++)
		if (x == getHash(i, i + len - 1))
			return 1;
	return 0;
}

void buildHash(){
	pw[0] = 1;
	for (int i = 1; i <= n; i++)
		pw[i] = 1ll * pw[i - 1] * base % mod;
	for (int i = 0; i < n; i++){
		if (i == 0){
			hsh[i] = int(s[i] - 'a') + 1;
			continue;
		}
		hsh[i] = (1ll * hsh[i - 1] * base % mod + int(s[i] - 'a') + 1) % mod;
	}
}

int dp[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int a, b;
	cin >> n >> a >> b;
	cin >> s;
	buildHash();
	for (int i = 0; i < n; i++){
		if (i == 0){
			dp[i] = a;
			continue;
		}
		int lo = 0, hi = (i + 1) / 2 + 1;
		while (hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if (check(i - mid + 1, i))
				lo = mid;
			else
				hi = mid;
		}
		dp[i] = dp[i - 1] + a;
		if (lo > 0)	
			dp[i] = min(dp[i], dp[i - lo] + b);
	}
	cout << dp[n - 1] << endl;
}