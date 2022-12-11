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

int x[350][350], z[350], o[350];

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);

	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		for(int f = 0; f < n; f++) {
			scanf("%d", &x[i][f]);
		}
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &z[i]);
	}
	for(int i = 0; i < n; i++) {
		for(int f = 0; f < n; f++) {
			bool ok = 1, mt = 0;
			for(int g = 0; g < n; g++) {
				if(x[i][f] == i + 1) {ok = 0; break;}
				if(z[g] == x[i][f]) {
					mt = 1;
				}
				if(!mt && z[g] != i + 1 && z[g] < x[i][f]) {
					ok = 0;
					break;
				}
			}
			if(ok) {
				o[i] = x[i][f];
				break;
			}
		}
	}

	for(int i = 0; i < n; i++) {
		printf("%d ", o[i]);
	}

	return(0);
}

// by Kim Andrey