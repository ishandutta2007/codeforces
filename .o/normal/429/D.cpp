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
#include <time.h>

using namespace std; 
typedef long long ll; 
typedef unsigned long long llu; 
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int N_ = 150005;

int N, A[N_];
ll S[N_];

inline ll sq (ll v) {
	return v*v;
}

inline ll f (int x, int y) {
	return sq(x - y) + sq(S[x] - S[y]);
}

vector< pli > v1, v2;

ll solve (int l, int r) {
	ll ret = 2e18;
	if(r - l <= 5) {
		for(int i = l; i < r; i++) for(int j = i+1; j <= r; j++) ret = min(ret, f(i,j));
		return ret;
	}

	int m = (l+r) >> 1;
	ret = min(solve(l, m), solve(m+1, r));

	int w = (int)sqrt(ret);

	v1.clear(); 
	for(int i = max(m-w-1, l); i <= m; i++) v1.push_back( pli(S[i], i) );
	sort(v1.begin(), v1.end());

	v2.clear();
	for(int i = m+1; i <= m+w+1 && i <= r; i++) v2.push_back( pli(S[i], i) );
	sort(v2.begin(), v2.end());

	for(int i = 0, k = 0; i < v1.size(); i++) {
		while(k < v2.size() && v1[i].first > v2[k].first) ++k;
		for(int j = max(k-10, 0); j < k+10 && j < v2.size(); j++) ret = min(ret, f(v1[i].second, v2[j].second));
	}

	return ret;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", A+i);
		S[i] = S[i-1] + A[i];
	}/*
	srand(time(NULL));
	N = 3000;
	for(int i = 1; i <= N; i++) {
		A[i] = rand() % 20001 - 10000;
		S[i] = S[i-1] + A[i];
	}
	
	ll vv =  solve(1, N), vvv = 2e18;
	for(int i = 1; i <= N; i++) {
		for(int j = i+1; j <= N; j++) {
			vvv = min(vvv, f(i,j));
		}
	}

	printf("%lld %lld\n", vv, vvv);*/
	printf("%I64d\n", solve(1, N));
	return 0;
}