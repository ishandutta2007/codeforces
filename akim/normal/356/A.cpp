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
#define LL long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define forit(it,S) for(__typeof((S).begin()) it = (S).begin(); it != (S).end(); it++)
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef pair<int, int> pii;

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.0);

set<int> st;
set<int>::iterator up, lw, it;
int otv[300300] = {0};
int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	int n, m, i;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; i++) {st.insert(i);}
	for(; m > 0; m--) {
		int l, r, p;
		scanf("%d%d%d", &l, &r, &p);
		lw = st.lower_bound(l);
		up = st.upper_bound(r);
		for(it = lw; it != up; it++) {
			otv[(*it)] = p;
		}
		st.erase(lw, up);
		st.insert(p);
		otv[p] = 0;
	}
	for(i = 1; i <= n; i++) {
		printf("%d ", otv[i]);
	}
	return 0;
}