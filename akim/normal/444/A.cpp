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

double p[550];

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	
	
	int n, m, i;
	double lo = 0;
	scanf("%d%d", &n, &m);
	for(i = 0; i < n; i++) {
		scanf("%lf", &p[i + 1]);
	}
	for(i = 0; i < m; i++) {
		int u, v;
		double c; scanf("%d%d%lf", &u, &v, &c);
		if((p[u] + p[v]) / c > lo) {
			lo = (p[u] + p[v]) / c;
		}
	}

	printf("%.12lf", lo);
	
	return(0);
}

// by Kim Andrey