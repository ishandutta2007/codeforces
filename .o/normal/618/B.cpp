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

int N;
int P[55];
bool used[55];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			int x; scanf("%d", &x);
			P[i] = max(P[i], x);
			P[j] = max(P[j], x);
		}
	}
	for(int i = 1; i <= N; i++) {
		if(used[P[i]]) P[i] = N;
		printf("%d ", P[i]);
		used[P[i]] = true;
	}
    return 0;
}