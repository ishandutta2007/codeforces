#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int ans=1e9;
    for(int i=0;i*m<=n+10000;i++)
    {
        ans=min(max(n-i*m,0)*a+b*i,ans);
    }
    cout<<ans<<endl;
    return 0;
}