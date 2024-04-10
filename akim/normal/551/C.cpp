#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
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

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

int n, k, a[maxn];
ll b[maxn];

bool check(ll m) {
	int cnt = 0;
	ll ost = 0;
	for(int i = 0; i < n; i++) {
		b[i] = a[i] - ost;
		while(b[i] > 0) {
			b[i] -= m - i - 1;
			if(m - i - 1 < 0) {
				return(0);
			}
			if(++cnt > k) {
				return(0);
			}
		}
		ost = max(abs(b[i]) - 1, 0ll);
	}
	return(1);
}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	srand(time(0));
	const string file = "";
	if(!file.empty()) {
		freopen((file + ".in").c_str(),"r",stdin);
		freopen((file + ".out").c_str(),"w",stdout);
	}
	#endif

	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
//	check(3);
//	return(0);
	ll l = 0, r = (ll)1e17;
	while(l + 1 < r) {
		ll m = (l + r) >> 1;
		if(check(m)) {
			r = m;
		} else {
			l = m;
		}
	}

	printf("%I64d", l + 1);


	return(0);
}

// by Kim Andrey