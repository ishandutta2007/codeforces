
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

int N, C[1005000];
int ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("566F.in", "r", stdin);
    freopen("566F.out", "w", stdout);
#endif

    scanf("%d", &N);
    while (N--) {
        int x; scanf("%d", &x);
        ++C[x];
    }

    for (int i = 1000000; i > 0; i--) {
        int mx = 0;
        for (int j = i * 2; j <= 1000000; j += i) mx = max(mx, C[j]);
        C[i] += mx;
        ans = max(ans, C[i]);
    }

    printf("%d\n", ans);

    return 0;
}