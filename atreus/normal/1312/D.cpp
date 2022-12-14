#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
 
const int mod = 998244353;

int power(int a, int b){
	if (b == 0)
		return 1;
	int ret = power(a, b / 2);
	ret = 1ll * ret * ret % mod;
	if (b & 1)
		ret = 1ll * ret * a % mod;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int pw = 1;
	for (int i = 1; i <= n - 3; i++)
		pw = 2ll * pw % mod;
	int A = 1, B = 1;
	for (int i = n; i <= m; i++)
		A = 1ll * A * i % mod;
	for (int i = 1; i <= m - n + 1; i++)
		B = 1ll * B * i % mod;
	cout << 1ll * pw * A % mod * power(B, mod - 2) % mod * (n - 2) % mod << '\n';
}