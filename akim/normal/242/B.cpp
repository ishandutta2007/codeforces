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

	int n, ml = mod, l = mod, pos, mr = 0; scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int pl, pr;
		scanf("%d%d", &pl, &pr);
		if(pl < ml || (pl == ml && pr - pl > l)) {
			ml = pl; l = pr - pl; pos = i + 1;
		}
		if(pr > mr) {mr = pr;}
	}

	if(ml + l >= mr) {printf("%d", pos);} else {printf("-1");}

	return(0);
}

// by Kim Andrey