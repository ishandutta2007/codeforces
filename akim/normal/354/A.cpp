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

long long sl[100100], sr[100100] ,x[100100];

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	long long n, l, r, ql, qr, i;
	scanf("%I64d%I64d%I64d%I64d%I64d", &n, &l, &r, &ql, &qr);

	for(i = 1; i <= n; i++) {
		scanf("%I64d", &x[i]);
	}
	
	for(i = 1; i <= n; i++) {
		sl[i] = sl[i - 1] + (x[i] * l);
	}

	for(i = n; i >= 1; i--) {
		sr[i] = sr[i + 1] + (x[i] * r);
	}

	long long otv = 1000ll * mod;
	for(i = 0; i <= n; i++) {
		otv = min(otv, sl[i] + sr[i + 1] + max(n - i - i - 1, 0ll) * qr + max(i - n + i - 1, 0ll) * ql);
	}
	
	cout<<otv;

	return 0;
}