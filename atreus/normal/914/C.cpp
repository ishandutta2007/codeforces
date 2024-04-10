#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7, maxn = 1e3 + 100;
ll dp[maxn][maxn][2];
ll cont[maxn];

int cnt (int x){
	if (x == 1)
		return 0;
	int k = 0;
	while (x > 0){
		k += x % 2;
		x /= 2;
	}
	return k;
}

int main(){
	string s;
	int k;
	cin >> s >> k;
	int n = s.size();
	for (int i = 0; i <= 1010; i++)
		dp[i][0][0] = 1;
	for (int i = 1; i <= 1010; i++){
		for (int j = 1; j <= i; j++){
			dp[i][j][1] = (dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1]) % mod;
			dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % mod;
		}
	}
	cont[1] = 0;
	for (int i = 2; i <= 1010; i++){
		cont[i] = 1 + cont[cnt(i)];
	}
	ll ans = 0;
	if (k == 0)
		return cout << 1 << endl, 0;
	if (k == 1){
		cout << n - 1 << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++){
		if (cont[i] + 1 == k){
			ans += dp[n][i][1] + dp[n][i][0];
			ans %= mod;
			int l = i;
			for (int i = 0; i < n; i++){
				if (l == 0)
					break;
				if (s[i] == '0'){
					ans += mod - dp[n - i][l][1];
					ans %= mod;
				}
				if (s[i] == '1')
					l --;
			}
		}
	}
	cout << ans << endl;
}