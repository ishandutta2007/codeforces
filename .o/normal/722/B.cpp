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

int N;
int P[105];
char line[1050];
bool good[1050];
int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", P+i);
	scanf("\n");

	good['a'] = true;
	good['e'] = true;
	good['i'] = true;
	good['o'] = true;
	good['u'] = true;
	good['y'] = true;
	for(int i = 1; i <= N; i++) {
		gets(line);
		int len = strlen(line), cnt=0;
		for(int i = 0; i < len; i++) {
			if(good[line[i]]) cnt++;
		}
		if(P[i] != cnt) return 0 & puts("NO");
	}
	puts("YES");
    return 0;
}