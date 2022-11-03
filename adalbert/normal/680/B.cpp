#include <bits/stdc++.h>;
#define fin freopen("cakes.in","r",stdin)
#define fout freopen("cakes.out","w",stdout)
using namespace std;
long long ans,n,t,t2,t3,t4,t5,mx,a[1000],k;

int main()
{
   // fin;
    //fout;
    cin>>n>>t;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int j=1;j<=n-1;j++)
    {
        if (t-j<1) ans+=a[t+j]; else
        if (t+j>n) ans+=a[t-j]; else
        if ((a[t-j]==1)&&(a[t+j]==1)) ans+=2;
    }
    cout<<ans+a[t];
}