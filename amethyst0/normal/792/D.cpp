/*AMETHYSTS*/
//#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define mp make_pair

using namespace std;

const int maxn = (int)1e5 + 10;
char s[maxn];

void getp(ll ver, ll n, ll &ans) {
	if (ver <= (n - 1) / 2) {
		ans *= 2;
		getp(ver, (n - 1) / 2, ans);
	} else if (ver == (n - 1) / 2 + 1) {
		
	} else {
		ans = ans * 2 + 1;
		getp(ver - (n - 1) / 2 - 1, (n - 1) / 2, ans);
	}
}

vector <int> w;

ll get_ans(ll n) {
	if (w.empty()) {
		return (n - 1) / 2 + 1;
	}

	if (w.back() == 0) {
		w.pop_back();
		return get_ans((n - 1) / 2);
	} else {
		w.pop_back();
		return (n - 1) / 2 + 1 + get_ans((n - 1) / 2);
	}
}

int main() {
	ll n;
	int q;

	cin >> n >> q;

	while (q--) {
		ll v;

		scanf("%I64d %s", &v, s);

		int len = strlen(s);

		ll tmp = 1;
		getp(v, n, tmp);

		for (int i = 0; i < len; i++) {
			if (s[i] == 'U') {
				if (tmp != 1) {
					tmp /= 2;
				}
			} else if (s[i] == 'L') {
				if (tmp * 2 <= n) {
					tmp *= 2;
				}
			} else {
				if (tmp * 2 + 1 <= n) {
					tmp *= 2;
					tmp++;
				}
			}
		}

		w.clear();

		while (tmp != 1) {
			w.push_back(tmp % 2);
			tmp /= 2;
		}

		printf("%I64d\n", get_ans(n));
	}

	return 0;
}