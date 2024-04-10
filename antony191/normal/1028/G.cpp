#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <ctime>
#include <utility>

#pragma GCC optimize("O3")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi1;
typedef vector<vi1> vi2;
typedef vector<ll> vll1;
typedef vector<vll1> vll2;

const int inf = 1e9;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define all(v) v.begin(), v.end()

ll dp[5][10000], d[5];

ll get(int c, ll k) {
	if (k < 10000)
		return dp[c][k];
	return d[c] * 1ll + k * 1ll;
}
int main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	d[0] = 0;
	for (int i = 1; i < 5; ++i)
		d[i] = d[i - 1] * 10001ll + 10000ll;
	for (int i = 1; i < 10000; ++i) dp[0][i] = i;
	for (int i = 1; i < 5; ++i) {
	//	cout << i << ' ';
		for (int j = 1; j < 10000; ++j) {
			ll r = j * 1ll;
			for (int k = 0; k <= j; ++k) {
				r = get(i - 1, r) + 1;
			}
			dp[i][j] = r - 1;
		}
	}
	ll l = 1, r = 10004205361450474;
	for (int i = 5; i; --i) {
		vector<ll> k(min(l, 10000ll));
		k[0] = get(i - 1, l);
		for (int j = 1; j < (int)k.size(); ++j)
			k[j] = get(i - 1, k[j - 1] + 1);
		cout << (int)k.size() << ' ';
		for (auto j : k)
			cout << j << ' ';
		cout << endl;
		int tmp;
		cin >> tmp;
		if (tmp < 0)
			break;
		if (tmp == 0)
			r = k[0] - 1;
		else {
			if (tmp == (int)k.size())
				l = k.back() + 1;
			else {
				l = k[tmp - 1] + 1;
				r = k[tmp] - 1;
			}
		}
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}