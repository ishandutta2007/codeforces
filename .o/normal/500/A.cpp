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

const int N_ = 30500;

int N, T, A[N_];

int main() {
    scanf("%d%d", &N, &T);
    for(int i = 1; i < N; i++) {
        scanf("%d", &A[i]);
    }
    A[N] = 1;
    for(int cur = 1; cur <= N; cur += A[cur]) {
        if(cur == T) return 0 & puts("YES");
    }
    
    puts("NO");
    return 0;
}