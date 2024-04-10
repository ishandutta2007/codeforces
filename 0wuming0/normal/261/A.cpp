#include"bits/stdc++.h"
using namespace std;
int a[100005];
int main()
{
    int m,n;
    int best=1e9;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int t;
        scanf("%d",&t);
        best=min(best,t);
    }
    cin>>n;
    for(int i=0;i<n;i++)scanf("%d",a+i);
    sort(a,a+n);
    int now=best;
    for(int i=n-1;i>=0;i--)
    {
        if(now<=0)a[i]=0;
        now--;
        if(now==-2)now=best;
    }
    long long ans=0;
    for(int i=0;i<n;i++)ans+=a[i];
    cout<<ans<<endl;
    return 0;
}