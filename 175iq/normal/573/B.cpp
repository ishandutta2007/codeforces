#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
const int N=100010;
int a[N],b[N],c[N],n,ans;
 
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        b[i]=min(b[i-1]+1,a[i]);
    for(int i=n;i>=1;i--)
        c[i]=min(c[i+1]+1,a[i]);
    for(int i=1;i<=n;i++)
        ans=max(ans,min(b[i],c[i]));
    printf("%d\n",ans);
}