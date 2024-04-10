#include<cstdio>
#include<algorithm>
const int N=100005;
int t,n,a[N];
bool judge(){
    for(int i=1;i<n;i++)
        if(a[i+1]<a[i]) return false;
    return true;
}
void work(int x){
    for(int i=2-(x&1);i<n;i+=2)
        if(a[i]>a[i+1]) std::swap(a[i],a[i+1]);
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        int ans;
        for(ans=0;ans<=10000000;ans++){
            if(judge()) break;
            work(ans+1);
        }
        printf("%d\n",ans);
    }
    return 0;
}