#include <functional>
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <sstream>
#include <bitset>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)		(a).begin(), (a).end()

typedef long long ll;
typedef pair<int, int> pii;

char a[155][155], s[100500];
int n, m, len;
vector<pii> P;
bitset<150 * 150> msk, st, L, R, U, D;

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n >> m >> len;
	int e = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (int j = 0; j < m; ++j) if (a[i][j] != '#') {
			msk.set(i * m + j);
			if (a[i][j] == 'E') {
				e = i * m + j;
			}
		} else st.set(i * m + j);
	}
	L = (st << 1) & msk;
	R = (st >> 1) & msk;
	U = (st << m) & msk;
	D = (st >> m) & msk;
	st = msk;
	cin >> s;
	for (int i = 0; ; ++i) {
		if (st[e] && st.count() == 1) {
			printf("%d\n", i);
			return 0;
		}
		if (i == len) break;
		switch (s[i]) {
			case 'D':
				st = ((st << m) & msk) | (st & D);
				break;
			case 'U':
				st = ((st >> m) & msk) | (st & U);
				break;
			case 'L':
				st = ((st >> 1) & msk) | (st & L);
				break;
			case 'R':
				st = ((st << 1) & msk) | (st & R);
				break;
		}
	}
	puts("-1");
	return 0;
}