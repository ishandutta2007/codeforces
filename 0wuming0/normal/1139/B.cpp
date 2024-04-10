#include"bits/stdc++.h"
using namespace std;
int a[200005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    long long ans=0;
    int last=2e9;
    for(int i=n;i>=1;i--)
    {
        last=min(a[i],max(last-1,0));
        ans+=last;
    }
    cout<<ans<<endl;
    return 0;
}