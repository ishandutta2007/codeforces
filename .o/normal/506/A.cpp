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

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;

const int Z = 30000;
int N, D;
int C[Z+500];

int table[Z+15][505];
#define tb(i, j) table[i][(j)+250]

int main() {
    scanf("%d%d", &N, &D);
    for(int i = 1; i <= N; i++) {
        int p; scanf("%d", &p);
        ++C[p];
    }
    
    int ans = 0;
    for(int x = 0; x <= Z; x++) {
        for(int d = -250; d <= 250; d++) tb(x, d) = (int)-1e9;
    }
    
    tb(D, 0) = 0;
    
    for(int x = D; x <= Z; x++) {
        for(int d = -250; d <= 250; d++) {
            ans = max(ans, tb(x, d) += C[x]);
            
            if(D + d > 0 && x + D + d <= Z) tb(x + (D + d), d) = max(tb(x + (D + d), d), tb(x, d));
            if(d < 250 && D + d + 1 > 0 && x + D + d + 1 <= Z) tb(x + (D + d + 1), d + 1) = max(tb(x + (D + d + 1), d + 1), tb(x, d));
            if(d > -250 && D + d - 1 > 0 && x + D + d - 1 <= Z) tb(x + (D + d - 1), d - 1) = max(tb(x + (D + d - 1), d - 1), tb(x, d));
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}