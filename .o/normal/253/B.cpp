#include <stdio.h>
#include <algorithm>

const int N_ = 100005;

int N;
int D[N_];

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int i, j;
    
    scanf("%d", &N);
    for(i = 1; i <= N; i++) scanf("%d", &D[i]);
    std::sort( D + 1, D + N + 1 );
    
    // max <= 2 * min
    int res = N - 1;
    
    for(i = 1; i <= N; i++){
        int low = i, high = N, r = 0;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(D[mid] <= D[i] * 2){
                r = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        if(r > 0){
            int v = N - (r - i + 1);
            if(res > v) res = v;
        }
    }
    
    printf("%d\n", res);
    return 0;
}