#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

int power(int a, int b){
	if (b == 0)
		return 1;
	int ret = power(a, b/2);
	ret = 1ll * ret * ret % mod;
	if (b & 1)
		ret = 1ll * ret * a % mod;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	cout << power((power(2, m) - 1), n) << endl;
}