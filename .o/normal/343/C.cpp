#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <bits/stdc++.h>
#include <limits.h>
 
using namespace std;
typedef long long ll;
typedef double lf;
typedef long double llf;
typedef unsigned long long llu;

const int M_ = 100005, N_ = 100005;

int N, M;
ll H[N_], P[M_];
ll res;

bool possible (ll t) {
    int i, j, k;
    
    for(i = 1, j = 1; i <= N && j <= M; i++) {
        if(P[j] - H[i] > t) continue;
        if(H[i] - P[j] > t) return j > M;
        if(P[j] >= H[i]) {
            while(P[j] - H[i] <= t && j <= M) ++j;
        }else {
            ll l = H[i] - P[j];
            while(P[j] <= H[i] && j <= M) ++j;
            while((((P[j] - H[i]) * 2 + l <= t) || (P[j] - H[i] + 2*l <= t)) && j <= M) ++j;
        }
    }
    
    return j > M;
}

int main() {
    int i, j, k;
    
    scanf("%d%d", &N, &M);
    for(i = 1; i <= N; i++) scanf("%I64d", H+i);
    for(i = 1; i <= M; i++) scanf("%I64d", P+i);
    
    ll left = 0, right = 1e12;
    while(left <= right) {
        ll mid = (left + right) >> 1;
        if(possible(mid)) {
            res = mid;
            right = mid - 1;
        }else {
            left = mid + 1;
        }
    }
    
    printf("%I64d\n", res);
    
    return 0;
}