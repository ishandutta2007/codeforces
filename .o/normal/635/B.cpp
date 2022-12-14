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

const int N_ = 200500;
int N;
vector<int> a, b;

int main() {
	scanf("%d", &N); 
	for(int i = 0; i < N; i++) {
		int v; scanf("%d", &v);
		if(v > 0) a.push_back(v);
	}
	for(int i = 0; i < N; i++) {
		int v; scanf("%d", &v);
		if(v > 0) b.push_back(v);
	}

	rotate(a.begin(), min_element(a.begin(), a.end()), a.end());
	rotate(b.begin(), min_element(b.begin(), b.end()), b.end());

	puts(a == b ? "YES" : "NO");
    return 0;
}