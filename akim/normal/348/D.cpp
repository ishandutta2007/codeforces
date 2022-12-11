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
const int maxn = 3300;

char c[maxn][maxn];
int dp1[maxn][maxn], dp2[maxn][maxn];

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

	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("\n");
		for(int f = 0; f < m; f++) {
			c[i][f] = getchar();
		}
	}
	if(c[0][1] != '#') dp1[0][1] = 1;
	if(c[1][0] != '#') dp2[1][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int f = 0; f < m; f++) {
			if(c[i][f] == '#') continue;
			if(i > 0) {
				dp1[i][f] += dp1[i - 1][f];
				dp1[i][f] %= mod;
				dp2[i][f] += dp2[i - 1][f];
				dp2[i][f] %= mod;
			}
			if(f > 0) {
				dp1[i][f] += dp1[i][f - 1];
				dp1[i][f] %= mod;
				dp2[i][f] += dp2[i][f - 1];
				dp2[i][f] %= mod;
			}
		}
	}

	printf("%I64d", (1ll * dp1[n - 2][m - 1] * dp2[n - 1][m - 2] % mod - 1ll * dp1[n - 1][m - 2] * dp2[n - 2][m - 1] % mod + mod) % mod);

	return(0);
}

// by Kim Andrey