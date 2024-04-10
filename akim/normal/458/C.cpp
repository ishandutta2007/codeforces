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

vector<int> c[100100];
int sum;

bool check(int m) {
	sum = 0;
	vector<int> vc; int k = c[0].size();
	for(int i = 1; i < 100100; i++) {
		int sz = c[i].size(), f;
		for(f = 0; f <= sz - m; f++) {
			sum += c[i][f]; k++;
		}
		for(; f < sz; f++) {
			vc.pb(c[i][f]);
		}
	}
	if(k > m) {return(0);}
	sort(vc.begin(), vc.end());
	for(int i = 0; i < m - k; i++) {
		sum += vc[i];
	}
	return(1);
}

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	
	int n, i, mx = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		c[a].pb(b);
		if(a > 0) {mx = max(mx, (int)c[a].size());}
	}

	if(c[0].size() > mx) {printf("0"); return(0);}

	for(i = 1; i < 100100; i++) {
     	sort(c[i].begin(), c[i].end());
	}
	
	int l = c[0].size(), r = n;
	while(l + 1 < r) {
		int m = (l + r) / 2;
		if(check(m)) {
			r = m;
		} else {
			l = m;
		}
	}
	l = r; r = n;
	while(l + 2 < r) {
		int m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;
		check(m1);
		int c1 = sum;
		check(m2);
		int c2 = sum;
		if(c1 < c2) {
			r = m2;
		} else {
			l = m1;
		}
	}
	int ssum = mod;
	check(l);
	ssum = min(ssum, sum);
	check(min(l + 1, n));
	ssum = min(ssum, sum);
	check(min(l + 2, n));
	ssum = min(ssum, sum);
	printf("%d", ssum);
	
	return(0);
}

// by Kim Andrey