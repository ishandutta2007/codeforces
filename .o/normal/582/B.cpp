
#define _CRT_SECURE_NO_WARNINGS

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
#include <unordered_map>
#include <unordered_set>
#include <time.h>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int N_ = 150;

int N, T;
int M;
int A[N_];

int calc(int L) {
    vector<int> tb(305);
    int ret = 1;
    for (int i = 0; i < L; i++) {
        int v = tb[A[i % N]] = *max_element(tb.begin(), tb.begin() + A[i % N] + 1) + 1;
        ret = max(ret, v);
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("582B.in", "r", stdin);
    freopen("582B.out", "w", stdout);
#endif

    scanf("%d%d", &N, &T);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    M = N * T;

    if (M <= 100000) {
        printf("%d\n", calc(M));
    }
    else {
        int a = calc(N * 501);
        int b = calc(N * 502);
        printf("%d\n", a + (b - a) * (T - 501));
    }
    
    return 0;
}