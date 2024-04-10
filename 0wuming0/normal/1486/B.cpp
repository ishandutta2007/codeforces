#include"bits/stdc++.h"
using namespace std;
int x[1005],y[1005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>x[i];
            cin>>y[i];
        }
        sort(x,x+n);
        sort(y,y+n);
        long long ans=0;
        if(n%2)cout<<1<<endl;
        else
        {
            cout<<(x[n/2]-x[n/2-1]+1)*(long long)(y[n/2]-y[n/2-1]+1)<<endl;
        }
    }
    return 0;
}