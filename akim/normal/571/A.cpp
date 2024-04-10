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

	int a, b, c, l;
	scanf("%d%d%d%d", &a, &b, &c, &l);
	ll ans = 0, all = (l + 1) * 1ll * (l + 2) * (l + 3) / 6;
	for(int la = 0; la <= l; la++) {
		int lbc = min(a - b - c + la, l - la);
		if(lbc >= 0) ans += (((lbc + 2) * 1ll * (lbc + 1)) >> 1ll);
	}
	swap(a, b);
	for(int la = 0; la <= l; la++) {
		int lbc = min(a - b - c + la, l - la);
		if(lbc >= 0) ans += (((lbc + 2) * 1ll * (lbc + 1)) >> 1ll);
	}
	swap(a, c);
	for(int la = 0; la <= l; la++) {
		int lbc = min(a - b - c + la, l - la);
		if(lbc >= 0) ans += (((lbc + 2) * 1ll * (lbc + 1)) >> 1ll);
	}
	printf("%I64d", all - ans);

	return(0);
}

// by Kim Andrey