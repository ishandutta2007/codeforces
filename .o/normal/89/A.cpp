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

int N; ll M, K;
int A[10500];



int main() {
    scanf("%d%lld%lld", &N, &M, &K);
    
    if(N % 2 == 0) return 0 & puts("0");
    
    for(int i = 1; i <= N; i++) scanf("%d", A+i);
    
    int c = (N + 1) / 2;
    int m = (int)1e6;
    for(int i = 1; i <= N; i += 2) {
        m = min(m, A[i]);
    }
    
    printf("%lld\n", min(K * (M/c), (ll)m));
    return 0;
}