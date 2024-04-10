#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <string.h>
#include <assert.h>
#include <complex>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
mt19937 rr(random_device{}());




int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	ll n;
	cin >> n;
	vector<ll> d;
	ll i;
	for (i = 1; i * i < n; ++i) {
		if (n % i == 0)
			d.push_back(i);
	}
	if (i * i > n)
		--i;
	for (; i >= 1; --i) {
		if (n % i == 0)
			d.push_back(n / i);
	}

	ll k;
	cin >> k;
	--k;
	ll ans = (sz(d) > k ? d[k] : -1);
	cout << ans << endl;
	return 0;
}