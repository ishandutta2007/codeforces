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

int main() {
	scanf("%d", &N);
	vector<int> vec;//12321212
	for(int i = 1; i <= N; i++) {
		int cur = 1;
		while(!vec.empty() && vec.back() == cur) {
			++cur;
			vec.pop_back();
		}
		vec.push_back(cur);
	}
	for(auto x : vec) printf("%d ", x);
    return 0;
}