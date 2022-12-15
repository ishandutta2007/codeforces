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

int N; const int N_ = 100005;
struct S{ 
    lld k, a;
    bool operator< (const S &t) const{
        return k < t.k;
    }
} D[N_];

lld res;

int main(){
    int i, j;
    
    scanf("%d", &N);
    for(i = 1; i <= N; i++){
        scanf("%lld%lld", &D[i].k, &D[i].a);
    }
    sort(D + 1, D + N + 1);
    
    for(i = 2; i <= N; i++){
        lld diff = D[i].k - D[i - 1].k;
        if(diff >= 16) continue;
        lld val = 1 << (diff << 1);
        lld u = D[i - 1].a - D[i].a * val;
        if(u > 0) {
            D[i].a += (u - 1) / val; 
            ++D[i].a;
        }
    }
    
    
    res = D[N].k;
    while(++res){
        lld val = 1 << ((res - D[N].k) << 1);
        if(val >= D[N].a) break;
    }
    
    printf("%lld\n", res);
    return 0;
}