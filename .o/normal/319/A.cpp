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

const ll MOD = 1000000007 ;
int N; char X[1000];
ll res = 0;
ll p2[1000] = {1};

int main() {
    int i, j, k;
    
    scanf("%s", X); N = strlen(X);
    for(i = 1; i < 1000; i++) p2[i] = (p2[i - 1] * 2) % MOD;
    
    for(i = 0; i < N; i++) if(X[i] == '1') {
        res = (res + p2[N + N - i - 2]) % MOD;
    }
    
    printf("%I64d\n", res);
    return 0;
}