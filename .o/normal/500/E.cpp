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
typedef pair<ll, ll> pll;

const int N_ = 200500;
const int LEAF = 131072;
const int Q_ = 300500;
const int lgN_ = 18;
int N, P[N_], L[N_];

namespace rmq {
    int tree[N_];
    
    void upd (int x, int v) {
        while(x <= N) {
            tree[x] = max(tree[x], v);
            x += x & -x;
        }
    }

    int get (int x) {
        int ret = 0;
        while(x > 0) {
            ret = max(ret, tree[x]);
            x -= x & -x;
        }
        return ret;
    }
};

int rightmost[N_];
int nxt[lgN_][N_];

int tb[lgN_][N_];

int Q;

int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) scanf("%d%d", &P[i], &L[i]);
    
    for(int i = N; i > 0; i--) {
        rightmost[i] = max(
            P[i] + L[i],
            rmq::get(upper_bound(P+1, P+N+1, P[i]+L[i]) - P - 1)
        );
        nxt[0][i] = upper_bound(P+1, P+N+1, rightmost[i]) - P;
        tb[0][i] = max(P[nxt[0][i]] - rightmost[i], 0);
        rmq::upd(i, rightmost[i]);
    }
    nxt[0][N+1] = N+1;
    
    for(int k = 1; k < lgN_; k++) {
        nxt[k][N+1] = N+1;
        for(int i = 1; i <= N; i++) {
            nxt[k][i] = nxt[k-1][nxt[k-1][i]];
            tb[k][i] = tb[k-1][i] + tb[k-1][nxt[k-1][i]];
        }
    }
    
    scanf("%d", &Q);
    while(Q--) {
        int x, y; scanf("%d%d", &x, &y);
        int ret = 0;
        
        for(int k = lgN_-1; k >= 0; k--) {
            if(nxt[k][x] <= y) {
                ret += tb[k][x];
                x = nxt[k][x];
            }
        }
        printf("%d\n", ret);
    }
    
    
    return 0;
}