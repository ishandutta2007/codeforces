#include<stdio.h>
#include<algorithm>
using namespace std;
int BIT[2][201000];
int w[201000], n, K, A, B, Q;
void Add(int ck, int a, int b){
    while(a<=n){
        BIT[ck][a]+=b;
        a+=(a&-a);
    }
}
int Sum(int a, int ck){
    int s = 0;
    while(a){
        s += BIT[ck][a];
        a-=(a&-a);
    }
    return s;
}
int main(){
    int i, a, b, ck;
    scanf("%d%d%d%d%d",&n,&K,&A,&B,&Q);
    while(Q--){
        scanf("%d%d",&ck,&a);
        if(ck==1){
            scanf("%d",&b);
            Add(0,a,-min(w[a],B));
            Add(1,a,-min(w[a],A));
            w[a]+=b;
            Add(0,a,min(w[a],B));
            Add(1,a,min(w[a],A));
        }
        else{
            printf("%d\n",Sum(a-1,0)+Sum(n,1)-Sum(a+K-1,1));
        }
    }
}