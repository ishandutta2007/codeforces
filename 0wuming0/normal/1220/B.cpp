#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a[1005][1005];
ll ans[1005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%lld",&a[i][j]);
    ll t=a[1][2]*a[1][3]/a[2][3];
    ans[1]=sqrt(t+1);
    ans[1]-=100;
    if(ans[1]<0)ans[1]=0;
    while(ans[1]*ans[1]!=t)ans[1]++;
    for(int i=2;i<=n;i++)ans[i]=a[1][i]/ans[1];
    for(int i=1;i<=n;i++)printf("%lld%c",ans[i]," \n"[i==n]);
    return 0;
}