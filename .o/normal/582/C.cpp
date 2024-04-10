
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

const int N_ = 200539;
int N, A[N_], G[N_];

int best[N_];
int add[N_];
bool good[N_];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("582C.in", "r", stdin);
    freopen("582C.out", "w", stdout);
#endif
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", A + i);
        if (i > 0) G[i] = gcd(i, N);
    }
    G[N] = N;

    ll ans = 0;

    for (int d = 1; d < N; d++) if (N % d == 0) {
        fill(best, best + N, 0);
        fill(good, good + N, false);
        fill(add, add + N, 0);

        for (int i = 0; i < N; i++) best[i%d] = max(best[i % d], A[i]);
        for (int i = 0; i < N; i++) if (A[i] >= best[i % d]) good[i] = true;

        int p = N;
        while (p > 0 && good[--p]);
        if (!good[p]) {
            for (int i = 0, k = 0; i < N; i++) if (good[(i + p) % N]) ++add[++k]; else k = 0;

            int sum = 0;
            for (int i = N - 1; i > 0; i--) {
                sum += add[i];
                if (G[i] == d) ans += sum;
            }
        }
        else {
            for (int i = 0; i < N; i++) if (G[i] == d) ans += N;
        }
    }

    printf("%lld\n", ans);
    return 0;
}