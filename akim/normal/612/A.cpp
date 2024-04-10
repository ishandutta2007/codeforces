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

int dp[maxn], pr[maxn];
bool ok[maxn];
string s;

void rec(int n) {
	if(dp[n]) {
		rec(pr[n]);
	} else {
		return;
	}
	for(int i = pr[n]; i < n; i++) {
		printf("%c", s[i]);
	}printf("\n");

}

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

	int n, a, b;
	cin >> n >> a >> b;
	cin >> s;
	ok[0] = 1;
	for(int i = 0; i < n; i++) {
		if(!ok[i]) continue;
		dp[i + a] = dp[i] + 1;
		pr[i + a] = i;
		ok[i + a] = 1;
		dp[i + b] = dp[i] + 1;
		pr[i + b] = i;
		ok[i + b] = 1;
	}

	if(dp[n] == 0) {
		cout << -1;
		return(0);
	}

	cout << dp[n] << endl;
	rec(n);

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