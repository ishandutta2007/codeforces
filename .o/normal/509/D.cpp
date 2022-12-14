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

int N, M;
ll W[105][105];
ll CA[105][105], CB[105][105];
ll K = -1;
ll sum;

void IMPOSSIBLE() {
    puts("NO");
    exit(0);
}

ll A[105], B[105];

ll inv(ll a, ll b)
{
    ll b0 = b, t, q;
    ll x0 = 0, x1 = 1;
    if (b == 1) return 1;
    while (a > 1) {
        q = a / b;
        t = b, b = a % b, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
    if (x1 < 0) x1 += b0;
    return x1;
}

ll gcd (ll a, ll b) {
    
    return (b == 0) ? a : gcd(b, a%b);
}
int main() {
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            int c;
            scanf("%d", &c); W[i][j] = c;
            CA[i][j] = W[i][j] - W[i-1][j];
            CB[i][j] = W[i][j] - W[i][j-1];
            A[i] = B[j] = 0;
            sum += W[i][j];
        }
    }
    
    if(N == 1) {
        K = (ll)1e17;
        for(int j = 1; j <= M; j++) B[j] = W[1][j];
    }else if(M == 1) {
        K = (ll)1e17;
        for(int j = 1; j <= N; j++) A[j] = W[j][1];
    }else {
        
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                if(i == 1)CA[i][j] = W[i][j] - W[i+1][j];
                if(j == 1)CB[i][j] = W[i][j] - W[i][j+1];
            }
        }
        
        for(int i = 1; i <= N; i++) {
            ll pos = -1, neg = +1, zero = 0;
            for(int j = 1; j <= M; j++) {
                if(CA[i][j] > 0) {
                    if(pos < 0 || pos == CA[i][j])pos = CA[i][j];
                    else IMPOSSIBLE();
                } else if(CA[i][j] < 0) {
                    if(neg > 0 || neg == CA[i][j])neg = CA[i][j];
                    else IMPOSSIBLE();
                } else zero++;
            }
            if(pos > 0 && neg < 0) {
                if(K < 0) K = pos - neg;
                else if(K != pos - neg) IMPOSSIBLE();
            }
            if(zero > 0 && pos > 0) IMPOSSIBLE();
            if(zero > 0 && neg < 0) IMPOSSIBLE();
        }
        
        for(int j = 1; j <= M; j++) {
            ll pos = -1, neg = +1, zero = 0;
            for(int i = 1; i <= N; i++) {
                if(CB[i][j] > 0) {
                    if(pos < 0 || pos == CB[i][j])pos = CB[i][j];
                    else IMPOSSIBLE();
                } else if(CB[i][j] < 0) {
                    if(neg > 0 || neg == CB[i][j])neg = CB[i][j];
                    else IMPOSSIBLE();
                } else zero++;
            }
            if(pos > 0 && neg < 0) {
                if(K < 0) K = pos - neg;
                else if(K != pos - neg) IMPOSSIBLE();
            }
            if(zero > 0 && pos > 0) IMPOSSIBLE();
            if(zero > 0 && neg < 0) IMPOSSIBLE();
        }
        
        if(K < 0) K = (ll)1e17;
        
        for(int i = 2; i <= N; i++) {
            ll pos = -1, neg = +1, zero = 0;
            for(int j = 1; j <= M; j++) {
                if(CA[i][j] > 0) {
                    if(pos < 0 || pos == CA[i][j])pos = CA[i][j];
                    else IMPOSSIBLE();
                } else if(CA[i][j] < 0) {
                    if(neg > 0 || neg == CA[i][j])neg = CA[i][j];
                    else IMPOSSIBLE();
                } else zero++;
            }
            if(pos > 0 && neg < 0) {
                if(K < 0) K = pos - neg;
                else if(K != pos - neg) IMPOSSIBLE();
            }
            if(zero > 0) {
                A[i] = A[i-1];
            }else {
                if(pos < 0) pos = K+neg;
                A[i] = (A[i-1] + pos) % K;
            }
        }
        
        
        for(int j = 2; j <= M; j++) {
            ll pos = -1, neg = +1, zero = 0;
            for(int i = 1; i <= N; i++) {
                if(CB[i][j] > 0) {
                    if(pos < 0 || pos == CB[i][j])pos = CB[i][j];
                    else IMPOSSIBLE();
                } else if(CB[i][j] < 0) {
                    if(neg > 0 || neg == CB[i][j])neg = CB[i][j];
                    else IMPOSSIBLE();
                } else zero++;
            }
            if(pos > 0 && neg < 0) {
                if(K < 0) K = pos - neg;
                else if(K != pos - neg) IMPOSSIBLE();
            }
            if(zero > 0) {
                B[j] = B[j-1];
            }else {
                if(pos < 0) pos = K+neg;
                B[j] = (B[j-1] + pos) % K;
            }
        }
        
        A[1] = W[1][1];
        B[1] = (W[1][2] - B[2] - W[1][1] + K + K) % K;
        A[1] = (K + W[1][1] - B[1]) % K;
        for(int i = 2; i <= N; i++) A[i] = (A[i] + A[1]) % K;
        for(int i = 2; i <= M; i++) B[i] = (B[i] + B[1]) % K;
    }
    
    
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(W[i][j] >= K) IMPOSSIBLE();
            if(W[i][j] != (A[i]+B[j])%K) while(1);//while(1);
        }
    }
    
    puts("YES");
    printf("%lld\n", K);
    for(int i = 1; i <= N; i++) printf("%lld ", A[i]);puts("");
    for(int j = 1; j <= M; j++) printf("%lld ", B[j]);puts("");

    return 0;
}