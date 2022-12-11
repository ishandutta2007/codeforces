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

priority_queue<pair<int, int> > q;
map<int, int> ma;
map<int, int>::iterator it;
vector<pair<pair<int, int>, int> > vc;

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);

	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int c;
		scanf("%d", &c);
		if(ma.count(c) == 0) {ma[c] = 1;} else {ma[c]++;}
	}
	for(it = ma.begin(); it != ma.end(); it++) {
		q.push(mp((*it).sc, (*it).fs));
	}

	while(q.size() > 2) {
		pair<int, int> p1 = q.top(); q.pop();
		pair<int, int> p2 = q.top(); q.pop();
		pair<int, int> p3 = q.top(); q.pop();
		p1.fs--; p2.fs--; p3.fs--;
		int x[3] = {p1.sc, p2.sc, p3.sc};
		sort(&x[0], &x[3]);
		vc.pb(mp(mp(x[2], x[1]), x[0]));
		if(p1.fs > 0) {q.push(p1);}
		if(p2.fs > 0) {q.push(p2);}
		if(p3.fs > 0) {q.push(p3);}
	}

	printf("%d\n", (int)vc.size());
	for(int i = 0; i < (int)vc.size(); i++) {
		printf("%d %d %d\n", vc[i].fs.fs, vc[i].fs.sc, vc[i].sc);
	}

	return(0);
}

// by Kim Andrey