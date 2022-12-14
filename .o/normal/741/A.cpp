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

const int N_ = 105;

int N;
int crush[N_];
int deg[N_];ll ans = 1;
    
ll gcd (ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

bool visited[N_];

int go (int u) {
    if(visited[u]) return 0;
    visited[u] = true;
    return go(crush[u]) + 1;
}

int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &crush[i]);
        deg[crush[i]]++;
    }

    for(int i = 1; i <= N; i++) {
        if(deg[i] != 1) return 0 & puts("-1");
    }

    for(int i = 1; i <= N; i++) if(!visited[i]) {
        int l = go(i);
        if(l % 2 == 0) l >>= 1;
        ans = ans / gcd(ans, l) * l;
    }

    printf("%lld\n", ans);
    return 0;
}