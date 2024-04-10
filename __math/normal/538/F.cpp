#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

// #pragma comment(linker,"/STACK:36777216")

int a[ten(5) * 2];
int ans[ten(5) * 2 + 10];

int main(){
	int n; scanf("%d", &n);
	FOR(i, n) scanf("%d", a + i);

	for (int v = 1; v < n; v++) {
		int k = 1;
		while (k < n) {
			int p = (v - 1) / k;
			int kn;
			if (p == 0) kn = n;
			else kn = (v - 1) / p + 1;
			if (a[v] < a[p]) {
				ans[k-1]++;
				ans[kn-1]--;
				//printf("[%d-%d) ,", k - 1, kn - 1);
			}
			k = kn;
		}
		//puts("");
	}

	FOR(i, n - 1) ans[i + 1] += ans[i];
	FOR(i, n - 1) printf("%d ",ans[i]);
	puts("");
}