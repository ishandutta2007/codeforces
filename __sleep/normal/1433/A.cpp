#include<cstdio>
int main(){
    int s[]={0,1,3,6,10};
    int t,n,x,g;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        x=n%10; g=0;
        while(n){
            n/=10;
            g++;
        }
        printf("%d\n",(x-1)*10+s[g]);
    }
    return 0;
}