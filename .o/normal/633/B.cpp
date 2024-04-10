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
typedef pair<ll, ll> pll;

#define debug(format, ...) printf(format, __VA_ARGS__);

int M;
vector<int> vec;

int main() {
	scanf("%d", &M);
	for(int i = 1; i <= (int)2e6; i++) {
		int z = 0;
		for(int p = 5; p <= i; p *= 5) 
			z += i / p;
		if(z == M) vec.push_back(i);
	}

	printf("%lu\n", vec.size());
	for(auto x : vec) printf("%d ", x);

    return 0;
}