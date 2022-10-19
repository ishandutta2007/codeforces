#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t,k;
    cin>>t;
    int ans=0;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        if(n<3)cout<<1<<endl;
        else cout<<(n-3)/x+2<<endl;
    }//cout<<ans<<endl;
    return 0;
}