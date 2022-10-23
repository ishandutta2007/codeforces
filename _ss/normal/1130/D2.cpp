#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=5e3+1;;
int n,m,x,y,d=0,min2[maxn],a[maxn],t;
int main()
{
    //freopen("toy.inp","r",stdin);
    //freopen("toy.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) min2[i]=1e9;
    for (int i=1;i<=m;i++)
    {
        cin>>x>>y;
        a[x]++;
        d=max(d,a[x]);
        t=y-x;
        if (t<0) t=t+n;
        min2[x]=min(min2[x],t);
    }
    ll kq=(d-2)*n;
    int max2=0;
    for (int i=1;i<=n;i++)
    {
        if (d>0) kq=(d-2)*n; else kq=0;
        max2=0;
        if (d>1)
        {
        for (int j=i;j<=n;j++)
            if (a[j]==d-1) max2=max(max2,min2[j]+(j-i));
        for (int j=1;j<i;j++)
            if (a[j]==d-1) max2=max(max2,min2[j]+j+(n-i));
        }
        for (int j=i;j<=n;j++)
            if (a[j]==d) max2=max(max2,min2[j]+n+(j-i));
        for (int j=1;j<i;j++)
            if (a[j]==d) max2=max(max2,min2[j]+n+j+(n-i));
        cout<<kq+max2<<endl;
    }
    return 0;
}