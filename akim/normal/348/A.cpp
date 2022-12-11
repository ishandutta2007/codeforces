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

long long x[100100] = {0};
int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	long long n, i, l=1, r=100000000000000ll, ma = 0;
	scanf("%I64d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &x[i]);
		ma = max(x[i], ma);
	}

	while(l + 1 < r) {
		long long m = (l + r) / 2, k = 0;
		for(i = 0; i < n; i++){
			k += m - x[i];
		}
		if(k >= m){r = m;} else {l = m;}
	}
	printf("%d", max(r, ma));
	return 0;
}