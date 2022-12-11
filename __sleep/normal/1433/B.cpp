#include<cstdio>
int flag,n,t,x,ans,ans1;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        flag=ans=ans1=0;
        while(n--){
            scanf("%d",&x);
            if(x&&!flag) flag=1;
            if(x) ans+=ans1,ans1=0;
            if(!x&&flag) ans1++;
        }
        printf("%d\n",ans);
    }
    return 0;
}