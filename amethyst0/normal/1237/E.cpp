//#pragma comment(linker, "/STACK:1000000000")
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
#include <memory.h>
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define ld double

using namespace std;

const int mod = 998244353;
const int maxn = (int)1e6 + 10;
int ans[2][maxn];

int main() {
	/*ans[0][0] = ans[1][0] = 1;
	ans[1][1] = 1;

	for (int i = 2; i < 1000; i++) {
		int st = 0;

		while ((1 << (st + 1)) - 1 <= i) {
			st++;
		}

		int cnt = i - (1 << st) + 1;
		int l = 0;
		int r = (1 << (st - 1));

		r = min(r, cnt);
		l = max(l, cnt - (1 << (st - 1)));

		l += (1 << (st - 1)) - 1;
		r += (1 << (st - 1)) - 1;

		for (int x = l + 1; x <= r + 1; x++) {
			int cur = ans[1 - x % 2][x - 1];
			if (x % 2 == 0) {
				cur = (ll)cur * ans[0][i - x] % mod;
			}
			else {
				cur = (ll)cur * ans[0][i - x] % mod;
			}

			ans[x % 2][i] += cur;
			ans[x % 2][i] %= mod;
		}

		//cout << i << ' ' << ans[0][i] << ' ' << ans[1][i] << endl;
		if (ans[0][i] != ans[1][i] != 0) {
			cout << i << ' ' << ans[0][i] + ans[1][i] << '\n';
		}
	}*/

	int n;

	cin >> n;

	int x = 1;

	while (x <= n) {
		if (x == n || x + 1 == n) {
			cout << 1 << endl;
			//system("pause");
			return 0;
		}

		x++;

		if (x % 2 == 0) {
			x *= 2;
		}
		else {
			x *= 2;
			x--;
		}
	}

	cout << 0 << endl;

	//system("pause");
	return 0;
}