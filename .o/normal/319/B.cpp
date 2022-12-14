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

typedef pair<int,int> pii;

const int N_ = 100005;
int N, A[N_];
bool C[N_];
stack<int> S;
int res;

int main() {
    int i, j, k;
    
    scanf("%d", &N);
    for(int i = 1, mx = 0; i <= N; i++) {
        scanf("%d", A+i);
        if(A[i] > mx) C[i] = 1, mx = A[i];
    }
    
    for(i = N; i > 0; i--) {
        if(C[i]) {
            while(!S.empty()) S.pop();
        }else {
            while(!S.empty() && S.top() < A[i]) S.pop();
            S.push(A[i]);
            res = max(res, (int)S.size());
        }
    }
    
    printf("%d\n", res);
    return 0;
}