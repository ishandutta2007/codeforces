#include <stdio.h>
#include <string.h>
#include <algorithm>

const int N_ = 100005;
typedef long long lld;

int N, Q;
lld Val[N_];
int Color[N_];

int A, B;
lld Table[N_];
lld res, res2;

int main(){
    int i;
    
    scanf("%d%d", &N, &Q);
    for(i = 1; i <= N; i++) {
        int tmp; scanf("%d", &tmp);
        Val[i] = (lld)tmp;
    }
    for(i = 1; i <= N; i++) {
        int tmp; scanf("%d", &tmp);
        Color[i] = tmp;
    }
    
    while(Q--){
        lld a, b;
        scanf("%lld%lld", &a, &b);
        
        std::fill(Table, Table + N + 1, -(lld)(1e15));
        res = res2 = 0;
        int res_color = 0;
        
        for(i = 1; i <= N; i++){
            lld tmp = Table[ Color[i] ] + a * Val[i];
            lld tmp2 = b * Val[i];
            
            if(Color[i] != res_color) tmp2 += res;
            else tmp2 += res2;
            
            if(tmp2 > tmp) tmp = tmp2;
            if(tmp > Table[ Color[i] ]) Table[ Color[i] ] = tmp;
            if(Color[i] != res_color && tmp > res2) res2 = tmp;
            if(tmp > res){
                if(Color[i] != res_color) res2 = res;
                res = tmp; res_color = Color[i];
            }
        }
        
        printf("%lld\n", res);
    }
    return 0;
}