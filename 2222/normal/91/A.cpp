#include <functional>
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <sstream>
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

int nxt[21111][26];

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	string a, b, c;
	cin >> a >> b;
	c = a + a;
	memset(nxt, -1, sizeof nxt);
	for (int i = c.size() - 1; i --> 0; ) {
		for (int j = 0; j < 26; ++j)
			nxt[i][j] = nxt[i + 1][j];
		nxt[i][c[i + 1] - 'a'] = (i + 1) % a.size();
	}
	int x = a.size() - 1, res = 0;
	for (char q : b) {
		q -= 'a';
		if (nxt[x][q] < 0) {
			res = -1;
			break;
		}
		res += nxt[x][q] <= x;
		x = nxt[x][q];
	}
	cout << res << endl;
	return 0;
}