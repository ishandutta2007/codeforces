#include"bits/stdc++.h"
using namespace std;
int n;
void solve(int l,int r)
{
    if(l==r)
    {
        cout<<"! "<<l<<endl;
        return;
    }
    int m=l+r>>1;
    cout<<"? "<<l<<" "<<m<<endl;
    int k=m-l+1;
    bool f=0;
    for(int i=1;i<=k;i++)
    {
        int a;
        cin>>a;
        if(l<=a&&a<=m)f^=1;
    }
    if(f)r=m;
    else l=m+1;
    solve(l,r);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        solve(1,n);
    }
    return 0;
}