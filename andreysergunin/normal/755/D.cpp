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
	
	ll n, k;
	cin >> n >> k;

	if (k > n / 2) {
		k = n - k;
	}

	ll ans = 1;
	int d = 0;
	int cur = 0;

	for (int i = 0; i < n; ++i) {
		if (cur + k >= n) {
			++d;
			cur -= n;
			--ans;
		}
		cur += k;
		ans += 2 * d + 1;
		if (i == n - 1)
			--ans;
		cout << ans << " ";
	}

	cout << endl;
		
	return 0;
}