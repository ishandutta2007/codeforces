#include"bits/stdc++.h"
using namespace std;
int ans[10005];
int l=5000,r=5000;
long long a[1005],pos[1005];
long long op;
bool cmp(int x,int y)
{
    return a[x]<a[y];
}
int main()
{
    int n;
    cin>>n;
    int p1=1,p2=2;
    for(int i=1;i<=n;i++)pos[i]=i;
    for(int i=3;i<=n;i++)
    {
        cout<<2<<" "<<p1<<" "<<p2<<" "<<i<<endl;
        cin>>op;
        if(op==-1)
        {
            p2=i;
            swap(pos[2],pos[i]);
        }
    }
    for(int i=3;i<=n;i++)
    {
        cout<<1<<" "<<p1<<" "<<p2<<" "<<pos[i]<<endl;
        cin>>a[pos[i]];
    }
    sort(pos+3,pos+n+1,cmp);
    ans[r++]=p1;
    ans[r++]=p2;
    ans[r++]=pos[3];
    for(int i=4;i<=n;i++)
    {
        cout<<2<<" "<<ans[r-2]<<" "<<ans[r-1]<<" "<<pos[i]<<endl;
        cin>>op;
        if(op==-1)
        {
            ans[--l]=ans[--r];
            ans[r++]=pos[i];
        }
        else ans[r++]=pos[i];
    }
    while(ans[l]!=1)
    {
        ans[--l]=ans[--r];
    }
    cout<<0;
    for(int i=l;i<r;i++)cout<<" "<<ans[i];
    cout<<endl;
    return 0;
}