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

	long long mink = 1ll * mod * mod, maxk = 0;
	long long n; scanf("%I64d", &n);
	for(long long i = 1; i * i <= n; i++) {
		if(n % i != 0) {continue;}
		long long nn = n / i;
		for(long long f = 1; f * f <= nn; f++) {
			if(nn % f != 0) {continue;}
			long long c = nn / f;
			if((i + 2) * (f + 2) * (c + 1) - i * f * c < mink) {
				mink = (i + 2) * (f + 2) * (c + 1) - i * f * c;
			}
			if((i + 2) * (f + 2) * (c + 1) - i * f * c > maxk) {
				maxk = (i + 2) * (f + 2) * (c + 1) - i * f * c;
			}
			if((i + 2) * (f + 1) * (c + 2) - i * f * c < mink) {
				mink = (i + 2) * (f + 1) * (c + 2) - i * f * c;
			}
			if((i + 2) * (f + 1) * (c + 2) - i * f * c > maxk) {
				maxk = (i + 2) * (f + 1) * (c + 2) - i * f * c;
			}
			if((i + 2) * (f + 2) * (c + 2) - i * f * c < mink) {
				mink = (i + 2) * (f + 2) * (c + 2) - i * f * c;
			}
			if((i + 1) * (f + 2) * (c + 2) - i * f * c > maxk) {
				maxk = (i + 1) * (f + 2) * (c + 2) - i * f * c;
			}
		}
	}

	printf("%I64d %I64d", mink, maxk);

	return(0);
}

// by Kim Andrey