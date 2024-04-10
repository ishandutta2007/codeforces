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
	string s;
	cin >> s;
	int n = (int)s.size();
	int mx = 1, cur = 1;
	for (int i = 1; i < n; ++i) {
		if (s[i] == s[i - 1]) {
			mx = max(mx, cur);
			cur = 1;
		}
		else
			cur++;
	}
	mx = max(mx, cur);
	if (s[0] == s.back() || mx == n)
		cout << mx;
	else {
		int l = 1, r = 1;
		while (s[l] != s[l - 1]) l++;
		while (s[n - r - 1] != s[n - r]) r++;
		cout << max(mx, l + r);
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}