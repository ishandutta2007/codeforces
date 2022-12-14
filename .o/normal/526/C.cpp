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

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

ll solve(ll C, ll H_R, ll H_B, ll W_R, ll W_B) {
    ll ret = 0;

    if (W_R > (ll)3e4) {
        for (ll n = 0; n * W_R <= C; n++) {
            ret = max(ret, n * H_R + ((C - n * W_R) / W_B) * H_B);
        }
    }
    else {
        for (ll m = 0; m < W_R; m++) if (m * W_B <= C) {
            ret = max(ret, m * H_B + ((C - m * W_B) / W_R) * H_R);
        }
    }

    return ret;
}

int main() {

    ll C, H_R, H_B, W_R, W_B;
    scanf("%I64d%I64d%I64d%I64d%I64d", &C, &H_R, &H_B, &W_R, &W_B);
    printf("%I64d\n", max(solve(C, H_R, H_B, W_R, W_B), solve(C, H_B, H_R, W_B, W_R)));
    return 0;
}