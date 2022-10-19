#include <bits/stdc++.h>
using namespace std;
const int N=100005;

int n;
int a[N];

int pz[N],sm[N];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("hall.in","r",stdin);
    //freopen("hall.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i)
    {
        pz[i]=pz[i-1];
        if(a[i]==0)
            pz[i]++;
    }
    for(int i=n;i>=1;--i)
    {
        sm[i]=sm[i+1];
        if(a[i]==1)
            sm[i]++;
    }
    int ans=0;
    for(int i=0;i<=n;++i)
        ans=max(ans,pz[i]+sm[i+1]);
    cout<<ans<<endl;
    return 0;
}