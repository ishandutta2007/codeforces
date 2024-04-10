#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int maxn = (int)3e5 + 10;
char s[maxn];

bool good(int l, int r) {
	int d = r - l + 1;

	for (int k = 1; k <= d; k++) {
		if (r - 2 * k < l) {
			break;
		}

		if (s[r] == s[r - k] && s[r] == s[r - 2 * k]) {
			return false;
		}
	}

	return true;
}

int main() {
	scanf("%s", s);
	int n = strlen(s);

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		int r = i;
		while (r < n && good(i, r)) {
			r++;
		}

		ans += n - r;
	}

	cout << ans << endl;

	//system("pause");
}