#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 10;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

int f_tl(int n, int r) {
	if (!r) {
		int ans = 0;
		for (int i = 1; i * i <= n; ++i) {
			if (n % i) continue;
			int j = n / i;
			if (__gcd(i, j) > 1) continue;
			if (i != j) {
				ans += 2;	
			} else {
				++ans;	
			}
		}	
		return ans;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (n % i == 0) {
			ans += f_tl(i, r - 1);	
		}	
	}
	return ans;
}

int min_div[N];
const int M = 21;
int tabl[N][M];

void prec() {
	min_div[1] = 1;
	for (ll i = 2; i < N; ++i) {
		if (min_div[i]) continue;
		min_div[i] = i;
		for (ll j = i * i; j < N; j += i) {
			if (!min_div[j]) {
				min_div[j] = i;		
			}	
		}	
	}

	for (int i = 0; i < N; ++i) {
		tabl[i][1] = i + 2;	
	}
	for (int i = 1; i < M; ++i) {
		tabl[0][i] = 2;	
	}
	for (int i = 1; i < N; ++i) {
		for (int j = 2; j < M; ++j) {
			tabl[i][j] = tabl[i][j - 1] + tabl[i - 1][j];
			if (tabl[i][j] >= MOD) tabl[i][j] -= MOD;	
		}	
	}
}

int f(int n, int r) {
	ll ans = 1;
	while (n > 1) {
		int cnt = 0;
		int cur_div = min_div[n];
		while (n % cur_div == 0) {
			cnt++;
			n /= cur_div;
		}	
		ans *= (ll)tabl[r][cnt];
		ans %= MOD;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	prec();

	int q;
	cin >> q;
	while (q--) {
		int r, n;
		cin >> r >> n;	
		cout << f(n, r) << "\n";
	}
}