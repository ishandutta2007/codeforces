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
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.0);



int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);


	int n, m, a, b, o = 0, oo = mod;
	scanf("%d%d%d%d", &n, &m, &a, &b);
	for(int i = 0; i <= n; i++) {
		o = i * a;
		o += ((n - i) / m + (((n - i) % m != 0) ? (1) : (0))) * b;
		oo = min(oo, o);
	}

	printf("%d", oo);

	return(0);
}

// by Kim Andrey