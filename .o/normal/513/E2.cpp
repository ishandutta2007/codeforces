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

const int N_ = 30505, K_ = 205;

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
        ll MP, MN, A, B, C, D;
        MP = MN = A = B = C = D = -(ll)1e10;
        for(int i = k; i <= N; i++) {
            MP = max(MP, tp[k-1][i-1]);
            MN = max(MN, tn[k-1][i-1]);
            A = max(A, MN - S[i-1] * 2);
            B = max(B, MP);
            C = max(C, MP + S[i-1] * 2);
            D = max(D, MN);
            tp[k][i] = max(max(A + S[i]*2, B), tp[k][i]);
            tn[k][i] = max(max(C - S[i]*2, D), tn[k][i]);
        }
    }
    
    ll A, B;
    A = B = -(ll)1e10;
    
    for(int i = K; i <= N; i++) {
        A = max(A, tp[K-1][i-1] + S[i-1]);
        B = max(B, tn[K-1][i-1] - S[i-1]);
        res = max(res, max(A - S[i], B + S[i]));
        /*for(int p = K-1; p < i; p++) {
            res = max(res, max(tp[K-1][p] + (S[p] - S[i]), tn[K-1][p] + (S[i] - S[p])));
        }*/
    }
    
    printf("%lld\n", res);
    
    
    return 0;
}