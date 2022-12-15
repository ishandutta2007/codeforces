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

int N;
bool C[100];

int main() {
	scanf("%d", &N);
	while(N--) {
		int t; scanf("%d", &t);
		C[t] = 1;
	}

	int con = 0;
	for(int i = 1; i <= 90; i++) {
		if(!C[i]) ++con; else con = 0;
		if(con == 15) {
			return 0 & printf("%d\n", i);
		}
	}

	printf("%d\n", 90);
    return 0;
}