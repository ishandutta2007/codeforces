#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf=2000000000;
const ld eps=1e-07;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		int s, t, f;
		scanf("%d %d %d", &s, &t, &f);
		if (s == t) {
			cout << f << endl;
			continue;
		}
		int tekt = f % (2 * m - 2);
		if (tekt > m - 1) {
			tekt = m - (tekt + 1 - m);
			if (s <= tekt)
				f += tekt - s;
			else f += tekt - 1 + s - 1;
		}
		else {
			tekt++;
			if (s >= tekt)
				f += s - tekt;
			else f += m - tekt + m - s;
		}
		tekt = f % (2 * m - 2);
		if (tekt < m) {
			tekt++;
			if (t >= tekt)
				f += t - tekt;
			else f += m - tekt + m - t;
		}
		else {
			tekt = m - (tekt + 1 - m);
			if (tekt >= t)
				f += tekt - t;
			else f += tekt + t - 2;
		}
		printf("%d\n", f);
	}
	return 0;
}