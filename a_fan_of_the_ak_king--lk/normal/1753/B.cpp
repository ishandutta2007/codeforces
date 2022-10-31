#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,x,a[N];
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    scanf("%d %d",&n,&x);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;){
        int j;
        for(j=i;a[j]==a[i]&&j<=n;++j);
        if((j-i)%(a[i]+1)!=0)
            return 0,puts(a[i]>=x?"Yes":"No");
        int l=j-(j-i)/(a[i]+1);
        int w=a[i]+1;
        for(--j;j>=l;--j)
            a[j]=w;
        i=l;
    }
}