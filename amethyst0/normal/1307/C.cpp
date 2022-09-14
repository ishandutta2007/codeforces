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
#include <cstring>
#include <limits.h>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>
#define uint int

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int maxn = (int)1e5 + 10;
char s[maxn];
ll cnt[26];
ll res[26][26];

int main() {
	scanf("%s", s);

	int n = strlen(s);

	for (int i = 0; i < n; i++) {
		int c = s[i] - 'a';
		
		for (int j = 0; j < 26; j++) {
			res[c][j] += cnt[j];
		}
		
		cnt[c]++;
	}

	ll ans = 0;

	for (int i = 0; i < 26; i++) {
		ans = max(ans, cnt[i]);

		for (int j = 0; j < 26; j++) {
			ans = max(ans, res[i][j]);
		}
	}

	cout << ans << '\n';

	return 0;
}