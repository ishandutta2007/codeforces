#include <stdio.h>
int main(){
    int n,m,r,i,q,j,x[1003],y[1003];
    char s[1003],t[1003];
    scanf("%d %d",&n,&m);
    scanf("%s %s",&s,&t);
    r=n+1;
    for(i=0;i<=m-n;i++){
        q=0;
        for(j=0;j<n;j++){
            if(s[j]!=t[j+i]){
                y[q++]=j;
            }
        }
        if(q<r){
            r=q;
            for(j=0;j<r;j++) x[j]=y[j];
        }
        
    }
    printf("%d\n",r);
    for(i=0;i<r;i++){
        printf("%d ",x[i]+1);
    }
}