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

int n,L[10], R[10];
lf tp[50][10500];
lf sp[50][10500];
lf tb[50][10500];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d%d", L+i, R+i);
    
    for(int x = 1; x <= 10000; x++) {
        for(int state = 0; state < (1<<n); state++) {
            
            lf &s = sp[state][x]; s = 1;
            for(int i = 0; i < n; i++) if((state >> i) & 1) {
                if(L[i] <= x && x <= R[i]) s *= 1. / (R[i] - L[i] + 1);
                else { s = 0; break; }
            }
            
            lf &t = tp[state][x]; t = 1;
            for(int i = 0; i < n; i++) if((state >> i) & 1) {
                t *= (lf) max(min(R[i], x) - L[i] + 1, 0) / (R[i] - L[i] + 1);
            }
            
            tb[state][x] = tb[state][x-1];
            tb[state][x] += x * (tp[state][x] - tp[state][x-1]);
        }
    }
    
    lf res = tb[(1<<n)-1][1];
    for(int x = 2; x <= 10000; x++) {
        for(int state = 1; state < (1<<n); state++) {
            int op = state ^ ((1 << n) - 1);
            if(state == (state & -state)) res += sp[state][x] * tb[op][x-1];
            else res += x * sp[state][x] * tp[op][x-1];
        }
    }
    
    printf("%.20lf\n", res);
    return 0;
}