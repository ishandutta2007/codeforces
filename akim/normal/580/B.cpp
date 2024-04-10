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
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

pair<ll, ll> p[maxn];

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	ll n, d;
	scanf("%I64d%I64d", &n, &d);
	for(int i = 0; i < n; i++) {
		scanf("%I64d%I64d", &p[i].fs, &p[i].sc);
	}
	sort(&p[0], &p[n]);

	ll ans = 0, mans = 0;
	for(int i = 0, f = 0; i < n; i++) {
		while(f < n && p[f].fs - p[i].fs < d) {
			ans += p[f++].sc;
		}
		mans = max(mans, ans);
		ans -= p[i].sc;
	}

	printf("%I64d", mans);

	return(0);
}

// by Kim Andrey