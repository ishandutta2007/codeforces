#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <queue>
#include <stack>
#include <assert.h>
 
typedef long long lld;
using namespace std;
typedef vector<int> vi;
typedef vi::iterator vii;
const int N_ = 5005;
const int INF = 987654321;

int N, M;
int D[N_];
int X[N_];

int main(){
    int i, j;
    
    scanf("%d%d", &N, &M);
    for(i = 1; i <= N; i++) {
        char str[105];
        scanf("%d%s", &D[i], str);
    }
    
    for(i = 1; i <= N; i++) X[i] = INF;
    for(i = 1; i <= N; i++){
        for(j = 1; j < i; j++) if(X[j] > D[i]) break;
        X[j] = D[i];
    }
    
    for(i = 1; i <= N; i++){
        if(X[i] > M) break;
    }
    
    printf("%d\n", N - i + 1);
    
    return 0;
}