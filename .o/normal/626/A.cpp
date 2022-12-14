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

#define debug(format, ...) printf(format, __VA_ARGS__);

int N;
char S[505];
int ans; 

int main() {
	scanf("%d%s", &N, S);
	for(int i = 0; i < N; i++) {
		int dx = 0, dy = 0;
		for(int j = i; j < N; j++) {
			if(S[j] == 'U') --dx; else if(S[j] == 'D') ++dx;
			if(S[j] == 'L') --dy; else if(S[j] == 'R') ++dy;
			if(dx == 0 && dy == 0) ++ans;
		}
	}
	printf("%d\n",ans);
    return 0;
}