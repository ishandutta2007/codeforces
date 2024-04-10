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

const int N_ = 2050;
const int MAXA = 10050;

int N, A[N_];
ll tb[MAXA];
ll freq[MAXA];
double ans;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", A+i);
	sort(A+1, A+N+1);
	
	for(int i = 1; i <= N; i++) 
		for(int j = i+1; j <= N; j++) 
			++freq[A[j] - A[i]];

	for(int i = 0; i <= MAXA; i++) 
		for(int j = 0; j <= i; j++) tb[i] += freq[j] * freq[i-j];

	ll sum = 0;
	for(int i = 0; i <= MAXA; i++) {
		ans += sum * freq[i];
		sum += tb[i];
	}

	ll v = N*(N-1)/2;
	ans /= v;
	ans /= v;
	ans /= v;

	printf("%.30lf\n", ans);

    return 0;
}