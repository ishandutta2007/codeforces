#include<stdio.h>
#include<string.h>
#include<algorithm>

typedef long long lld;
lld L, R;
lld res;

lld Number(lld z, int f, lld n){
    return f + z * 10 * f + n * 10;
}

int main(){
    scanf("%I64d%I64d",&L,&R);

    if(R < 10){
        printf("%I64d",(R-L+1));
        return 0;
    }
    if(L < 10){
        res += 10 - L;
        L = 10;
    }
    
    int f; lld z = 1;
    for(z=1; z<R; z*=10) for(f=1; f<=9; f++){
        lld low, high, small = z, large = -z;
        low = 0; high = z-1;
        while(low <= high){
            lld mid = (low + high) >> 1;
            lld num = Number(z, f, mid);
            if(num >= L){
                high = mid - 1;
                if(num <= R && small > mid) small = mid;
            }else low = mid + 1;
        }

        low = 0; high = z-1;
        while(low <= high){
            lld mid = (low + high) >> 1;
            lld num = Number(z, f, mid);
            if(num <= R){
                low = mid + 1;
                if(num >= L && large < mid) large = mid;
            }else high = mid - 1;
        }

        if(small < z && large >= 0) res += large - small + 1;
    }

    printf("%I64d\n",res);
    return 0;
}