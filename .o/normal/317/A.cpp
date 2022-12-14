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
const int INF = 987654321; 
const ll LINF = 1e15;  

ll X, Y, M, res;

ll solve (ll x, ll y) {
    if(x >= M || y >= M) return 0;
    if(x > y) swap(x, y);
    x += y;
    return solve(x, y) + 1;
}

int main() {
    scanf("%I64d%I64d%I64d", &X, &Y, &M);
    if(X >= M || Y >= M) return 0 & puts("0");
    if(X <= 0 && Y <= 0) return 0 & puts("-1");
    if(X > Y) swap(X, Y);
    if(X <= 0) {
        res += (-X)/Y;
        X += Y * ((-X)/Y);
        while(X <= 0) {
            X += Y;
            ++res;
        }
    }
    
    printf("%I64d\n", res + solve(X, Y));
    return 0;
}