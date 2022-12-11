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

int x[1000100], z[4000100], k = 1048579;
pair<int, int> p1[1000100], p2[1000100];
map<int, int> st;

long long sum(int l, int r = k * 2 - 1000) {
	int otv = 0;
	l += k;
	while(l < r) {
		if(l & 1) {otv += z[l++];}
		if(!(r & 1)) {otv += z[r--];}
		l >>= 1; r >>= 1;
	}
	if(l == r) {
		otv += z[l];
	}
	return(otv);
}

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}

	st.clear();
	for(int i = 0; i < n; i++) {
		if(st.count(x[i])) {
			p1[i] = mp(++st[x[i]], i);
		} else {
			st[x[i]] = 1;
			p1[i] = mp(1, i);
		}
	}

	st.clear();
	for(int i = n - 1; i >= 0; i--) {
		if(st.count(x[i])) {
			p2[i] = mp(++st[x[i]], i);
		} else {
			st[x[i]] = 1;
			p2[i] = mp(1, i);
		}
	}

	sort(&p1[0], &p1[n]);
	sort(&p2[0], &p2[n]);

	long long otv = 0, f = 0;
	for(int i = 0; i < n; i++) {
		if(p2[f].fs < p1[i].fs) {
			for(; f < i; f++) {
				int p = p2[f].sc + k;
				z[p] = 1; p >>= 1;
				while(p > 0) {z[p] = z[p * 2] + z[p * 2 + 1]; p >>= 1;}
			}
		}
		otv += sum(p1[i].sc + 1);
	}

	printf("%I64d", otv);
	
	return(0);
}

// by Kim Andrey