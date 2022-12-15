#include<stdio.h>

#define N_ 105
int N, Q;
char D[N_];

int S[N_];
int X[10];

void print(int n){
    if(n==0) X[0]++;
    while(n>0){
        X[n%10]++;
        n/=10;
    }
}

void solve(int l, int r){
    int i, j;
    int L = r - l + 1;

    for(i=l; i<=r; i++){
        if(D[i] == '<') S[i-l+1] = -3;
        else if(D[i] == '>') S[i-l+1] = -4;
        else S[i-l+1] = D[i] - 48;
    }

    int cp = 1; bool dp = 1;
    for(i=0; i<10; i++) X[i] = 0;
    while(1){
        if(S[cp] < 0){
            if(S[cp] == -3) dp = false; else dp = true;
            while(1){
                int tcp = cp;
                cp = (dp ? cp + 1 : cp - 1);
                if(S[cp] < 0){
                    for(i=tcp; i<L; i++) S[i] = S[i+1];
                    --L; if(cp > tcp) cp--;
                    break;
                }else break;
            }
        }else{
            print(S[cp]--);
            int tcp = cp; cp = (dp ? cp + 1 : cp - 1);
            if(S[tcp] < 0){
                for(i=tcp; i<L; i++) S[i] = S[i+1];
                --L; if(cp > tcp) cp--; 
            }
        }
        if(cp < 1 || cp > L) break;
    }
    for(i=0; i<10; i++) printf("%d ",X[i]);
    puts("");
}

int main(){
    int i, j;

    scanf("%d%d%s",&N,&Q,D+1);
    while(Q--){
        int l, r; scanf("%d%d",&l,&r);
        solve(l, r);
    }
    return 0;
}