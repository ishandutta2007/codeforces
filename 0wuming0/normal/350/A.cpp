#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int l=100000,r=-1,k=-1;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        l=min(l,k);
        r=max(r,k);
    }
    int ans=max(r,2*l);
    for(int i=0;i<m;i++)
    {
        cin>>k;
        if(k<=ans)
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}