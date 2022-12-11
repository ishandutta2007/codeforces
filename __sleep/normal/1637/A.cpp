#include<cstdio>
#include<algorithm>
const int N=300005;
int n,t,a[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        if(std::is_sorted(a+1,a+n+1)) puts("NO");
        else puts("YES");
    }
    return 0;
}