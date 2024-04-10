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

const int N_ = 200500;

int N;
int P[N_], Q[N_];
int A[N_], B[N_];

int tree[N_];

void upd (int x, int v) {
    while(x <= N) {
        tree[x] += v;
        x += x & -x;
    }
}

int get (int x) {
    int ret = 0;
    while(x > 0) {
        ret += tree[x];
        x -= x & -x;
    }
    return ret;
}

void solve (int *D, int *R) {
    for(int i = 1; i <= N; i++) tree[i] = 0;
    for(int i = 1; i <= N; i++) {
        R[i] = D[i]-1 - get(D[i]-1);
        upd(D[i], +1);
    }
}

int tree2[N_*7];

void upd2 (int x, int v) {
    x += 131072*2;
    tree2[x] = v;
    while(x>>=1) tree2[x] = tree2[x+x] + tree2[x+x+1];
}

int getkth (int k) {
    int r = 1;
    while(r < 131072*2) {
        if(tree2[r+r] >= k) {
            r = r+r;
        }else {
            k -= tree2[r+r];
            r = r+r+1;
        }
    }
    return r - 131072*2;
}
int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d", P+i); ++P[i];
    }
    for(int i = 1; i <= N; i++) {
        scanf("%d", Q+i); ++Q[i];
    }
    
    solve(P, A);
    solve(Q, B);
    
    for(int i = N; i > 0; i--) {
        A[i] += B[i];
        A[i-1] += A[i] / (N-i+1);
        A[i] %= N-i+1;
    }
    
    for(int i = 1; i <= N; i++) upd2(i, 1);
    for(int i = 1; i <= N; i++) {
        int x = getkth(A[i]+1);
        printf("%d ", x-1);
        upd2(x, 0);
    }
    return 0;
}