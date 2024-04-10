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

const int N_ = 1050;
int N, M, MAXW;
int grp[N_]; int get_grp(int x) { return (grp[x] == x) ? x : (grp[x] = get_grp(grp[x])); }
int W[N_], B[N_];

vector<pii> vec[N_];
int tb[2][N_];

int main() {
    scanf("%d%d%d", &N, &M, &MAXW);
    for(int i = 1; i <= N; i++) scanf("%d", &W[i]);
    for(int i = 1; i <= N; i++) scanf("%d", &B[i]), grp[i] = i;
    while(M--) {
        int x, y; scanf("%d%d", &x, &y);
        x = get_grp(x);
        y = get_grp(y);
        if(M & 1) swap(x, y);
        grp[x] = y;
    }

    for(int i = 1; i <= N; i++) {
        int g = get_grp(i);
        vec[g].push_back(pii(W[i], B[i]));
    }

    int *prv = tb[0], *now = tb[1];
    for(int g = 1; g <= N; g++) if(!vec[g].empty()) {
        vector<pii> &v = vec[g];
        pii n(0, 0);
        for(auto x : v) {
            n.first += x.first;
            n.second += x.second;
        }
        v.push_back(n);

        for(int w = 1; w <= MAXW; w++) now[w] = prv[w];
        for(auto x : v) {
            for(int w = x.first; w <= MAXW; w++) {
                now[w] = max(now[w], prv[w - x.first] + x.second);
            }
        }
        swap(prv, now);
    }

    printf("%d\n", prv[MAXW]);
    return 0;
}