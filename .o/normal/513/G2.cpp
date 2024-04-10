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
#include <tuple>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;


int n, k;
int a[100];
int p[100];

ll res1;
ll cnt1;

void rec1 (int x) {
    if(x > k) {
        int c = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) if(p[i] > p[j]) ++c;
        }
        res1 += c;
        cnt1 ++;
        return;
    }
    for(int i = 0; i < n; i++) for(int j = i; j < n; j++) {
        reverse(p+i, p+j+1);
        rec1(x+1);
        reverse(p+i, p+j+1);
    }
}
void solve1() {
    for(int i = 0; i < n; i++) p[i]=a[i];
    rec1(1);
    printf("%lld %lld\n", res1, cnt1);
    printf("%.10lf\n", (lf)res1 / cnt1);
}

int T[35][35][35][35];

lf tb[2][35][35];
void solve2() {
    for(int i = 0; i < n; i++) p[i] = i;
    for(int l = 0; l < n; l++) for(int r = l; r < n; r++) {
        reverse(p+l, p+r+1);
        for(int a = 0; a < n; a++) for(int b = a+1; b < n; b++) {
            T[a][b][p[a]][p[b]]++;
        }
        reverse(p+l, p+r+1);
    }
    
    for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++) {
        if(a[i] > a[j]) tb[0][i][j] = 1.; else tb[0][j][i] = 1;
    }
    
    for(int rep = 1; rep <= k; rep++) {
#define cur tb[rep & 1]
#define prv tb[~rep & 1]
        for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++) {
            cur[i][j] = 0;
            for(int a = 0; a < n; a++) for(int b = 0; b < n; b++) if(T[i][j][a][b]) {
                cur[i][j] += prv[a][b] * T[i][j][a][b] ;
            }
            cur[i][j] /= (n * (n+1) / 2.);
            //printf("%d %d %d %lf\n",rep,i+1,j+1,cur[i][j]);
            cur[j][i] = 1 - cur[i][j];
        }
#undef cur
#undef prv
    }
    
    lf res = 0;
    
    for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++) {
        res += tb[k & 1][i][j];
    }
    
    printf("%.20lf\n", res);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", a+i);
    
    if(0 && n <= 6 && k <= 4) {
        solve1();
    }else {
        solve2();
    }
    return 0;
}