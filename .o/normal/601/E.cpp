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
#include <time.h>
#include <functional>
#include <numeric>
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define debug(format, ...) printf(format, __VA_ARGS__);

int N, K, Q;
const int N_ = 5050, K_ = 1050, Q_ = 30050, Q1_ = 30050;
const int lgQ_ = 20;

struct exhibit {
    int v, w, l, r;
    exhibit (int v = 0, int w = 0, int l = 0, int r = 0): v(v), w(w), l(l), r(r) { }
};

exhibit exhibits[N_ + Q1_];
vector<int> time3;
ll ans[Q_];
bool check_time3[Q_];

const ll hashP = (ll)1e7 + 19, hashQ = (ll)1e9 + 7;

int tb[lgQ_][K_];

void solve (int l, int r, vector<exhibit> &cur, int level) {
    for(int m = 0; m <= K; m++) 
        tb[level][m] = tb[level-1][m];

	int mid = (l + r) >> 1;
    
    vector<exhibit> nxtl;
    vector<exhibit> nxtr;
    for(exhibit e : cur) {
        if(e.l <= l && r <= e.r) { //  
            for(int i = K; i >= e.w; i--)
                tb[level][i] = max(tb[level][i], tb[level][i - e.w] + e.v);
        }else if(e.r <= mid) {
            nxtl.push_back(e);
        }else if(e.l > mid) {
            nxtr.push_back(e);
        }else if(e.l <= r && l <= e.r) {
            nxtl.push_back(e);
            nxtr.push_back(e);
        }
    }

    if(l == r) {
        if(check_time3[l]) {
            ll mul = 1;
            for(int m = 1; m <= K; m++) {
                ans[l] = (ans[l] + tb[level][m] * mul) % hashQ;
                mul = (mul * hashP) % hashQ;
            }
        }
        return;
    }else {
	    solve(l, mid, nxtl, level + 1);
	    solve(mid+1, r, nxtr, level + 1);
    }
}
int main() {
    scanf("%d%d", &N, &K);
    for(int i = 1; i <= N; i++) {
        exhibit &e = exhibits[i];
        scanf("%d%d", &e.v, &e.w);
        e.l = 1;
    }
    scanf("%d", &Q); ++Q;
    for(int q = 2; q <= Q; q++) {
        int t; scanf("%d", &t);
        if(t == 1) {
            exhibit &e = exhibits[++N];
            scanf("%d%d", &e.v, &e.w);
            e.l = q;
        }else if(t == 2) {
            int i; scanf("%d", &i);
            exhibits[i].r = q;
        }else if(t == 3) {
            time3.push_back(q);
            check_time3[q] = true;
        }
    }

    ++Q;
    for(int i = 1; i <= N; i++) {
        exhibit &e = exhibits[i];
        if(e.r == 0) e.r = Q;
    }

    vector<exhibit> cur;
    for(int i = 1; i <= N; i++) cur.push_back(exhibits[i]);
    solve(1, Q, cur, 1);

    for(auto t : time3)
        printf("%lld\n", ans[t]);

    return 0;
}