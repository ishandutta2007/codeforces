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

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int N_ = 200005, lgN_ = 20;
char S[N_], T[N_]; int N;


int main() {
#ifndef ONLINE_JUDGE
    freopen("E.in", "r", stdin);
    freopen("E.out", "w", stdout);
#endif

    scanf("%d%s%s", &N, S + 1, T + 1); //N = strlen(S + 1);

    int p = N, q = -1;
    for (int i = 1; i <= N; i++) {
        if (S[i] != T[i]) p = min(p, i), q = max(q, i);
    }

    int ans = 0;

    if (p == q) ans = 2;
    else {
        int cnt1 = 1, cnt2 = 1;
        for (int i = p; i <= q - 1; i++) if (S[i] != T[i + 1]) cnt1 = 0;
        for (int i = p; i <= q - 1; i++) if (S[i + 1] != T[i]) cnt2 = 0;
        ans = cnt1 + cnt2;
    }

    printf("%d\n", ans);
    return 0;
}