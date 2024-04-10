#include<cstdio>
int w,h,n,t;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&w,&h,&n);
        if((w&-w)*(h&-h)>=n) puts("YES");
        else puts("NO");
    }
    return 0;
}