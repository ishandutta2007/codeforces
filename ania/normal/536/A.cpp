#include<algorithm>
#include<bitset>
#include<cctype>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

int A,B;

bool ok(int l, int r, int t, int m) {
	int n = r-l+1;
	long long sum = 0;
	if (A+(r-1)*B > t) return false;
	sum = 1LL*n*(A-B) + 1LL*(r+l)*n*B/2;
	int mm = min(m, n);
	if (sum <= 1LL*mm*t) return true;
	return false;
}

int test() {
	int l,t,m;
	scanf("%d%d%d", &l, &t, &m);
	int low = l-1, high = (t-A)/B+3;
	while (low+1<high) {
		int r = (low+high)/2;
		if (ok(l,r,t,m)) low = r;
		else high = r;
	}
	if (high<=l) return -1;
	return low;
}

int main() {
	int tt;
	scanf("%d%d%d", &A, &B, &tt);
	while (tt--) {
		printf("%d\n", test());
	}
	return 0;
}