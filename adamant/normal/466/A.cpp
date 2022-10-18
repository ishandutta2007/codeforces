#include <bits/stdc++.h>

using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int ans=0;
    while(n>0)
    {
        if(min(n,m)*a>=b) n-=m,ans+=b;
        else n--,ans+=a;
    }
    cout<<ans<<endl;
}