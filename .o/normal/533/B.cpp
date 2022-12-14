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
typedef pair<ll, ll> pll;

const int N_ = 200500;

int N;

int P[N_];
vector<int> gph[N_];

pll solve(int u) {
    ll a = (ll)-1e15;
    ll b = 0;

    for (int e = 0; e < gph[u].size(); e++) {
        int v = gph[u][e];
        pll c = solve(v);
        
        ll cand_a[] = { a, a + c.first, b + c.second };
        ll cand_b[] = { b, a + c.second, b + c.first };

        a = *max_element(cand_a, cand_a + 3);
        b = *max_element(cand_b, cand_b + 3);
    }

    return pll(b, max(a, b + P[u]));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
#endif

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int a, p; scanf("%d%d", &a, P+i);
        if (a > 0) gph[a].push_back(i);
    }

    pll ans = solve(1);

    printf("%I64d\n", max(ans.first, ans.second));
    return 0;
}