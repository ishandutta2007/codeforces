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

int main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int first = -1, last = -1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			char tmp;
			cin >> tmp;
			if (tmp == 'B') {
				if (first == -1) first = i * m + j;
				last = i * m + j;
			}
		}
	int x = (last / m) + (first / m);
	x /= 2;
	int y = (last % m) + (first % m);
	y /= 2;
	cout << x + 1 << ' ' << y + 1;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}