#include"bits/stdc++.h"
using namespace std;
int a1[200005],n1;
int a2[200005],n2;
int a3[200005],n3;
int ans1[200005];
int ans2[200005];
int sum[200005];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    cin>>n1>>n2>>n3;
    for(int i=0;i<n1;i++)scanf("%d",a1+i);
    for(int i=0;i<n2;i++)scanf("%d",a2+i);
    for(int i=0;i<n3;i++)scanf("%d",a3+i);
    sort(a1,a1+n1);
    sort(a2,a2+n2);
    sort(a3,a3+n3,cmp);
    int n=n1+n2+n3;
    int now=0;
    int &nn=now;
    for(int i=0;i<=n;i++)
    {
        if(nn<n1&&a1[nn]==i)
        {
            now++;
        }//cout<<"<<"<<i<<" "<<now<<endl;
        ans1[i]=i-now;
        ans1[i]+=n1-now;
    }
    now=0;
    nn=0;
    for(int i=n+1;i>0;i--)
    {
        if(nn<n3&&a3[nn]==i)
        {
            now++;
        }
        ans2[i]=n+1-i-now;
        ans2[i]+=n3-now;
    }
    for(int i=0;i<n1;i++)sum[a1[i]]--;
    for(int i=n;i>=0;i--)sum[i]+=sum[i+1];
    for(int i=n;i>=1;i--)ans2[i]+=sum[i];
    for(int i=n;i>=0;i--)sum[i]=0;
    for(int i=0;i<n3;i++)sum[a3[i]]--;
    for(int i=1;i<=n;i++)sum[i]+=sum[i-1];
    for(int i=1;i<=n;i++)ans1[i]+=sum[i];
    //for(int i=0;i<=n+1;i++)printf("%d%c",ans1[i]," \n"[i==n+1]);
    //for(int i=0;i<=n+1;i++)printf("%d%c",ans2[i]," \n"[i==n+1]);
    int best=1e9;
    for(int i=n+1;i>0;i--)
    {
        best=ans2[i]=min(ans2[i],best);
    }
    int ans=1e9;
    for(int i=0;i<=n;i++)
    {
        ans=min(ans,ans1[i]+ans2[i+1]);
    }
    cout<<ans<<endl;
    return 0;
}