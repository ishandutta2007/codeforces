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

int n;
ll m;

int a[100];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d%lld", &n, &m);
    
    int l = 1, r = n;
    --m;
    for(int i = n-2; i >= 0; i--) {
        if((m >> i) & 1) a[r--] = n-i-1;
        else a[l++] = n-i-1;
    }
    a[l] = n;
    
    for(int i = 1; i <= n; i++) printf("%d ", a[i]);
    return 0;
}