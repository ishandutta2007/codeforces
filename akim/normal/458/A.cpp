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

int x[300350], y[300350];

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	
	int i;	
	string s; getline(cin, s); int ls = s.length();
	for(i = 1; i <= ls; i++) {
		if(s[ls - i] == '1') {
			x[i] = 1;
		}
	}

	for(i = 1; i < 300300; i++) {
		if(x[i] > 0 && x[i + 1] > 0) {
			x[i + 2] += 1;
			x[i]--; x[i + 1]--;
		}
		if(x[i] >= 2) {
			x[i + 1]++;
			x[i] -= 2;
			if(i - 2 > 0)x[i - 2]++;
			i -= 3;
			i = max(0, i);
		}
	}

	getline(cin, s); ls = s.length();
	for(i = 1; i <= ls; i++) {
		if(s[ls - i] == '1') {
			y[i] = 1;
		}
	}

	for(i = 1; i < 300300; i++) {
		if(y[i] > 0 && y[i + 1] > 0) {
			y[i + 2] += 1;
			y[i]--; y[i + 1]--;
		}
		if(y[i] >= 2) {
			y[i + 1]++;
			y[i] -= 2;
			if(i - 2 > 0) y[i - 2]++;
			i -= 3;
			i = max(0, i);
		}
	}

	for(i = 300300; i >= 0 ; i--) {
		if(x[i] > y[i]) {
			printf(">");
			return(0);
		}
		if(x[i] < y[i]) {
			printf("<");
			return(0);
		}
	}
	printf("=");
	return(0);
}

// by Kim Andrey