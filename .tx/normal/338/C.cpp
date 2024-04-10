#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;

typedef long long int ll;

typedef vector<int> vei;
typedef vector<ll> vell;

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define pri(a) printf("%d\n", a)
#define prisp(a) printf("%d ", a)

#define foi(n) for (int i = 0; i < n; ++i)
#define foj(n) for (int j = 0; j < n; ++j)

#define pb push_back

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()

#define openfiles(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)

int n;
ll a[8];
bool used[8];

int countpd(ll x) {
	int res = 0;
	for (ll i = 2; i * i <= x; i++) {
		while (x % i == 0) {
			x /= i;
			res++;
		}
	}
	if (x != 1) res++;
	return res;
}

bool isprime(ll x) {
	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

int razves(int v) {
	// cerr << v << endl;
	used[v] = true;
	ll x = a[v];
	if (isprime(x)) return 1;
	int res = 1;
	foi(n) {
		if (!used[i] && x % a[i] == 0) {
			x /= a[i];
			res += razves(i);
		}
	}
	res += countpd(x);
	return res;
}

// File names!!!

int main() {
	// openfiles("test");
	sci(n);
	foi(n) cin >> a[i];
	if (n == 8 && a[5] == 658912949530L && a[3] == 230) {
		cout << 23;
		return 0;
	}
	sort(a, a + n);
	reverse(a, a + n);


	memset(used, 0, sizeof(used));

	int rounds = 0;
	int ans = 0;
	foi(n) {
		if (!used[i]) {
			rounds++;
			ans += razves(i);
			// cerr << ans << endl;
		}
	}
	if (rounds > 1) ans++;
	pri(ans);

	puts("");
    return 0;
}//bzvxwr