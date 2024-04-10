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
typedef vector<vi2> vi3;
typedef vector<vi3> vi4;
typedef vector<vi4> vi5;

const int inf = 1e9;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define all(v) v.begin(), v.end()

int main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x, d;
	cin >> x >> d;
	vi1 a;
	int sum = 0;
	vector<ll> ans;
	while (x > 0) {
		int k = log2(x + 1);
		ll l = (ans.size() > 0 ? ans.back() : 0 * 1ll);
		for (int i = 0; i < k; ++i)
			ans.push_back(l * 1ll + d);
		x -= (1 << k) - 1;
	}
	cout << (int)ans.size() << '\n';
	for (int i = 0; i < (int)ans.size(); ++i)
		cout << ans[i] << ' ';

#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}