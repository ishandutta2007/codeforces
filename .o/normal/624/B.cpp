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
#include <functional>
#include <numeric>
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define debug(format, ...) printf(format, __VA_ARGS__);

const int N_ = 50;
int N, A[N_];

int main() {
	scanf("%d", &N);
	for(int i = 0;i < N;i++)scanf("%d",A+i);
	sort(A,A+N,[](const int &a, const int &b){return a>b; });
	
	set<int> S; S.insert(A[0]);
	ll ans = A[0];
	for(int i = 1; i < N; i++) {
		while(S.find(A[i]) != S.end()) A[i]--;
		ans += A[i];
		S.insert(A[i]);
		S.erase(0);
	}

	printf("%lld\n",ans);
	return 0;
}