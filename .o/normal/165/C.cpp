#include <stdio.h>
#include <string.h>

const int N_ = 1000005;
typedef long long lld;

int N, K;
char S[N_];
lld res;

int D[N_], DN;

int main(){
    int i, j;
    
    scanf("%d%s", &K, S + 1); 
    N = strlen(S + 1);
    
    for(i = 1; i <= N; i++){
        if(S[i] == '1'){
            D[++DN] = 1;
        }else{
            if(D[DN] < 0) --D[DN];
            else D[++DN] = -1;
        }
    }
    
    int cnt = 0;
    for(i = j = 1; i <= DN; i++){
        if(D[i] > 0) ++cnt;
        while(cnt > K && j < i) {
            if(D[j] > 0) --cnt;
            ++j;
        }
        
        
        if(cnt == K){
            lld v = 1;
            
            if(i == j){
                if(D[i] < 0) v = (lld)-D[i] * (-D[i] + 1) >> 1;
            }else{
                if(D[j] < 0) v *= -D[j] + (D[j + 1] > 0 && j < i);
                if(D[i] < 0) v *= -D[i];
            }
            
            res += v;
        }
    }
    
    printf("%lld\n", res);
    return 0;
}