#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 1e7 + 10;
const int mod = 1e9 + 7;
const int MAXN = 664579 + 10;
bool prime[maxn];
int a[maxn], mark[maxn], p[maxn], mpf[maxn], tmp = 0;
ll ted[maxn];

void gharbal (int mxx) {
	memset (prime, -1, sizeof prime);
	prime[1] = 0;
	for (int i = 2; i <= mxx; i++) {
		if (prime[i]) {
			mpf[i] = i;
			p[tmp ++] = i;
			if (1ll * i * i > mxx)
				continue;
			for (ll j = i * i; j <= mxx; j += i) {
				prime[j] = 0;
				mpf[j] = i;
			}
		}
	}
}

bool check (ll n) {
	for (int j = 0; j < tmp; j++) {
		int i = p[j];
		ll cnt = 0, x = i;
		while (n >= x) {
			cnt += n / x;
			x *= i;
		}
		if (cnt < ted[i]) {
			return 0;
		}
		if (cnt == 0)
			return 1;
	}
	return 1;
}

int main () {
//	ios_base::sync_with_stdio (false);
	int n, mxx = 1e7 + 5;
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &a[i]);
	}
	sort (a + 1, a + n + 1);
	int xy = a[n];

	gharbal (mxx);
	
	int cur = 1;
	for (int i = 1; i <= n; i++) {
		while (cur < a[i]) {
			cur ++;
			int tmp = cur;
			while (tmp > 1) {
				ted[mpf[tmp]] += n - i + 1;
				tmp /= mpf[tmp];
			}
		}
	}

	ll l = xy - 1, r = 9999998000001;
	while (r - l > 1) {
		ll mid = (l + r) / 2;
		if (check (mid))
			r = mid;
		else
			l = mid;
	}
	printf ("%lld", r);
}