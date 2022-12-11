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

	int c1 = 4, c2 = 7;
	int a1, a2, b1, b2; scanf("%d%d%d%d", &a1, &a2, &b1, &b2);

	if(b1 < b2) {swap(a1, a2); swap(b1, b2); swap(c1,c2);}

	if(b1 - b2 > 1) {printf("-1"); return(0);}
	if(b2 + 1 > a1 || b1 > a2) {
		if(b1 == b2) {
			swap(a1, a2); swap(b1, b2); swap(c1,c2);
		} else {
			printf("-1"); return(0);
		}
	}
	if(b2 + 1 > a1 || b1 > a2) {
		printf("-1"); return(0);
	}
	a1 -= b2 + 1; a2 -= b1;

	int i = -1;
	printf("%d", c1);
	if(c1 == 4) while(a1 > 0) {a1--; printf("%d", c1);}
	if(c1 == 7 && i >= b1 + b2 - 2) while(a2 > 0) {a2--; printf("%d", c2);}

	for(i = 0; i < b1 + b2; i++) {
		if(i % 2 == 0) {
			printf("%d", c2);
			if(c2 == 4) while(a2 > 0) {a2--; printf("%d", c2);}
			if(c2 == 7 && i >= b1 + b2 - 2) while(a2 > 0) {a2--; printf("%d", c2);}
		}
		if(i % 2 == 1) {
			printf("%d", c1);
			if(c1 == 4) while(a1 > 0) {a1--; printf("%d", c1);}
			if(c1 == 7 && i >= b1 + b2 - 2) while(a1 > 0) {a1--; printf("%d", c1);}
		}
	}
	if(c1 == 4) {
		while(a1 > 0) {a1--; printf("%d", c1);}
		while(a2 > 0) {a2--; printf("%d", c2);}
	}
	if(c1 == 7) {
		while(a2 > 0) {a2--; printf("%d", c2);}
		while(a1 > 0) {a1--; printf("%d", c1);}
	}

	return(0);
}

// by Kim Andrey