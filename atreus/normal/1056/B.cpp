#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int mark[200];

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	
	ll cnt = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			int k = i * i + j * j;
			if (k % m == 0)
				cnt ++;
		}
	}
	ll ans = cnt * (n / m) * (n / m);
	if (n % m != 0) {
		ll cnt2 = 0;
		for (int i = 1; i <= n % m; i++) {
			for (int j = 1; j <= m; j++) {
				int k = i * i + j * j;
				if (k % m == 0)
					cnt2 ++;
			}
		}
		ans += 2ll * cnt2 * (n / m);
		for (int i = 1; i <= n % m; i++) {
			for (int j = 1; j <= n % m; j++) {
				int k = i * i + j * j;
				if (k % m == 0)
					ans ++;
			}
		}
	}
	cout << ans << endl;
}