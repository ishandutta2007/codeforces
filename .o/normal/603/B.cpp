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
#include <unordered_map>
#include <unordered_set>
#include <time.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int P, K;

const int MOD = 1000000007;

const int P_ = 1005000;
int grp[P_];
int get(int x) { return grp[x] == x ? x : (grp[x] = get(grp[x])); }

int main() {
    scanf("%d%d", &P, &K);
    
    int ans = (K == 1) ? P : P-1;
    if(K > 0) {
        for(int i = 0; i < P; i++) grp[i] = i;
        for(int i = 0; i < P; i++) {
            int x = ((ll)i * (ll)K) % P;
            int a = get(x), b = get(i);
            if(a != b) --ans, grp[a] = b;
        }
    }
    
    ll v = 1;
    for(int i = 0; i < ans; i++) v = (v * P) % MOD;
    printf("%lld\n", v);
    return 0;
}