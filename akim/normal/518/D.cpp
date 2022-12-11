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
const int maxn = 2020;

double dp[maxn][maxn] = {1.};

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

	int n, t;
	double p, _p;
	cin >> n >> p >> t;
	_p = 1 - p;
	double ans = 0.;
	for(int i = 0; i <= n; i++) {
		for(int f = 0; f <= t; f++) {
			if(i == n) {
				dp[i][f + 1] += dp[i][f];
			} else {
				dp[i + 1][f + 1] += dp[i][f] * p;
				dp[i][f + 1] += dp[i][f] * _p;
			}
//			cout << dp[i][f] << " ";
		}
//		cout << endl;
	}
	for(int i = 0; i <= n; i++) {
		ans += (i * 1.) * dp[i][t];
	}

printf("%.10lf", ans);

	return(0);
}

// by Kim Andrey