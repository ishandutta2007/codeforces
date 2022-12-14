#include <iostream>
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
const int inf = 1e9 + 7, maxn = 1e6 + 500;

ll m[maxn];
ll w[maxn];
ll a, b, p;

ll pw(ll fi, ll se) {
	if (se == 0)
		return 1;
	if (se == 1)
		return fi;
	ll ret = pw(fi, se / 2);
	ret *= ret;
	ret %= p;
	if (se % 2 == 1) {
		ret *= fi;
		ret %= p;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> a >> b >> p;
	ll x;
	cin >> x;
	for (int i = 1; i < p; i++) {
		m[i] = b * pw(i, p - 2);
		m[i] %= p;
	}
	for (int i = 1; i < p; i++) {
		w[i] = pw(a, i);
	}
	ll rem = x % (p * (p - 1));
	ll ans = x / (p * (p - 1)) * (p - 1);
	ll cur = rem / (p - 1);
	for (int i = 1; i < p; i++) {
		ll o = m[w[i]];
		if (o <= i) {
			if (cur >= (i - o + 1))
				ans++;
			else if (cur + 1 >= (i - o + 1)) {
				if (i <= rem % (p - 1))
					ans++;
			}
		} else {
			if (cur >= i + 1 + (p - 1 - o + 1)) {
				ans++;
			} else if (cur + 1 >= i + 1 + (p - o)) {
				if (i <= rem % (p - 1))
					ans++;			
			}
		}
	}
	cout << ans << endl;
}