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
const int maxn = 2100;

ll tp[maxn][maxn];

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

	for(int i = 0; i < maxn; i++) {
		tp[i][0] = 1;
		for(int f = 1; f <= i; f++) {
			tp[i][f] = tp[i - 1][f - 1] + tp[i - 1][f];
			tp[i][f] %= mod;
		}
	}

	ll ans = 1, sum = 0;
	int k;
	scanf("%d", &k);
	for(int i = 0; i < k; i++) {
		int c;
		scanf("%d", &c);
		sum += c;
		ans = ans * tp[sum - 1][c - 1] % mod;
	}

	printf("%I64d", ans);

	return(0);
}

// by Kim Andrey