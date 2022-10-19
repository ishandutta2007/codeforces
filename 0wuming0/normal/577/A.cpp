#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(x%i==0&&x/i<=n)ans++;
    }
    cout<<ans<<endl;
    return 0;
}