#include<stdio.h>
int idx, S, t1, t2;
int n, Q, Res[1010000];
int main(){
    int ck, a, i, tt1, tt2;
    scanf("%d%d",&n,&Q);
    idx = 1;
    t1=t2=1;
    for(i=1;i<=Q;i++){
        scanf("%d",&ck);
        if(ck==2){
            tt1 = (-t1+n)%n;
            tt2 = (t1+t2+t1)%n;
            t1=tt1,t2=tt2;
            if(idx%2==1)idx++;
            else idx--;
        }
        else{
            scanf("%d",&a);
            a = (a+n)%n;
            idx = (idx+a-1)%n+1;
            if(a%2==1){
                tt1=t2,tt2=t1;
                t1=tt1,t2=tt2;
            }
        }
    }
    a = Res[idx] = 1;
    for(i=idx+1;i<idx+n;i++){
        if(i%2==0)a += t1;
        else a += t2;
        a=(a+n-1)%n+1;
        if(i>n)Res[i-n] = a;
        else Res[i]=a;
    }
    for(i=1;i<=n;i++)printf("%d ",Res[i]);
}