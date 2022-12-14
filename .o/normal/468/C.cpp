#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <memory.h> 
#include <math.h> 
#include <assert.h> 
#include <stack> 
#include <queue> 
#include <map> 
#include <set> 
#include <algorithm> 
#include <string> 
#include <functional> 
#include <vector> 
#include <deque> 
#include <utility> 
#include <bitset> 
#include <limits.h>  

using namespace std; 
typedef long long ll; 
typedef unsigned long long llu; 
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int L = 200;
ll A;
ll T[L+10], P[L+10];

ll solve (ll x) {
	ll ret = 0;
	ll sum = 0;
	for(ll t = (ll)1e16, p = 16; t > 0; t /= 10, --p) {
		ll n = (x / t) % 10;
		if(p > 0) {
			ret += T[p] * n;
			ret += (sum * n + n*(n-1)/2) * P[p];
		}else {
			ret += sum * (n+1);
			ret += (n*(n+1)/2);
		}
		sum += n;
	}
	return ret;
}

int main() {
	
	scanf("%I64d", &A);
	P[0] = 1; T[0] = 0;
	for(int i = 1; i <= L; i++) {
		P[i] = (P[i-1] * 10) ;
		T[i] = (T[i - 1] * 10 + P[i-1] * 45) ;
	}
		
	ll R = 0;
	for(ll i = 55; i >= 0; i--) {
		ll x = R | (1ll<<i);
		if(solve(x) <= A) R = x;
	}

	ll L = 1;
	while(1) {
		ll v = solve(R) - solve(L-1);
		if(v < A) ++R; else if(v > A)++L;
		else {
			printf("%I64d %I64d\n", L, R);
			return 0;
		}
	}
	return 0;
}