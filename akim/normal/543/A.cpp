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
//const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

ll dp[1100][1100];

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

	dp[0][0] = 1;
	int n, m, b, mod;
	scanf("%d%d%d%d", &n, &m, &b, &mod);
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		for(int f = 0; f <= m; f++) {
			for(int g = 0; g <= b; g++) {
				dp[f][g] %= mod;
				dp[f + 1][g + x] = dp[f + 1][g + x] + dp[f][g];
			}
		}
	}
	ll ans = 0;
	for(int i = 0; i <= b; i++) {
		ans += dp[m][i];
	}

	printf("%I64d", ans % mod);

	return(0);
}

// by Kim Andrey