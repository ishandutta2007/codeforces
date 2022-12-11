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

	int n; scanf("%d", &n);
	if(n < 4) {
		printf("NO");
		return(0);
	}
	if(n % 4 == 0) {
		printf("YES\n");
		printf("1 * 2 = 2\n");
		printf("2 * 3 = 6\n");
		printf("6 * 4 = 24\n");
		for(int i = 1; i < n / 4; i++) {
			printf("%d - %d = -1\n", i * 4 + 1, i * 4 + 2);
			printf("%d - %d = 1\n", i * 4 + 4, i * 4 + 3);
			printf("1 + -1 = 0\n");
			printf("24 + 0 = 24\n");
		}
	}
	if(n % 4 == 1) {
		printf("YES\n");
		printf("3 * 5 = 15\n");
		printf("2 * 4 = 8\n");
		printf("15 + 8 = 23\n");
		printf("23 + 1 = 24\n");
		for(int i = 1; i < n / 4; i++) {
			printf("%d - %d = -1\n", i * 4 + 2, i * 4 + 3);
			printf("%d - %d = 1\n", i * 4 + 5, i * 4 + 4);
			printf("1 + -1 = 0\n");
			printf("24 + 0 = 24\n");
		}
	}
	if(n % 4 == 2) {
		printf("YES\n");
		printf("6 * 4 = 24\n");
		printf("1 * 2 = 2\n");
		printf("2 + 3 = 5\n");
		printf("5 - 5 = 0\n");
		printf("24 - 0 = 24\n");
		for(int i = 1; i < n / 4; i++) {
			printf("%d - %d = -1\n", i * 4 + 3, i * 4 + 4);
			printf("%d - %d = 1\n", i * 4 + 6, i * 4 + 5);
			printf("1 + -1 = 0\n");
			printf("24 + 0 = 24\n");
		}
	}
	if(n % 4 == 3) {
		printf("YES\n");
		printf("1 - 2 = -1\n");
		printf("-1 + 3 = 2\n");
		printf("2 + 4 = 6\n");
		printf("6 + 5 = 11\n");
		printf("11 + 6 = 17\n");
		printf("17 + 7 = 24\n");
		for(int i = 1; i < n / 4; i++) {
			printf("%d - %d = -1\n", i * 4 + 4, i * 4 + 5);
			printf("%d - %d = 1\n", i * 4 + 7, i * 4 + 6);
			printf("1 + -1 = 0\n");
			printf("24 + 0 = 24\n");
		}
	}


	return(0);
}

// by Kim Andrey