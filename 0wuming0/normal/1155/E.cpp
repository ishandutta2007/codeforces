#include"stdio.h"
#include"string.h"
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
ll mod=1000003;
ll mu(ll a,ll b,ll c)
{
    return a*b%mod*c%mod;
}
ll det3(ll a[3][3])
{
    return mu(a[0][0],a[1][1],a[2][2])+mu(a[0][1],a[1][2],a[2][0])+mu(a[0][2],a[1][0],a[2][1])-\
           mu(a[0][2],a[1][1],a[2][0])-mu(a[0][0],a[1][2],a[2][1])-mu(a[0][1],a[1][0],a[2][2]);
}
ll det4(ll a[4][4])
{
#define n 3
#define dn det3
    ll s=0,i,j;
    ll b[n][n];
#define t 0//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 1//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 2//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 3//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#undef n
#undef dn
    return s%mod;
}
ll det5(ll a[5][5])
{
#define n 4
#define dn det4
    ll s=0,i,j;
    ll b[n][n];
#define t 0//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 1//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 2//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 3//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 4//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#undef n
#undef dn
    return s%mod;
}
ll det6(ll a[6][6])
{
#define n 5
#define dn det5
    ll s=0,i,j;
    ll b[n][n];
#define t 0//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 1//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 2//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 3//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 4//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 5//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#undef n
#undef dn
    return s%mod;
}
ll det7(ll a[7][7])
{
#define n 6
#define dn det6
    ll s=0,i,j;
    ll b[n][n];
#define t 0//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 1//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 2//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 3//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 4//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 5//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 6//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#undef n
#undef dn
    return s%mod;
}
ll det8(ll a[8][8])
{
#define n 7
#define dn det7
    ll s=0,i,j;
    ll b[n][n];
#define t 0//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 1//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 2//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 3//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 4//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 5//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 6//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 7//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#undef n
#undef dn
    return s%mod;
}
ll det9(ll a[9][9])
{
#define n 8
#define dn det8
    ll s=0,i,j;
    ll b[n][n];
#define t 0//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 1//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 2//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 3//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 4//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 5//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 6//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 7//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 8//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#undef n
#undef dn
    return s%mod;
}
ll det10(ll a[10][10])
{
#define n 9
#define dn det9
    ll s=0,i,j;
    ll b[n][n];
#define t 0//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 1//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 2//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 3//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 4//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 5//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 6//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 7//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 8//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#define t 9//////////
    for(i=1;i<=n;i++)for(j=0;j<=n;j++)if(j!=t)b[i-1][j-(j>t)]=a[i][j];
    if(t%2)s-=a[0][t]*dn(b);else s+=a[0][t]*dn(b);
#undef t
#undef n
#undef dn
    return s%mod;
}
ll pows(ll a,ll b)
{
    ll ans=1;
    for(;b;a=a*a%mod,b/=2)if(b%2)ans=ans*a%mod;
    return ans;
}
void copys(ll a[10][10],ll b[10][10])
{
    ll i,j;
    for(i=0;i<10;i++)for(j=0;j<10;j++)a[i][j]=b[i][j];
}
int main()
{
    ll i,j;
    ll a[10][10],re[10][10],k[12],b[12];
    for(i=0;i<10;i++)for(j=0;j<10;j++)a[i][j]=pows(i+1,j+1);
    //printf("%lld\n",pows(det10(a)+mod,mod-2));
    ll m=193379;
    cout<<"? 0"<<endl;
    scanf("%lld",k);
    for(i=1;i<=10;i++)
    {
        cout<<"? "<<i<<endl;
        scanf("%lld",b+i-1);
        b[i-1]-=k[0];
    }
    fflush(stdout);
    for(i=0;i<10;i++)
    {
        copys(re,a);
        for(j=0;j<10;j++)
        {
            re[j][i]=b[j];
        }
        k[i+1]=m*det10(re)%mod;
        if(k[i+1]<0)k[i+1]+=mod;
    }
    for(i=0;i<mod;i++)
#define x(a) k[a]*pows(i,a)
        if((k[0]+x(1)+x(2)+x(3)+x(4)+x(5)+x(6)+x(7)+x(8)+x(9)+x(10))%mod==0)
#undef x
        {
            printf("! %lld\n",i);
            return 0;
        }
    cout<<"! -1"<<endl;
    return 0;
}