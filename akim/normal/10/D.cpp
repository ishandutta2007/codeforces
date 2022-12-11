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
const int maxn = 510;

int dp[maxn][maxn];
int prv[maxn][maxn];
int a[maxn], b[maxn];
vector<int> vc;

int main() {

	#ifdef SOL
	{
//		freopen("input.txt", "r", stdin);
//		freopen("output.txt", "w", stdout);
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

	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}

	int bans = 0, posx = -1, posy = -1;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i] == b[j]) {
				int &ans = dp[i][j];
				ans = 1;
				int bst = 0;
				int fr = -1;
				if(j - 1 >= 0)
				for(int k = 0; k < i; k++) {
					if(a[k] < a[i] && bst < dp[k][j - 1]) {
						bst = dp[k][j - 1];
						fr = k;
					}
				}
				ans += bst;
				prv[i][j] = fr;

				if(bans < ans) {
					bans = ans;
					posx = i, posy = j;
				}

			}
			if(dp[i][j + 1] < dp[i][j]) {
				dp[i][j + 1] = dp[i][j];
				prv[i][j + 1] = prv[i][j];
			}
		}
	}

	cout << bans << endl;

	while(!(posx == -1)) {
		vc.pb(a[posx]);
		int ii = prv[posx][m - 1];
		posx = ii;
	}

	reverse(vc.begin(), vc.end());
	for(int i = 0; i < (int)vc.size(); i++) {
		cout << vc[i] << " ";
	}

	#ifdef SOL
	{
		fflush(stdout);
		fprintf(stderr, "%.3lf ms\n", 1000. * clock() / CLOCKS_PER_SEC);
		fflush(stderr);
	}
	#endif
	return(0);
}

// by Andrey Kim