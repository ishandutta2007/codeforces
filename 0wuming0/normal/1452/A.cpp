#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        if(n<m)swap(n,m);
        int ans=2*m;
        n-=m;
        int r=(n/2);
        if(n>0)ans+=2*n-1;
        cout<<ans<<endl;
    }
    return 0;
}