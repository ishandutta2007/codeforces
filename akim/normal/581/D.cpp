#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

char ans[310][310];

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	int x1, y1, x2, y2, x3, y3;
	char c1 = 'A', c2 = 'B', c3 = 'C';
	scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
	int sz = -1, sz2, p = x1 * y1 + x2 * y2 + x3 * y3;
	for(int i = 1; i < 200; i++) {
		if(sqr(i) == p) {
			sz = i;
		}
	}

	if(sz == -1 || x1 > sz || y1 > sz || x2 > sz || y2 > sz || x3 > sz || y3 > sz) {
		printf("-1");
		return(0);
	}
	bool ok = 0;
	if(x1 == sz || y1 == sz) {
		ok = 1;
		if(y1 == sz) {
			swap(y1, x1);
		}
	} else
	if(x2 == sz || y2 == sz) {
		ok = 1;
		swap(x1, x2);
		swap(y1, y2);
		swap(c1, c2);
		if(y1 == sz) {
			swap(y1, x1);
		}
	} else
	if(x3 == sz || y3 == sz) {
		ok = 1;
		swap(x1, x3);
		swap(y1, y3);
		swap(c1, c3);
		if(y1 == sz) {
			swap(y1, x1);
		}
	}
	if(!ok) {
		printf("-1");
		return(0);
	}
	sz2 = sz - y1;
	int zp = 0;
	for(int i = zp + 0; i < zp + y1; i++) {
		for(int f = 0; f < sz; f++) {
			ans[i][f] = c1;
		}
	}
	zp += y1;

	ok = 0;
	if(x2 == sz || y2 == sz) {
		ok = 1;
		if(y2 == sz) {
			swap(y2, x2);
		}
	} else
	if(x3 == sz || y3 == sz) {
		ok = 1;
		swap(x2, x3);
		swap(y2, y3);
		swap(c2, c3);
		if(y2 == sz) {
			swap(y2, x2);
		}
	}
	if(!ok) {
		bool ok1 = 0, ok2 = 0;
		if(x2 == sz2 || y2 == sz2) {
			ok1 = 1;
			if(y2 == sz2) {
				swap(x2, y2);
			}
		}
		if(x3 == sz2 || y3 == sz2) {
			ok2 = 1;
			if(y3 == sz2) {
				swap(x3, y3);
			}
		}
		if(ok1 && ok2) {

		} else {
			printf("-1");
			return(0);
		}
		printf("%d\n", sz);
		for(int i = 0; i < zp; i++) {
			for(int f = 0; f < sz; f++) {
				printf("%c", ans[i][f]);
			}
			printf("\n");
		}
		for(int i = zp + 0; i < sz; i++) {
			for(int f = 0; f < sz; f++) {
				if(f < y2) {
					printf("%c", c2);
				} else {
					printf("%c", c3);
				}
			}
			printf("\n");
		}
		return(0);
	}
	sz2 -= y2;
	for(int i = zp + 0; i < zp + y2; i++) {
		for(int f = 0; f < sz; f++) {
			ans[i][f] = c2;
		}
	}
	zp += y2;
	ok = 0;
	if(x3 == sz || y3 == sz) {
		ok = 1;
		if(y3 == sz) {
			swap(y3, x3);
		}
	}
	if(!ok) {
		printf("-1");
		return(0);
	}
	printf("%d\n", sz);
	for(int i = zp + 0; i < zp + y3; i++) {
		for(int f = 0; f < sz; f++) {
			ans[i][f] = c3;
		}
	}
	for(int i = 0; i < sz; i++) {
		for(int f = 0; f < sz; f++) {
			printf("%c", ans[i][f]);
		}
		printf("\n");
	}

//
//
	return(0);
}

// by Kim Andrey