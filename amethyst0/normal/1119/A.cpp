#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int maxn = (int)3e5 + 10;
int v[maxn];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int pos = -1;

	for (int i = n - 1; i >= 0; i--) {
		if (v[i] != v[n - 1]) {
			pos = i;
			break;
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (v[i] != v[n - 1]) {
			ans = max(n - 1 - i, ans);
		}
		else {
			ans = max(ans, pos - i);
		}
	}

	cout << ans << endl;

	//system("pause");

	return 0;
}