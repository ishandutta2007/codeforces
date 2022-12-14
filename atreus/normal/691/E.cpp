#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int maxn = 100 + 10;
const int mod = 1e9 + 7;

ll a[maxn];
ll n;

ll x[maxn][maxn], y[maxn][maxn], z[maxn][maxn];

void power(ll k){
	if (k == 1){
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				y[i][j] = x[i][j];
		return;
	}

	power(k / 2);
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			for (int k = 0; k < n; k++){
				z[i][j] = (z[i][j] + y[i][k] * y[k][j] % mod) % mod;
			}
		}
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			y[i][j] = z[i][j];
			z[i][j] = 0;
		}
	}
	if (k & 1){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				for (int k = 0; k < n; k++){
					z[i][j] = (z[i][j] + y[i][k] * x[k][j] % mod) % mod;
				}
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				y[i][j] = z[i][j];
				z[i][j] = 0;
			}
		}
	}
}

bool cntdiv3(ll x){
	int ret = 0;
	while (x){
		x -= x & -x;
		ret ++;
	}
	return ret % 3 == 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	ll k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (k == 1)
		return cout << n << endl, 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			x[i][j] = cntdiv3(a[i] ^ a[j]);
		}
	}
	power(k - 1);
	ll ans = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			ans = (ans + y[i][j]) % mod;
		}
	}
	cout << ans << endl;
}