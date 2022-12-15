#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>

typedef long long i64d;

i64d N;
i64d A[100005];

inline i64d value(i64d x){
    i64d s = 0, y = x; while(y > 0) s += y%10, y /= 10;
    return (x + s) * x;
}

inline i64d max(i64d a, i64d b){
    return a > b ? a : b;
}

int main(){
    int i, j;
    scanf("%I64d",&N);

    i64d low=1, high=(i64d)sqrt(N);
    while(high - low >= 100){
        i64d mid = (low+high)>>1;
        i64d k = max(value(mid-1), max(value(mid), value(mid+1)));
        if(k == N) break;
        else if(k > N) high = mid - 1; else low = mid + 1;
    }

    i64d mid = (low + high) >> 1;
    for(i64d i = mid - 10000; i <= mid + 10000; i++){
        if(i < 0) i = 1;
        if(value(i) == N) return 0 * printf("%I64d\n",i);
    }
    printf("-1");
    return 0;
}