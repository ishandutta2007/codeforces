#include<stdio.h>
int w1[201000], w2[201000], c1, c2, n;
long long s1,s2;
int main(){
    int i, a, pv;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        if(a>0){
            w1[c1++]=a;
            pv=1;
            s1+=a;
        }
        else{
            w2[c2++]=-a;
            s2+=-a;
            pv=2;
        }
    }
    if(s1!=s2){
        printf(s1>s2?"first":"second");
        return 0;
    }
    for(i=0;i<c1||i<c2;i++){
        if(w1[i]!=w2[i])break;
    }
    if(i>=c1&&i>=c2)printf(pv==1?"first":"second");
    else printf(w1[i]>w2[i]?"first":"second");
}