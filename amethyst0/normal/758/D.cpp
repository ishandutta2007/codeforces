/*AMETHYSTS*/
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
#include <unordered_set>
#include <random>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

int main() {
	int n;

	cin >> n;

	string s;

	cin >> s;

	ll st = 1;

	ll ans = 0;

	for (int i = (int)s.size() - 1; i >= 0; ) {
		ll now = 1;
		int pos = i;
		ll z = 0;

		while (pos >= 0 && z + (s[pos] - '0') * now < n) {
			z += (s[pos] - '0') * now;
			now *= 10;
			if (now > 1000000000) {
			    break;
			}
			pos--;
		}

		while (s[pos + 1] == '0' && z != 0) {
			pos++;
		}

		if (z == 0) {
			pos = i - 1;
		}

		ans += z * st;
		st *= n;

		i = pos;
	}

	cout << ans << endl;

	return 0;
}