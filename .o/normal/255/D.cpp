#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<memory.h>
#include<map>
#include<assert.h>
#include<list>
#include<queue>

typedef long long lld;

lld N, X, Y, C;

struct P{
    lld x, y;
    P(lld x, lld y): x(x), y(y) {}
    P() {}
} D[4];
const int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};

lld res;

lld max(lld v){
    return v < 0 ? 0 : v;
}
lld getval(lld v){
    int i, j;
    for(i=0; i<4; i++){
        D[i] = P(X + dx[i] * v, Y + dy[i] * v);
    }
    
    lld ret = (v+1) * (v+1) + v * v;
    lld tmp;
    
    tmp = max(D[0].y - N); ret -= tmp*tmp;
    tmp = max(D[2].x - N); ret -= tmp*tmp;
    tmp = max(1 - D[1].y); ret -= tmp*tmp;
    tmp = max(1 - D[3].x); ret -= tmp*tmp;
    
    tmp = max(D[0].x + D[0].y - 2 * N); ret += tmp * (tmp - 1) >> 1;
    tmp = max(2 - (D[1].x + D[1].y)); ret += tmp * (tmp - 1) >> 1;
    tmp = max(D[0].y - D[0].x - N); ret += tmp * (tmp + 1) >> 1;
    tmp = max(D[1].x - D[1].y - N); ret += tmp * (tmp + 1) >> 1;
    
    return ret;
}

int main(){
    scanf("%I64d%I64d%I64d%I64d",&N,&X,&Y,&C);
    
    lld left = 0, right = 2000000001ll;
    res = right;
    while(left <= right){
        lld mid = (left + right) >> 1;
        if(getval(mid) >= C){
            if(res > mid) res = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }

    printf("%I64d\n",res);
    return 0;
}