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

long long pr[14] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43};

long long x[10500], sz = 0, kold = 0;

int main() {

//	freopen("*.in","r",stdin);
//	freopen("a.out","w",stdout);
	long long n, i, f, k, m;

	scanf("%I64d", &n);

	m = sqr(n) * 2;

	for(i = 0; i < 14; i++) {
		long long koldel = 0;
		x[sz] = pr[i]; sz++; kold++; koldel++;
		if(sz == n) {sz = 0;}
		for(f = 0; f < min(kold, n); f++) {
			if(sz == 1 && kold != 1) {f++;}
			if(x[f] * pr[i] <= m) {
				x[sz] = x[f] * pr[i]; sz++; kold++; koldel++;
				if(sz == n) {sz = 0;}
				if(koldel >= n - n / 2 && kold >= n) {
					break;
				}
			}
		}
		if(koldel >= n - n / 2 && kold >= n) {
			break;
		}
	}
	sort(&x[0], &x[n]);
	for(i = 0; i < n; i++) {
		cout<<x[i]<<" ";
	}
	return(0);
}

// by Kim Andrey