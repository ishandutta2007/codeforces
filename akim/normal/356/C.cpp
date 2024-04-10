#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
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
#define LL long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define forit(it,S) for(__typeof((S).begin()) it = (S).begin(); it != (S).end(); it++)
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef pair<int, int> pii;

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.0);
int x[5] = {0};
int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	int n, s = 0, i, o = mod;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {int u; scanf("%d", &u); x[u]++; s+=u;}
	for(int j = 0; j * 3 <= s; j++) if((s - (j * 3)) % 4 == 0 && (s - (j * 3)) / 4 + j <= n) {
		int i = j, f = (s - (j * 3)) / 4, x1 = x[1], x2 = x[2], x3 = x[3], x4 = x[4], o1 = s, t;

		t = min(x4, f); o1 -= t * 4; x4 -= t; f -= t;

		t = min(x3, i); o1 -= t * 3; x3 -= t; i -= t;
		t = min(x4, i); o1 -= t * 3; x4 -= t; i -= t;
		t = min(x2, i); o1 -= t * 2; x2 -= t; i -= t;
		t = min(x1, i); o1 -= t * 1; x1 -= t; i -= t;

		t = min(x3, f); o1 -= t * 3; x3 -= t; f -= t;
		t = min(x2, f); o1 -= t * 2; x2 -= t; f -= t;
		t = min(x1, f); o1 -= t * 1; x1 -= t; f -= t;

		o = min(o, o1);
	}

	if(o == mod) {printf("-1");} else {printf("%d", o);}
	return 0;
}