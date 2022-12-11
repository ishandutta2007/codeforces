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

vector<pair<int, int> > vc;

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);

	int a, b, x, y; scanf("%d%d%d%d", &a, &b, &x, &y);
	for(int i = x; i <= a; i++) {
		for(int f = y; f <= b; f++) {
			if(i > f) {
				vc.pb(mp(i, f));
			}
		}
	}

	printf("%d\n", vc.size());
	for(int i = 0; i < vc.size(); i++) {
		printf("%d %d\n", vc[i].fs, vc[i].sc);
	}

	return(0);
}

// by Kim Andrey