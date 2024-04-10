#include<stdio.h>
int BIT[101000];
int Q, be, ed, chk, n;
void Ins(int a, int b){
    while(a <= n){
        BIT[a] += b;
        a += (a&-a);
    }
}
int Sum(int a){
    if(a < be)return 0;
    if(a > ed)a = ed;
    int r = 0;
    while(a){
        r += BIT[a];
        a -= (a&-a);
    }
    return r;
}
int Gap(int a){
    return Sum(a) - Sum(a-1);
}
int main(){
    int i, ck, a, b, j, t;
    scanf("%d%d",&n,&Q);
    for(i=1;i<=n;i++){
        Ins(i,1);
    }
    be = 1, ed = n;
    while(Q--){
        scanf("%d%d",&ck,&a);
        if(ck == 1){
            if(a * 2 <= (ed - be + 1)){
                if(chk == 0){
                    for(j=1;j<=a;j++){
                        t = Gap(be+j-1);
                        Ins(be+2*a-j, t);
                        Ins(be+j-1, -t);
                    }
                    be += a;
                }
                else{
                    for(j=1;j<=a;j++){
                        t = Gap(ed-j+1);
                        Ins(ed-2*a+j, t);
                        Ins(ed-j+1, -t);
                    }
                    ed -= a;
                }
            }
            else{
                a = (ed-be+1)-a;
                if(chk == 0){
                    for(j=1;j<=a;j++){
                        t = Gap(ed-j+1);
                        Ins(ed-2*a+j, t);
                        Ins(ed-j+1, -t);
                    }
                    ed -= a;
                }
                else{
                    for(j=1;j<=a;j++){
                        t = Gap(be+j-1);
                        Ins(be+2*a-j, t);
                        Ins(be+j-1, -t);
                    }
                    be += a;
                }
                chk = !chk;
            }
        }
        else{
            scanf("%d",&b);
            a++;
            if(chk == 0){
                printf("%d\n",Sum(be + b - 1) - Sum(be + a - 2));
            }
            else{
                printf("%d\n",Sum(ed - a + 1) - Sum(ed - b));
            }
        }
    }
}