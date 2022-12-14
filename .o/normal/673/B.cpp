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
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <iostream>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N_ = 100500;
const int M_ = 100500;

int N, M;
vector<int> gph[N_];

vector<int> A, B;

int main() {
	scanf("%d%d", &N, &M);
	for(int e = 1; e <= M; e++) {
		int u, v; scanf("%d%d", &u, &v);
		if(u > v) swap(u, v);
		A.push_back(u); B.push_back(v);
	}

	if(M == 0) {
		printf("%d\n", N-1);
	}else {
		int a = *max_element(A.begin(), A.end());
		int b = *min_element(B.begin(), B.end());
		printf("%d\n", max(0, b-a));	
	}
    return 0;
}