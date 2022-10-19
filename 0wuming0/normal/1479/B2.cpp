#include"bits/stdc++.h"
using namespace std;
int a[100005];
int r[100005];
int pos[100005];
int main()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    int nn=1;
    for(int i=2;i<=n;i++)if(a[i]!=a[nn])a[++nn]=a[i];
    n=nn;
    for(int i=n;i>=1;i--)
    {
        r[i]=pos[a[i]];
        pos[a[i]]=i;
    }
    int now[2]={n+1,n+1};
    for(int i=1;i<=n;i++)
    {//cout<<i<<" "<<now[0]<<" "<<now[1]<<endl;
        if(i==now[0])
        {
            ans++;
            now[0]=n+1;
            sort(now,now+2);
        }
        if(r[i])
        {
            now[1]=r[i];
            sort(now,now+2);
        }
        else now[1]=n+1;
    }
    cout<<n-ans<<endl;
    return 0;
}