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

int x[100100];
int n, m, w;

bool can(int u) {
	vector<pair<int, int> > vc;
	int dob = 0, q = 0, v = 0;
	for(int i = 0; i < n; i++) {
		if(q < vc.size() && vc[q].fs == i) {
			dob -= vc[q].sc;
			q++;
		}
		if(x[i] + dob < u) {
			vc.pb(mp(i + w, u - dob - x[i]));
			v += u - dob - x[i];
			dob += u - dob - x[i];
			if(v > m) {
				return(0);
			}
		}
	}
	return(1);
}

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	
	int mn = mod;
	scanf("%d%d%d", &n, &m, &w);
	for(int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
		mn = min(mn, x[i]);
	}
	int l = mn, r = mn + m + 10;
	while(l + 1 < r) {
		int mid = (l + r) / 2;
		if(can(mid)) {l = mid;} else {r = mid;}
	}
	printf("%d", l);
	
	return(0);
}

// by Kim Andrey