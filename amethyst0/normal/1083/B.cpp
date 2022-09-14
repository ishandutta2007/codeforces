#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <ctime>
//#include <priority_queue>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ld long double
#define pii pair <int, int>
#define ll long long

using namespace std;

const int maxn = (int)5e5 + 10;
	
char s[maxn], t[maxn];

int main() {
	int n, k;

	cin >> n >> k;

	scanf("%s %s", s, t);

	ll ans = 0;

	int pos = 0;

	while (pos < n && s[pos] == t[pos]) {
		ans++;
		pos++;
	}

	if (pos == n) {
		cout << ans << endl;
		return 0;
	}

	ll cnt = t[pos] - s[pos] - 1;

	while (pos < n && cnt + 2 < k) {
		ans += cnt + 2;
		pos++;
		cnt *= 2;

		if (pos != n) {
			int c = s[pos] - 'a';

			cnt += 2 - c - 1;

			c = t[pos] - 'a';

			cnt += c;
		}
	}

	if (pos < n) {
		ans += (ll)(n - pos) * k;
	}

	cout << ans << endl;

	//system("pause");

	return 0;
}