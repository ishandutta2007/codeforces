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

int x[3 * maxn];
int dp[5100][5100];

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

	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}

	sort(&x[0], &x[n]);

	int cx = n / k, cy = n / k + 1;
	int kx = k - (n % k), ky = n % k;
	int sum = 0;
	for(int i = 0; i < n - 1; i++) {
		sum += abs(x[i] - x[i + 1]);
	}

	for(int i = 0; i <= kx; i++) {
		for(int f = 0; f <= ky; f++) {
			{
				f++;
				int id = i * cx + f * cy;
				if(f <= ky) dp[i][f] = max(dp[i][f - 1] + abs(x[id - (id == n)] - x[id - 1]), dp[i][f]);
				f--;
			}
			{
				i++;
				int id = i * cx + f * cy;
				if(i <= kx) dp[i][f] = max(dp[i - 1][f] + abs(x[id - (id == n)] - x[id - 1]), dp[i][f]);
				i--;
			}
		}
	}

	printf("%d", sum - dp[kx][ky]);

	return(0);
}

// by Kim Andrey