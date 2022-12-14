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

const int N_ = 100500;
const int LEAF = 131072*2;

int N, M;
ll D[N_+N_], H[N_+N_];

struct node {
    ll mx, mn;
    ll ans;
    node (ll mx = 0, ll mn = 0, ll ans = -1):
        mx(mx), mn(mn), ans(ans) { }
};

node merge (node a, node b) {
    node r;
    if(a.ans == -1) r = b; else if(b.ans == -1) r = a;
    else {
        r.mx = max(a.mx, b.mx);
        r.mn = min(a.mn, b.mn);
        r.ans = max(max(a.ans, b.ans), b.mx - a.mn);
    }
    return r;
}

node tree[LEAF+LEAF+10];

ll get (int x, int y) {
    x += LEAF; y += LEAF;
    
    node retl, retr;
    bool chkl = false, chkr = false;
    
    while(x <= y) {
        if((x & 1) == 1) {
            if(!chkl) retl = tree[x], chkl = true;
            else retl = merge(retl, tree[x]);
        }
        if((y & 1) == 0) {
            if(!chkr) retr = tree[y], chkr = true;
            else retr = merge(tree[y], retr);
        }
        x = (x + 1) >> 1;
        y = (y - 1) >> 1;
    }
    
    node ret;
    if(chkl && !chkr) ret = retl;
    else if(!chkl && chkr) ret = retr;
    else if(chkl && chkr) ret = merge(retl, retr);
    else assert(0);
    
    return ret.ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++) {
        scanf("%lld", &D[i]);
        D[N+i] = D[i];
    }
    for(int i = 0; i < N; i++) {
        scanf("%lld", &H[i]);
        H[N+i] = H[i];
    }
    
    for(int i = 1; i < N+N; i++) D[i] += D[i-1];
    
    for(int i = 0; i < N+N; i++) {
        ll p = (i > 0) ? D[i-1] : 0;
        tree[i + LEAF] = node(p + 2 * H[i], p - 2 * H[i], 0);
    }
    
    for(int i = LEAF-1; i >= 1; i--) tree[i] = merge(tree[i+i], tree[i+i+1]);
    
    while(M--) {
        int s, e; scanf("%d%d", &s, &e); --s; --e;
        ll ans = 0;
        if(s <= e) {
            ans = get(e + 1, s + N - 1);
        }else {
            ans = get(e + 1, s - 1);
        }
        printf("%lld\n", ans);
    }
    
    
    
    return 0;
}