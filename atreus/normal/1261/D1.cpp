#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3000 + 10;
const int mod = 998244353;
int a[maxn], pwk[maxn], pwk2[maxn];
int C[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (k == 1)
		return cout << 0 << endl, 0;
	int x = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] != a[i % n + 1])
			x ++;
	C[0][0] = 1;
	for (int i = 1; i <= x; i++){
		C[0][i] = 1;
		for (int j = 1; j <= i; j++)
			C[j][i] = (C[j - 1][i - 1] + C[j][i - 1]) % mod;
	}
	pwk[0] = pwk2[0] = 1;
	for (int i = 1; i <= n; i++){
		pwk[i] = 1ll * pwk[i - 1] * k % mod;
		pwk2[i] = 1ll * pwk2[i - 1] * (k - 2) % mod;
	}
	int answer = 0;
	for (int i = 1; i <= x; i++){
		for (int j = 0; j < i and i + j <= x; j++){
			int now = 1ll * C[i][x] * C[j][x - i] % mod * pwk[n - x] % mod * pwk2[x - i - j] % mod;
			answer = (answer + now) % mod;
		}
	}
	cout << answer << endl;
}