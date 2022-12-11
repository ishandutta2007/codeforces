#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
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

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.0);



int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	
	int n, m; scanf("%d%d", &m, &n);
	double otv = 0, koef = 0;
	for(int i = 1; i <= m; i++) {
		koef = pow(((i * 1.0) / (m * 1.0)), (n * 1.0)) - pow((((i - 1) * 1.0) / (m * 1.0)), (n * 1.0));
		otv += (i * 1.0) * abs(koef);
//		printf("%.6lf\n", pow(((i * 1.0) / (m * 1.0)), (n * 1.0)));
	}
	printf("%.8lf", abs(otv));
	
	return(0);
}

// by Kim Andrey