#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define int long long
const int N=5003,INF=5000000000000;

int n;
int a[N];
int p[N],s[N];

int pp[N],psum[N];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("river.in","r",stdin);
    //freopen("river.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    p[0]=a[0];
    for(int i=1;i<n;++i)
        p[i]=p[i-1]+a[i];
    for(int i=n-1;i>=0;--i)
        s[i]=s[i+1]+a[i];
    //////////////////////////////////
    for(int i=0;i<=n;++i)
    {
        psum[i]=-INF;
        pp[i]=-1;
    }
    for(int i=0;i<=n;++i)
    {
        int sum=0;
        for(int j=i;j>=0;--j)
        {
            if(i!=j)
                sum+=a[j];
            if(+(p[j]-a[j])-sum>psum[i])
            {
                psum[i]=+(p[j]-a[j])-sum;
                pp[i]=j;
            }
        }
    }
    int ans=-INF;
    int ans1=-1,ans2=-1,ans3=-1;
    for(int i=0;i<=n;++i)
    {
        int sum=0;
        for(int j=i;j<=n;++j)
        {
            if(i!=j)
                sum+=a[j-1];
            if(+psum[i]+sum-s[j]>ans)
            {
                ans=+psum[i]+sum-s[j];
                ans1=pp[i];
                ans2=i;
                ans3=j;
            }
        }
    }
    cout<<ans1<<' '<<ans2<<' '<<ans3<<endl;
    return 0;
}