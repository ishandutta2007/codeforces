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
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;

const int N_ = 20050, M_ = 20050;
int N, M, P, X[N_], Y[M_];
int f(int a, int b) { return (X[a] + Y[b]) % P; }

string str;
int tb1[2][M_], tb2[2][M_];

int solve(int u, int d, int l, int r) {
    int ret = 0;
    if (u == d) {
        for (int j = l; j <= r; j++) {
            ret += f(u, j);
            if(j  < r) str.push_back('S');
        }
    }
    else {
        for (int j = max(l - 2, 0); j <= r + 2; j++) tb1[0][j] = tb1[1][j] = tb2[0][j] = tb2[1][j] = 0;
        int m = (u + d) >> 1;
        for (int i = u; i <= m; i++) {
            for (int j = l; j <= r; j++) tb1[i & 1][j] = max(tb1[~i & 1][j], tb1[i & 1][j - 1]) + f(i, j);
        }
        for (int i = d; i >= m+1; i--) {
            for (int j = r; j >= l; j--) tb2[i & 1][j] = max(tb2[~i & 1][j], tb2[i & 1][j + 1]) + f(i, j);
        }

        int p = l;
        for (int i = l; i <= r; i++) {
            int cur = tb1[m & 1][i] + tb2[~m & 1][i];
            if (cur > ret) p = i, ret = cur;
        }
        
        solve(u, m, l, p);
        str.push_back('C');
        solve(m + 1, d, p, r);
    }
    return ret;
}

int main() {
    scanf("%d%d%d", &N, &M, &P);
    for (int i = 0; i < N; i++) scanf("%d", X + i);
    for (int i = 0; i < M; i++) scanf("%d", Y + i);

    printf("%d\n", solve(0, N - 1, 0, M - 1));
    puts(str.c_str());

    int sum = 0;
    for (int a = 0, b = 0, i = 0; i < str.size(); i++) {
        if (str[i] == 'C') ++a; else ++b;
        sum += f(a, b);
    }
    
    return 0;
}