#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md=1e9+7;
ll n,k,l,x,y,a[1000001],m,tep,v[5000001],sum[1000001],ans[1000001];
string st1,st2;
vector<long long > vec;
map<long long  , long long > last;



struct otr
{
    long long  r,l,nom;
};


void xorr (ll i, ll l, ll r, ll x, ll y)
{
    if (l==r)
    {
        v[i]^=y;
        return;
    }
    ll d=(l+r)/2;
    if (x<=d) xorr (i*2,l,d,x,y); else xorr (i*2+1,d+1,r,x,y);
    v[i]=v[i*2]^v[i*2+1];
}



ll getsum(ll i,ll l, ll r, ll l1,ll r1 )
{
    if (l>r1 || r<l1) return(0); else
        if (l>=l1 && r<=r1 ) return(v[i]);
    ll d=(l+r)/2;
    return(getsum(i*2,l,d,l1,r1)^getsum(i*2+1,d+1,r,l1,r1));
}



otr b[1000001];
bool check(otr i,otr j)
{
    return(i.r<j.r);
}



int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d",&b[i].l);
        scanf("%d",&b[i].r);
        b[i].nom=i;
    }
    sort(b+1,b+1+m,check);
    tep=1;
    for (int i=1;i<=n;i++)
    {
        if (last[a[i]]!=0)
        xorr(1,1,n,last[a[i]],a[i]);
        xorr(1,1,n,i,a[i]);
        last[a[i]]=i;
        sum[i]=sum[i-1]^a[i];
        while (b[tep].r==i)
        {
            ans[b[tep].nom]=sum[i]^sum[b[tep].l-1]^getsum(1,1,n,b[tep].l,b[tep].r);
            tep++;
        }
    }
    for (int i=1;i<=m;i++)
    cout<<ans[i]<<'\n';

}