#include<stdio.h>
int n;
int A[100], B[100], CA, CB, r1, r2;
int main(){
    int TC, i;
    char p[3];
    scanf("%d",&TC);
    while(TC--){
        scanf("%d",&n);
        CA=0,CB=0;
        for(i=1;i<=n/2;i++){
            printf("? %d %d\n",i*2-1,i*2);
            fflush(stdout);
            scanf("%s",p);
            if(p[0]=='<'||p[0]=='='){
                A[++CA] = i*2-1;
                B[++CB] = i*2;
            }
            else{
                B[++CB] = i*2-1;
                A[++CA] = i*2;
            }
        }
        if(n%2){
            A[++CA] = n;
            B[++CB] = n;
        }
        int x = A[1];
        for(i=2;i<=CA;i++){
            printf("? %d %d\n",x,A[i]);
            fflush(stdout);
            scanf("%s",p);
            if(p[0]=='>'){
                x = A[i];
            }
        }
        r1 = x;
        x = B[1];
        for(i=2;i<=CB;i++){
            printf("? %d %d\n",x,B[i]);
            fflush(stdout);
            scanf("%s",p);
            if(p[0]=='<'){
                x = B[i];
            }
        }
        r2 = x;
        printf("! %d %d\n",r1,r2);
        fflush(stdout);
    }
}