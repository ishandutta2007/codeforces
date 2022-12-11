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

long long x[100100], z[100100][2];

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		long long k; scanf("%I64d", &k);
		x[k] += k;
	}
	
	z[0][0] = 0; z[0][1] = 0;
	for(int i = 1; i < 100005; i++) {
		z[i][0] = z[i - 1][1] + x[i];
		z[i][1] = max(z[i - 1][0], z[i - 1][1]);
	}

	printf("%I64d", max(z[100004][0], z[100004][0]));
	
	return(0);
}

// by Kim Andrey