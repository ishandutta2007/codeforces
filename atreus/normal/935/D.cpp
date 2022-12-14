#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define In insert
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7, maxn = 1e6 + 100;
int dp[maxn], a[maxn][5], par[maxn];

ll gcd (ll a, ll b){
	if (b > a)
		swap (a, b);
	if (b == 0)
		return a;
	if (a % b == 0)
		return b;
	return gcd (b, a % b);
}

ll powe(ll a, ll b){
	if (b == 0)
		return 1;
	if (b == 1)
		return a;
	ll ret = powe (a, b / 2);
	ret = (ret * ret) % mod;
	if (b % 2 == 1)
		ret = ret * a % mod;
	return ret % mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i][0];
	for (int i = 0; i < n; i++)
		cin >> a[i][1];
	
	for (int i = n - 1; i >= 0; i--)
		par[i] = par[i + 1] + (a[i][0] == 0) + (a[i][1] == 0);
	
	ll cnt = 0, ans = 0, b = powe (m, par[0]);
	for (int i = 0; i < n; i++){
		if (a[i][0] == 0 and a[i][1] == 0){
			ans += ((((1ll * m * (m - 1) / 2) * powe (m, par[i + 1])) % mod) * powe (m, cnt)) % mod;
			cnt ++;
			ans %= mod;
		}

		else if (a[i][0] == 0){
			ans += ((((m - a[i][1]) * powe (m, par[i + 1])) % mod) * powe (m, cnt)) % mod;
			ans %= mod;
		}

		else if (a[i][1] == 0){
			ans += ((((a[i][0] - 1) * powe (m, par[i + 1])) % mod) * powe (m, cnt)) % mod;
			ans %= mod;
		}
		else if (a[i][1] > a[i][0])
			break;
		
		else if (a[i][1] < a[i][0]){
			ans += (powe (m, par[i + 1]) * powe (m, cnt)) % mod;
			ans %= mod;
			break;
		}
	}

	ll a = ans;
	ll tmp = gcd (a, b);
	a /= tmp;
	b /= tmp;
	cout << (a * powe (b, mod - 2)) % mod << endl;
}