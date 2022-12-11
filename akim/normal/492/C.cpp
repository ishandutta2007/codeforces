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

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.0);

pair<ll, ll> a[100100];

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	const string file = "";
	if(!file.empty()) {
		freopen((file + ".in").c_str(),"r",stdin);
		freopen((file + ".out").c_str(),"w",stdout);
	}
	#endif

	ll n, r, avg, c, ans = 0;
	scanf("%I64d%I64d%I64d", &n, &r, &avg);
	c = avg * n;
	for(int i = 0; i < n; i++) {
		scanf("%I64d%I64d", &a[i].sc, &a[i].fs);
		c -= a[i].sc;
	}
	sort(a, a + n);
	for(int i = 0; i < n; i++) {
		ans += min(max(c, 0ll), r - a[i].sc) * a[i].fs;
		c -= min(max(c, 0ll), r - a[i].sc);
	}
	cout << ans;

	return(0);
}

// by Kim Andrey