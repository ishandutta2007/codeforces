#include<cstdio>
#include<algorithm>
int t,n,a[100];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n); n*=2;
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        std::sort(a,a+n);
        for(int i=0;i<n;i++){
            if(!(i&1)) printf("%d ",a[i/2]);
            else printf("%d ",a[n-(i+1)/2]);
        }
        puts("");
    }
    return 0;
}