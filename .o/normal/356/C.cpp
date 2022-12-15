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

int N;
int sum;
int Count[10];
int res = 987654321;

int P[10], L[10];
bool chk;

int main() {
	int i, j, k;

	scanf("%d", &N);

	for(i = 1; i <= N; i++) {
		int x; scanf("%d", &x);
		x = 4-x;
		++Count[x]; sum += x;
	}

	for(k = 0; 4*k <= sum; k++) if(sum - 3*k <= N) {
		for(i = 0; i <= 4; i++) P[i] = Count[i];

		L[0] = N - sum + 3*k;
		L[1] = sum - 4*k;
		L[2] = 0;
		L[3] = 0;
		L[4] = k;

		int ret = 0, x = 0, y = 0;

		while(1) {
			while(x <= 4 && !P[x]) ++x;
			while(y <= 4 && !L[y]) ++y;
			if(x > 4 || y > 4) break;

			int s = min(P[x], L[y]);
			P[x] -= s;
			L[y] -= s;
			ret += s * abs(x - y);
		}

		res = min(res, ret / 2); chk = true;
	}

	printf("%d", chk ? res : -1);

	return 0;
}