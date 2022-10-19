#include <bits/stdc++.h>
using namespace std;
const int N=100005;
struct ban
{
    int l,r;
};

int n,l,m;
ban a[N];

int main()
{
    cin>>n>>l>>m;
    for(int i=0;i<n;++i)
    {
        int s,x;
        cin>>s>>x;
        a[i].l=s;
        a[i].r=s+x;
    }
    a[n].l=l;
    a[n].r=l;
    int ans=0;
    for(int i=0;i<=n;++i)
    {
        ans=ans+(a[i].l-a[i-1].r)/m;
    }
    cout<<ans<<endl;
    return 0;
}