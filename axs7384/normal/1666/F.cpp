#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
const int N=5005;
int c[N],a[N];
int f[N][N];
int fac[N],inv[N];
inline int ksm(int x,int y)
{
    int ans=1;
    for (;y;y/=2,x=(ll)x*x%mod)
        if (y&1)
            ans=(ll)ans*x%mod;
    return ans;
}
inline void prework()
{
    int n=5000;
    fac[0]=1;
    for (int i=1;i<=n;++i)
        fac[i]=(ll)fac[i-1]*i%mod;
    inv[n]=ksm(fac[n],mod-2);
    for (int i=n;i;--i)
        inv[i-1]=(ll)inv[i]*i%mod;
}
int main()
{
    prework();
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;++i)
            c[i]=0;
        for (int i=1;i<=n;++i)
        {    
            scanf("%d",&a[i]);
            ++c[a[i]];
        }
        for (int i=1;i<=n;++i)
            c[i]+=c[i-1];
        for (int i=1;i<=n;++i)
            //if (c[i]!=c[i-1])
                f[1][i]=(ll)(c[i]-c[i-1])*c[i-1]%mod;
        for (int i=2;i<=n/2;++i)
        {
            int sum=0;
            for (int j=1;j<=n;++j)
            {
                f[i][j]=(ll)(c[j]-c[j-1])*sum%mod;
                /*if (c[j]!=c[j-1])
                    f[i][j]=sum;
                else
                    f[i][j]=0;*/
                (sum+=(ll)f[i-1][j]*(c[j-1]-(i-1)*2+1)%mod)%=mod;
                //cout<<i<<' '<<j<<' '<<f[i][j]<<endl;
            }
        }
        int ans=f[n/2][a[n]];
        for (int i=1;i<=n;++i)
            ans=(ll)ans*inv[c[i]-c[i-1]]%mod;
        printf("%d\n",ans);
        //printf("%d\n",f[n/2][a[n]]);
    }
    return 0;
}