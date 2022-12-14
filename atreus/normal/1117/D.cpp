/**
 *    author:  Atreus
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 100 + 10;
const int mod = 1e9 + 7;

ll m;

ll a[maxn][maxn], b[maxn][maxn], cop[maxn][maxn], c[maxn][maxn];
ll f[2 * maxn];

void power(ll x){
	if (x == 1){
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				b[i][j] = a[i][j];
		return;
	}
	power(x / 2);
	for (int i = 0; i < m; i++){
		for (int j = 0; j < m; j++){
			for (int k = 0; k < m; k++){
				cop[i][j] = (cop[i][j] + b[i][k] * b[k][j]) % mod; 
			}
		}
	}
	for (int i = 0; i < m; i++){
		for (int j = 0; j < m; j++){
			b[i][j] = cop[i][j];
			cop[i][j] = 0;
		}
	}

	if (x & 1){
		for (int i = 0; i < m; i++){
			for (int j = 0; j < m; j++){
				for (int k = 0; k < m; k++){
					cop[i][j] = (cop[i][j] + b[i][k] * a[k][j]) % mod;
				}
			}
		}
		for (int i = 0; i < m; i++){
			for (int j = 0; j < m; j++){
				b[i][j] = cop[i][j];
				cop[i][j] = 0;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n >> m;
	for (int i = 0; i <= 2 * m - 2; i++){
		if (i < m)
			f[i] = 1;
		else
			f[i] = (f[i - 1] + f[i - m]) % mod;
	}
	if (n <= 2 * m - 2)
		return cout << f[n] << endl, 0;

	a[0][0] = 1;
	a[m - 1][0] = 1;
	for (int i = 1; i < m; i++)
		a[i - 1][i] = 1;
	power(n - (2 * m - 2));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			c[i][j] = f[2 * m - 2 - i - j];

	ll answer = 0;
	for (int i = 0; i < m; i++)
		answer = (answer + c[0][i] * b[i][0]) % mod;
	cout << answer << endl;
}