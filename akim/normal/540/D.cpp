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

double dp[110][110][110];

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

	int r, s, p;
	scanf("%d%d%d", &r, &s, &p);
	dp[r][s][p] = 1.;
	for(int i = r; i >= 0; i--) {
		for(int f = s; f >= 0; f--) {
			for(int g = p; g >= 0; g--) {
				if((i == 0 && f == 0) || (f == 0 && g == 0) || (i == 0 && g == 0)) continue;
					double obver = ((g + 0.) / (i + f + g + 0.)) * ((i + 0.) / (i + f + g + 0. - 1)) + ((i + 0.) / (i + f + g + 0.)) * ((f + 0.) / (i + f + g + 0. - 1)) + ((f + 0.) / (i + f + g + 0.)) * ((g + 0.) / (i + f + g + 0. - 1));
					if(i - 1 >= 0) dp[i - 1][f][g] += (((g + 0.) / (i + f + g + 0.)) * ((i + 0.) / (i + f + g + 0. - 1))) / obver * dp[i][f][g];
					if(f - 1 >= 0) dp[i][f - 1][g] += (((i + 0.) / (i + f + g + 0.)) * ((f + 0.) / (i + f + g + 0. - 1))) / obver * dp[i][f][g];
					if(g - 1 >= 0) dp[i][f][g - 1] += (((f + 0.) / (i + f + g + 0.)) * ((g + 0.) / (i + f + g + 0. - 1))) / obver * dp[i][f][g];
//					double val = dp[i][f][g];
//					dp[i][f][g] = 0;
//					dp[i][f][g] += ((i + 0.) / (i + f + g + 0.)) * ((i + 0. - 1) / (i + f + g + 0. - 1)) * val;
//					dp[i][f][g] += ((f + 0.) / (i + f + g + 0.)) * ((f + 0. - 1) / (i + f + g + 0. - 1)) * val;
//					dp[i][f][g] += ((g + 0.) / (i + f + g + 0.)) * ((g + 0. - 1) / (i + f + g + 0. - 1)) * val;
			}
		}
	}
	double ansr = 0., anss = 0., ansp = 0.;
	for(int i = 1; i <= 100; i++) {
		ansr += dp[i][0][0];
		anss += dp[0][i][0];
		ansp += dp[0][0][i];
	}

	printf("%.10lf %.10lf %.10lf\n", ansr, anss, ansp);

	return(0);
}

// by Kim Andrey