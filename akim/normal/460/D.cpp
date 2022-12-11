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
	
	long long l, r, k; scanf("%I64d%I64d%I64d", &l, &r, &k);
	if(k == 1) {printf("%I64d\n1\n%I64d", l, l); return(0);}
	if(k == 2) {
		if(l % 2 == 0 && l + 1 <= r) {
			printf("1\n2\n%I64d %I64d", l, l + 1);
			return(0);
		} else
		if(l % 2 == 1 && l + 2 <= r) {
			printf("1\n2\n%I64d %I64d", l + 2, l + 1);
			return(0);
		} else
		if(l < (l ^ (l + 1))) {
			printf("%I64d\n1\n%I64d", l, l); return(0);
		} else {
			printf("%I64d\n2\n%I64d %I64d", (l ^ (l + 1)), l, l + 1); return(0);
		}
	}
	if(k == 3) {
		if(l == 1) {
			printf("0\n3\n1 2 3");
			return(0);
		}
		if(l == 3) {
			printf("0\n3\n3 5 6");
			return(0);
		}

		long long k = 1;
		while(k < r) {k <<= 1;}
		if(k == r) {r--; k >>= 2;} else {k >>= 1;}
		if((r ^ k) >= l) {printf("0\n3\n%I64d %I64d %I64d", r, k, (r ^ k));return(0);}
		if((r ^ l) > l && (r ^ l) < r) {printf("0\n3\n%I64d %I64d %I64d", r, l, (r ^ l));return(0);}
		if(l % 2 == 0 && l + 1 <= r) {
			printf("1\n2\n%I64d %I64d", l, l + 1);
			return(0);
		} else
		if(l % 2 == 1 && l + 2 <= r) {
			printf("1\n2\n%I64d %I64d", l + 2, l + 1);
			return(0);
		}
	}
	if(l % 2 == 0 && l + 3 <= r) {
		printf("0\n4\n%I64d %I64d %I64d %I64d", l, l + 1, l + 2, l + 3);
		return(0);
	}
	if(l % 2 == 1 && l + 4 <= r) {
		printf("0\n4\n%I64d %I64d %I64d %I64d", l + 4, l + 1, l + 2, l + 3);
		return(0);
	}
	long long x[5] = {l, l + 1, l + 2, l + 3}, q = r - l + 1;
     long long pm[5] = {1, 0, 0, 0, 0};
     vector<long long> vc; vc.pb(l);
     long long motv = l;
	while(pm[q] == 0) {
		long long otv = 0;
		for(int i = 0; i < q; i++) {
			if(pm[i]) {otv ^= x[i];}
		}
		if(otv < motv) {
			motv = otv;
			vc.clear();
			for(int i = 0; i < q; i++) {if(pm[i] == 1) {vc.pb(x[i]);}}
		}
		pm[0]++;
		for(int i = 0; i < q; i++) {if(pm[i] > 1) {pm[i + 1]++; pm[i] = 0;}}
	}
	printf("%I64d\n", motv);
	printf("%d\n", vc.size());
	for(int i = 0; i < vc.size(); i++) {printf("%I64d ", vc[i]);}
	return(0);
}

// by Kim Andrey