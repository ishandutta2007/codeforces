#include <bits/stdc++.h>
#define pb push_back
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll
using namespace std;
typedef long long ll;
typedef long double ld;

int a[300000],sum[300000],b[300000];
int v[1700000];
int n,m;

void pluss(int i, int tl,int tr, int x)
{
    if (tl==tr)
    {
        v[i]++;
        return;
    }
    int d=(tl+tr)/2;

    if (x<=d)
        pluss(i*2,tl,d,x); else
        pluss(i*2+1,d+1,tr,x);

    v[i]=v[i*2]+v[i*2+1];
}

int get(int i, int tl, int tr, int l, int r)
{
    if (tl>=l && tr<=r)
        return(v[i]);
    if (tl>r || tr<l)
        return(0);
    int d=(tl+tr)/2;

    return(get(i*2,tl,d,l,r)+get(i*2+1,d+1,tr,l,r));
}

int get(int u)
{

    for (int i=1;i<=n;i++)
        if (a[i]<u)
        b[i]=-1; else
        b[i]=1;

    int ans=0;
    int nowsum=0;

    for (int i=0;i<8*n;i++)
        v[i]=0;

    pluss(1,0,2*n,n);

    for (int i=1;i<=n;i++)
    {
        nowsum+=b[i];
        ans+=get(1,0,2*n,0,nowsum+n-1);
        pluss(1,0,2*n,nowsum+n);
    }

    return(ans);
}

signed main()
{
    cin>>n>>m;

    for (int i=1;i<=n;i++)
        cin>>a[i];

    cout<<get(m)-get(m+1)<<'\n';
}