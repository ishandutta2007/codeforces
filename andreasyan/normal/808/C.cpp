#include <bits/stdc++.h>
using namespace std;
const int N=102;
struct ban
{
    int x,i;
};
bool operator<(const ban& a,const ban& b)
{
    return a.x<b.x;
}

int n,w;
ban a[N];

int ans[N];

int main()
{
    cin>>n>>w;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].x;
        if(a[i].x%2==0)
        {
            ans[i]=a[i].x/2;
            w-=(a[i].x/2);
        }
        else
        {
            ans[i]=a[i].x/2+1;
            w-=(a[i].x/2+1);
        }
        a[i].i=i;
    }
    if(w<0)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;--i)
    {
        if(w>=(a[i].x-ans[a[i].i]))
        {
            w-=(a[i].x-ans[a[i].i]);
            ans[a[i].i]=a[i].x;
        }
        else
        {
            ans[a[i].i]+=w;
            w=0;
        }
    }
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}