#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=2e5+1,maxv=1e7,maxdd=1e6+1;
ll dv;
struct dl
{
    ll l,r,vt;
};
dl q[maxn];
ll n,a[maxn],t,ans[maxn],dd[maxdd];

bool qt(dl t1,dl t2)
{
    return ((((t1.l+dv-1)/dv)*maxv+t1.r)<(((t2.l+dv-1)/dv)*maxv+t2.r));
}

int main()
{
    scanf("%I64d%I64d",&n,&t);
    dv=500;
    for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    for (int i=1;i<=t;i++)
    {
        scanf("%I64d%I64d",&q[i].l,&q[i].r);
        q[i].vt=i;
    }
    sort(q+1,q+t+1,qt);
    ll kq=0;
    for (int i=1;i<=t;i++)
    {
        if (q[i].r>q[i-1].r)
            for (int j=q[i-1].r+1;j<=q[i].r;j++)
            {
                dd[a[j]]++;
                kq=kq+(dd[a[j]]*2-1)*a[j];
            }
        else for (int j=q[i-1].r;j>=q[i].r+1;j--)
            {
                kq=kq-(dd[a[j]]*2-1)*a[j];
                dd[a[j]]--;
            }
        if (q[i].l<q[i-1].l)
            for (int j=q[i-1].l-1;j>=q[i].l;j--)
            {
                dd[a[j]]++;
                kq=kq+(dd[a[j]]*2-1)*a[j];
            }
    else for (int j=q[i-1].l;j<=q[i].l-1;j++)
            {
                kq=kq-(dd[a[j]]*2-1)*a[j];
                dd[a[j]]--;
            }
        ans[q[i].vt]=kq;
    }
    for (int i=1;i<=t;i++) cout<<ans[i]<<endl;
    return 0;
}