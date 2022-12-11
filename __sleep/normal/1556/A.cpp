#include<cstdio>
const int N=100005;
int t,n,a,b;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        if(a==0&&b==0) puts("0");
        else if(a==b)puts("1");
        else if((a-b)&1) puts("-1");
        else puts("2");
    }
    return 0;
}