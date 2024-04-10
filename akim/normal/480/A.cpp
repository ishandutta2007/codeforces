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

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.0);

pair<int, int> x[5100];

int main() {

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &x[i].fs, &x[i].sc);
	}
	sort(&x[0], &x[n]);
	int day = 0;
	for(int i = 0; i < n; i++) {
		if(x[i].sc >= day) {
			day = x[i].sc;
		} else {
			day = x[i].fs;
		}
	}
	printf("%d", day);


	return(0);
}

// by Kim Andrey