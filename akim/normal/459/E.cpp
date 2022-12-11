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

vector<pair<int, pair<int, int> > > rb;

int bo[300300];

vector<pair<int, int> > vc;

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	
	int n, m, i;
	scanf("%d%d", &n, &m);
	for(i = 0; i < m; i++) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		rb.pb(mp(c, mp(u, v)));
	}
	
	sort(rb.begin(), rb.end());

	int otv =  0;
	for(i = 0; i < m; i++) {
		int u = rb[i].sc.fs, v = rb[i].sc.sc, c = rb[i].fs;
		if(i > 0 && rb[i - 1].fs < c)
			while(!vc.empty()) {
				int u = vc.back().fs, o = vc.back().sc;
				bo[u] = max(bo[u], o);
				vc.ppb();
				otv = max(otv, bo[u]);
			}
		vc.pb(mp(v, bo[u] + 1));
	}
	while(!vc.empty()) {
		int u = vc.back().fs, o = vc.back().sc;
		bo[u] = max(bo[u], o);
		vc.ppb();
		otv = max(otv, bo[u]);
	}

	printf("%d", otv);
	
	return(0);
}

// by Kim Andrey