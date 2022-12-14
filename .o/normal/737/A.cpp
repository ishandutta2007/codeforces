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

const int N_ = 200500;

int N, K, S, T;
pair<int, int> cars[N_];
int G[N_], diff[N_];
ll sum0[N_], sum1[N_];

int main() {
    scanf("%d%d%d%d", &N, &K, &S, &T);
    for(int i = 1; i <= N; i++) {
        int c, v; scanf("%d%d", &c, &v);
        cars[i] = pair<int, int>(v, c);
    }
    sort(cars+1, cars+N+1);

    G[0] = 0; G[K+1] = S;
    for(int i = 1; i <= K; i++) scanf("%d", G+i);
    sort(G, G+K+2);
    
    for(int j = 1; j <= K+1; j++) diff[j] = G[j] - G[j-1];
    sort(diff+1, diff+K+2);

    for(int j = 1; j <= K+1; j++)
        sum0[j] = sum0[j-1] + diff[j];
    for(int j = K+1; j >= 1; j--)
        sum1[j] = sum1[j+1] + diff[j];

    int ans = (int)2e9;
    int j = 1;
    for(int i = 1; i <= N; i++) {
        int c = cars[i].second, v = cars[i].first;
        if(v >= diff[K+1]) {
            while(j <= K+1 && 2 * diff[j] < v) j++;
            ll t = (3 * sum1[j] - (K+2-j) * v) + sum0[j-1];
            if(t <= T) ans = min(ans, c);
        }
    }

    if(ans == (int)2e9) ans = -1;
    printf("%d\n", ans);
    return 0;
}