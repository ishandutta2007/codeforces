#include <stdio.h>
int main(){
    int n,prev,next,st=1,i,ans=1;
    scanf("%d",&n);
    scanf("%d",&prev);
    for(i=1;i<n;i++){
        scanf("%d",&next);
        if(prev<next){
            if(st!=1) ans=0;
        }
        else if(prev>next){
            st=-1;
        }
        else{
            if(st==-1) ans=0;
            st=0;
        }
        prev=next;
    }
    if(ans) printf("YES");
    else printf("NO");
}