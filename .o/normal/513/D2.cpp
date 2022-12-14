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

int N, C;
const int N_ = 1001000, C_ = 100500;

vector<int> L[N_], R[N_];

void IMPOSSIBLE() {
    puts("IMPOSSIBLE");
    exit(0);
}

int cur;
vector<int> res;

void solve (int u, int r) { // u : current node, r : rightmost node
    if(u != cur) IMPOSSIBLE();
    
    if(!L[u].empty()) {
        int ch_u = min(++cur, *min_element(L[u].begin(), L[u].end()));
        int ch_r = *max_element(L[u].begin(), L[u].end());
        solve(ch_u, ch_r);
    }
    
    res.push_back(u);
    
    if(!R[u].empty()) {
        int ch_u = min(++cur, *min_element(R[u].begin(), R[u].end()));
        int ch_r = max(*max_element(R[u].begin(), R[u].end()), r);
        solve(ch_u, ch_r);
    }else if(cur < r) {
        solve(++cur, r);
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d%d", &N, &C);
    
    for(int i = 1; i <= C; i++) {
        int a, b; char t[20];
        scanf("%d%d%s", &a, &b, t);
        if(a >= b) IMPOSSIBLE();
        (t[0] == 'L' ? L : R)[a].push_back(b);
    }
    
    cur = 1;
    solve(1, N);
    if(res.size() != N) IMPOSSIBLE();
    
    for(int i = 0; i < res.size(); i++) printf("%d ", res[i]);
    return 0;
}