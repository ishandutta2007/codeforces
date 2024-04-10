#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int N, C[4], res;

int main(){
    int i;
    
    scanf("%d",&N);
    for(i=1; i<=N; i++){
        int d; scanf("%d",&d);
        if(d == 4) res++; else C[d]++;
    }

    int t = min(C[1], C[3]);
    res += t; C[1] -= t; C[3] -= t;
    t = C[2] / 2;
    res += t; C[2] -= t * 2;

    if(C[3] > 0){ res += C[3]; C[3] = 0; }
    if(C[2] > 0){
        if(C[1] >= 2){ res ++; C[2] = 0; C[1] -= 2; }
        else if(C[1] == 1){ res ++ ; C[2] = 0; C[1] = 0; }
        else{ res+=C[2]; }
    }
    if(C[1] > 0){
        res += (C[1]+3) / 4;
    }

    printf("%d\n",res);

    return 0;
}