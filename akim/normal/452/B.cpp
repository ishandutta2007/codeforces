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
	
	int n, m;
	scanf("%d%d", &n, &m);
	if(n == 0) {
		printf("%d %d\n%d %d\n%d %d\n%d %d\n", 0, 1, 0, m, 0, 0, 0, m - 1);
		return(0);
	}
	if(m == 0) {
		printf("%d %d\n%d %d\n%d %d\n%d %d\n", 1, 0, n, 0, 0, 0, n - 1, 0);
		return(0);
	}
	if(n > m)	{
		if(sqrt(sqr(n) + sqr(m - 1)) * 2 + sqrt(sqr(n) + sqr(m)) < sqrt(sqr(n) + sqr(m)) * 2 + n) {
			printf("%d %d\n%d %d\n%d %d\n%d %d\n", 0, 0, n, m, 0, m, n, 0);
		} else {
			printf("%d %d\n%d %d\n%d %d\n%d %d\n", 0, 1, n, m, 0, 0, n, m - 1);
		}
	} else {
		if(sqrt(sqr(n - 1) + sqr(m)) * 2 + sqrt(sqr(n) + sqr(m)) < sqrt(sqr(n) + sqr(m)) * 2 + m) {
			printf("%d %d\n%d %d\n%d %d\n%d %d\n", 0, 0, n, m, n, 0, 0, m);
		} else {
			printf("%d %d\n%d %d\n%d %d\n%d %d\n", 1, 0, n, m, 0, 0, n - 1, m);
		}
	}
	
	return(0);
}

// by Kim Andrey