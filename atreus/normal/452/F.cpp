/**
 *    author:  Atreus
 *    created: 06.02.2019 09:53
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int maxn = 3e5 + 10;
int n, p[maxn], pw[maxn], revpw[maxn];
int fen[2][maxn];

int get(int idx, bool wh){
	int ret = 0;
	for (; idx; idx -= idx & -idx){
		ret = ret + fen[wh][idx];
		if (ret >= mod)
			ret -= mod;
	}
	return ret;
}

int get(int L, int R, bool wh){
	if (wh == 0)
		return 1ll * (get(R, wh) - get(L - 1, wh) + mod) * revpw[L] % mod;
	return 1ll * (get(R, wh) - get(L - 1, wh) + mod) * revpw[n - R + 1] % mod;
}

void addto(int x){
	for (int idx = x; idx <= n; idx += idx & -idx){
		fen[0][idx] += pw[x];
		if (fen[0][idx] >= mod)
			fen[0][idx] -= mod;
	}
	for (int idx = x; idx <= n; idx += idx & -idx){
		fen[1][idx] += pw[n - x + 1];
		if (fen[1][idx] >= mod)
			fen[1][idx] -= mod;
	}
}

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
	cin >> n;
	pw[0] = 1;
	for (int i = 1; i <= n; i++){
		cin >> p[i];
		pw[i] = 2 * pw[i - 1] % mod;
	}
	revpw[n] = power(2, n);
	for (int i = n - 1; i >= 0; i--)
		revpw[i] = 2ll * revpw[i + 1] % mod;
	
	for (int i = 1; i <= n; i++){
		addto(p[i]);
		int sz = min(p[i] - 1, n - p[i]);
		if (sz == 0)
			continue;
		int fi = get(p[i] - sz, p[i] - 1, 0);
		int se = get(p[i] + 1, p[i] + sz, 1);
		if (fi != se)
			return cout << "YES" << endl, 0;
	}
	cout << "NO" << endl;
}