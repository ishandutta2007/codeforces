#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
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
#include <fstream>
#include <bitset>
#include <limits.h>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>
#define uint int

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main() {
	int n, k;

	cin >> n >> k;

	string s;

	cin >> s;

	string ans = s;

	for (int i = k; i < n; i++) {
		ans[i] = ans[i - k];
	}

	if (ans >= s) {
		cout << ans.size() << endl;
		cout << ans << '\n';
		return 0;
	}

	ans = s;

	for (int i = k - 1; i >= 0; i--) {
		if (s[i] == '9') {
			ans[i] = '0';
		}
		else {
			ans[i] = s[i] + 1;
			break;
		}
	}

	for (int i = k; i < n; i++) {
		ans[i] = ans[i - k];
	}

	cout << ans.size() << endl;
	cout << ans << '\n';
	return 0;
}