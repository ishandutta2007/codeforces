#include"bits/stdc++.h"
using namespace std;
int num[1000006];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int p,q;
        scanf("%d%d",&p,&q);
        num[p]++;
        num[q]++;
    }
    if(n<=2)
    {
        cout<<"0"<<endl;
        return 0;
    }
    long long ans=(n*(long long)(n-1)/2-3*m)*(n-2)/3;
    for(int i=1;i<=n;i++)
    {
        ans=ans+num[i]*(long long)(num[i]-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}