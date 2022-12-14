
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <memory.h> 
#include <math.h> 
#include <assert.h> 
#include <stack> 
#include <queue> 
#include <map> 
#include <set> 
#include <algorithm> 
#include <string> 
#include <functional> 
#include <vector> 
#include <deque> 
#include <utility> 
#include <bitset> 
#include <limits.h>  
#include <unordered_map>
#include <unordered_set>
#include <time.h>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAXN = 3000000;

bool isc[MAXN+5];
int X[MAXN+5], Y[MAXN+5];

int main() {
#ifndef ONLINE_JUDGE
	freopen("568A.in", "r", stdin);
	freopen("568A.out", "w", stdout);
#endif

	int p, q; scanf("%d%d", &p, &q);

	for (int p = 2; p < MAXN; p++) if (!isc[p]) {
		for (int x = p + p; x < MAXN; x += p) isc[x] = true;
	}
	isc[1] = true;

	int x = 0, y = 0;
	for (int i = 1; i <= MAXN; i++) {
		string s;
		char st[10]; sprintf(st, "%d", i);
		s = st; reverse(s.begin(), s.end());
		if (s == st) ++x;
		if (!isc[i]) ++y;
		X[i] = x, Y[i] = y;
	}

	for (int i = MAXN; i > 0; i--) {
		int x = X[i], y = Y[i];
		if ((ll)y * q <= (ll)p * x) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}