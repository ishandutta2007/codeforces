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
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;

const int N_ = 405, K_ = 55;

int N, K, A[50000]; ll S[N_];
ll tn[K_][N_], tp[K_][N_]; // +, -
ll res = -1;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d%d", &N, &K);
    for(int i = 1; i <= N; i++) scanf("%d", A + i), S[i] = S[i-1] + A[i];
    
    for(int k = 1; k <= K; k++) {
        for(int i = k; i <= N; i++) tp[k][i] = tn[k][i] = -(ll)1e10;
    }
    
    { //  
        ll mn = 0, mx = 0;
        for(int i = 1; i <= N; i++) {
            tp[1][i] = S[i] - mn;
            tn[1][i] = mx - S[i];
            mn = min(mn, S[i]);
            mx = max(mx, S[i]);
            //printf("%d %d : %lld %lld\n",1,i,tp[1][i],tn[1][i]);
        }
    }
    
    for(int k = 2; k < K; k++) {
        for(int i = k; i <= N; i++) {
        ll t  = -(ll)1e18,v = -(ll)1e18;
            for(int p = k; p <= i; p++) {
                t = max(t, tn[k-1][p-1]);
                v = max(v, tp[k-1][p-1]);
                tp[k][i] = max(t + (S[i] - S[p-1]) * 2, tp[k][i]);
                tp[k][i] = max(v, tp[k][i]);
                tn[k][i] = max(v + (S[p-1] - S[i]) * 2, tn[k][i]);
                tn[k][i] = max(t, tn[k][i]);
            }
            //printf("%d %d : %lld %lld\n",k,i,tp[k][i],tn[k][i]);
        }
    }
    
    // tp[K][i] = ~ ) + S[i] - S[?]
                // (k-1)
    
    for(int i = K; i <= N; i++) {
        for(int p = K-1; p < i; p++) {
            res = max(res, max(tp[K-1][p] + (S[p] - S[i]), tn[K-1][p] + (S[i] - S[p])));
        }
    }
    
    printf("%lld\n", res);
    
    
    return 0;
}