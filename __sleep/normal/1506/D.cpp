#include<cstdio>
#include<algorithm>
const int N=200005;
int n,t,a[N],k,s;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        std::sort(a,a+n);
        k=s=1; a[n]=-1;
        for(int i=1;i<=n;i++){
            if(a[i]==a[i-1])s++;
            else k=std::max(k,s),s=1;
        }
        if(k<=n/2) puts(n&1?"1":"0");
        else printf("%d\n",n-(n-k)*2); 
    }
    return 0;
}