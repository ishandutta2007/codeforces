/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <unordered_map>
#include <random>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)2e5 + 10;
char s[maxn];

int main() {
	int n, a, b, k;

	cin >> n >> a >> b >> k;

	scanf("%s", s);

	int cnt = 0;

	int now = 0;

	int len = strlen(s);

	for (int i = 0; i < len; i++) {
		if (s[i] == '1') {
			now = 0;
			continue;
		}

		now++;

		if (now == b) {
			cnt++;
			now = 0;
		}
	}

	now = 0;

	vector <int> ans;

	for (int i = 0; i < n; i++) {
		if (cnt < a) {
			break;
		}

		if (s[i] == '1') {
			now = 0;
			continue;
		}

		now++;

		if (now == b) {
			ans.push_back(i + 1);
			cnt--;
			now = 0;
		}
	}

	cout << ans.size() << endl;

	for (int i = 0; i < (int)ans.size(); i++) {
		printf("%d ", ans[i]);
	}

	return 0;
}