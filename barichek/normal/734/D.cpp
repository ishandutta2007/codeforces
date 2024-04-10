#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pi pair<ll,ll>
using namespace std;
const ll inf=2000000001;
ll n,x[500005],y[500005],a[500005],z,i,j,k,l,r,b,c,mnx,mxx,mny,mxy,d1,d2,d3,d4,t1,t2,t3,t4,t5,t6,t7,t8;
char q;
int main()
{
    cin >>n;
    cin >>l>>r;
    for (i=1;i<=n;++i)
    {
        cin >>q>>x[i]>>y[i];
        if (q=='B')a[i]=0;else if (q=='R')a[i]=1;else a[i]=2;
    }
    t1=0;t2=0;t3=0;t4=0;t5=1;t6=1;t7=1;t8=1;
    mxy=-inf;
    mny=inf;
    mxx=-inf;
    mnx=inf;
    d1=inf;
    d2=inf;
    d3=inf;
    d4=inf;
    for (i=1;i<=n;++i)
    {
        if (x[i]==l)
        {
            if (y[i]<r&&y[i]>mxy)
            {
                mxy=y[i];
                t1=a[i];
            }
            if (y[i]>r&&y[i]<mny)
            {
                mny=y[i];
                t2=a[i];
            }
            continue;
        }
        if (y[i]==r)
        {
            if (x[i]<l&&x[i]>mxx)
            {
                mxx=x[i];
                t3=a[i];
            }
            if (x[i]>l&&x[i]<mnx)
            {
                mnx=x[i];
                t4=a[i];
            }
            continue;
        }
        if (abs(x[i]-l)!=abs(y[i]-r))continue;
        z=abs(x[i]-l);
        if (x[i]<l&&y[i]<r&&z<d1)
        {
            d1=z;
            t5=a[i];
        }
        if (x[i]<l&&y[i]>r&&z<d2)
        {
            d2=z;
            t6=a[i];
        }
        if (x[i]>l&&y[i]<r&&z<d3)
        {
            d3=z;
            t7=a[i];
        }
        if (x[i]>l&&y[i]>r&&z<d4)
        {
            d4=z;
            t8=a[i];
        }
    }
    if (t1!=-0||t2!=0||t3!=0||t4!=0||t5!=1||t6!=1||t7!=1||t8!=1)cout <<"YES";else cout <<"NO";
}