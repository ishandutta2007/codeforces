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

using namespace std;
typedef long long ll;
const int INF = 987654321;
const ll LINF = 1e15;

const int N_ = 100005;

int N;
int D[N_];
int res;

void solve () {
    set<int> S; set<int>::iterator it, nit;
    for(int i = 1; i <= N; i++){
        it = S.lower_bound(D[i]);
        if(it != S.end()) res = max(res, D[i] ^ *it);
        for(it = S.begin(); it != S.end();) {
            if(*it > D[i]) break;
            nit = it; nit++;
            S.erase(it);
            it = nit;
        }
        S.insert(D[i]);
    }
}

int main (){
    int i, j;

    scanf("%d", &N);
    for(i = 1; i <= N; i++) scanf("%d", &D[i]);

    solve();
    reverse(D + 1, D + N + 1);
    solve();

    printf("%d\n", res);
    return 0;
}