#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll num[100006];
ll ans[100006][3],nn;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        ll a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        num[a]+=c;
        num[b]-=c;
    }
    for(int i=1,j=1;;)
    {
        while(i<=n&&num[i]<=0)i++;
        while(j<=n&&num[j]>=0)j++;
        if(i>n||j>n)break;
        ll t=min(num[i],-num[j]);
        ans[nn][0]=i;
        ans[nn][1]=j;
        ans[nn][2]=t;
        num[i]-=t;
        num[j]+=t;
        nn++;
    }
    cout<<nn<<endl;
    for(int i=0;i<nn;i++)printf("%lld %lld %lld\n",ans[i][0],ans[i][1],ans[i][2]);
    return 0;
}