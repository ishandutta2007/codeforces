#include"bits/stdc++.h"
using namespace std;
int a[105];
int b[5];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<5;i++)cin>>b[i];
    long long num[5]={0};
    int ans=0;
    for(int i=0;i<n;i++)
    {
        a[i]+=ans;
        ans=0;
        for(int j=4;j>=0;j--)
        {
            num[j]+=a[i]/b[j];
            a[i]%=b[j];
        }
        ans+=a[i];
    }
    for(int i=0;i<5;i++)printf("%lld%c",num[i]," \n"[i==4]);
    cout<<ans<<endl;
    return 0;
}