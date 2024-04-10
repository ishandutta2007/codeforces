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

long long x[1001000] = {0}, z[1001000] = {0};

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	long long i, f, n, m, mi = mod;
	scanf("%I64d%I64d", &n, &m);
	for(i = 0; i < n; i++) {
		scanf("%I64d", &z[i]);
		mi = min(mi, z[i]);
		x[max(z[i] - m, 1ll)]++;
		x[z[i] + 1]--;
	}
	sort(&z[0], &z[n]);
	for(i = 1; i < 1001000; i++) {
		x[i] += x[i-1];
	}
	long long otv = 1;
	for(i = 2; i <= mi; i++) {
		long long k = 0;
		for(f = i; f < 1001000; f += i) {
			k += x[f];
		}
		if(k >= n) {otv = i;}
	}
	printf("%I64d", otv);
	return 0;
}