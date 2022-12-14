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

int m, n;
int a[100500];
int tb[100500];

int main() {

    scanf("%d", &m); n = (1 << (m + 1)) - 1;
    for (int i = 2; i <= n; i++) scanf("%d", &a[i]);

    ll ans = 0;
    for (int i = (1 << m) - 1; i >= 1; i--) {
        int lv = tb[i + i] + a[i + i];
        int rv = tb[i + i + 1] + a[i + i + 1];
        tb[i] = max(lv, rv);
        ans += max(lv, rv) - min(lv, rv);
    }

    printf("%I64d\n", ans);

    return 0;
}