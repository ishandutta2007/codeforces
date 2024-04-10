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
const int maxn = 2e5 + 100;
const int mod = 1e9 + 7;
const int max_number = 5e5 + 10;

int size;
ll ans;
int mpf[max_number];
int dp[max_number];

int cntdig(int mask){
	int ret = 0;
	while (mask){
		mask -= mask & -mask;
		ret ++;
	}
	return ret;
}

void add(int x){
	int last = -1;
	vector <int> pdiv;
	while (x > 1){
		if (mpf[x] != last){
			pdiv.PB(mpf[x]);
			last = mpf[x];
		}
		x /= mpf[x];
	}
	int ret = 0;
	int N = pdiv.size();
	for (int mask = 0; mask < (1 << N); mask++){
		ll y = 1;
		for (int i = 0; i < N; i++){
			if (mask & (1 << i)){
				y *= pdiv[i];
			}
		}

		if (cntdig(mask) % 2 == 0)
			ret += dp[y];
		else
			ret -= dp[y];
		dp[y] ++;
	}
	ans += ret;
}

void del(int x){
	int last = -1;
	vector <int> pdiv;
	while (x > 1){
		if (mpf[x] != last){
			pdiv.PB(mpf[x]);
			last = mpf[x];
		}
		x /= mpf[x];
	}
	int ret = 0;
	int N = pdiv.size();
	for (int mask = 0; mask < (1 << N); mask++){
		ll y = 1;
		for (int i = 0; i < N; i++){
			if (mask & (1 << i)){
				y *= pdiv[i];
			}
		}

		dp[y] --;
		if (cntdig(mask) % 2 == 0)
			ret += dp[y];
		else
			ret -= dp[y];
	}
	ans -= ret;

}

void eratosthenes(){
	int N = 500000;
	for (int i = 2; i <= N; i++){
		if (mpf[i] == 0){
			for (int j = i; j <= N; j += i){
				mpf[j] = i;
			}
		}
	}
}

int a[maxn];
bool mark[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	eratosthenes();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++){
		int x;
		cin >> x;
		if (!mark[x])
			add(a[x]);
		else
			del(a[x]);
		mark[x] ^= 1;
		cout << ans << '\n';
	}
}