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

char c[21][21];
int a[21][21];
int fixm[21][21];
int fix[21][21];
int dp[(1 << 20) + 1000];
bool pm[(1 << 20) + 1000];
vector<int> imp, nxt;

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
	for(int i = 0; i < n; i++) {
		for(int f = 0; f < m; f++) {
			scanf("%d", &a[i][f]);
		}
	}

	for(int i = 0; i < n; i++) {
		for(int f = 0; f < m; f++) {
			int cst = -a[i][f], mask = 0;
			for(int g = 0; g < n; g++) {
				cst += (c[i][f] == c[g][f]) * a[g][f];
				mask |= (c[i][f] == c[g][f]) * (1 << g);
			}
			fix[i][f] = cst;
			fixm[i][f] = mask;
		}
	}
	int mm = 1 << n;
	imp.pb(0);
	for(int g = 0; g < mm; g++) {
		for(int i = 0; i < n; i++) {
			int nx = g | (1 << i);
			for(int f = 0; f < m; f++) {
				if(!pm[nx]) {
					dp[nx] = dp[g] + a[i][f];
					pm[nx] = 1;
				} else {
					dp[nx] = min(dp[nx], dp[g] + a[i][f]);
				}
				int nx = g | fixm[i][f];
				if(!pm[nx]) {
					dp[nx] = dp[g] + fix[i][f];
					pm[nx] = 1;
				} else {
					dp[nx] = min(dp[nx], dp[g] + fix[i][f]);
				}
			}
		}
	}
	printf("%d", dp[(1 << n) - 1]);


	return(0);
}

// by Kim Andrey