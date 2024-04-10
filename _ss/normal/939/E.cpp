#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ld,ll>
#define fi first
#define se second
const ll maxn=5e5+1;
ll Q[maxn],q,n=0,col[maxn],maxvt=0;
pii b[maxn];
ld a[maxn],d[maxn],maxx=0;
void read()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>q;
    for (int i=1;i<=q;i++)
    {
        cin>>Q[i];
        //scanf("%d",&Q[i]);
        if (Q[i]==1)
        {
            cin>>d[i];
            //scanf("%lf",&d[i]);
            n++;
            b[n]={d[i],i};
        }
    }
}

void add(ll vt,ld x)
{
    for (int i=vt;i<=n;i+=i&-i) a[i]+=x;
}

ld sum(ll vt)
{
    ld kq=0;
    for (int i=vt;i;i-=i&-i) kq+=a[i];
    return kq;
}

ld ans(ll vt)
{
    if (vt<=0) return maxx;
    else if (vt==maxvt) return ans(maxvt-1);
    return (sum(vt)+maxx)/(vt+1);
}

ld bs()
{
    ll l=0,r=maxvt-1,mid;
    ld kq0,kq=0,kq1;
    while (l<=r)
    {
        mid=(l+r)/2;
        kq0=ans(mid-1);
        kq=ans(mid);
        kq1=ans(mid+1);
        if (kq<=kq0 && kq>=kq1) l=mid+1;
        else if (kq>=kq0 && kq<=kq1) r=mid-1;
        else if (kq<=kq0 && kq<=kq1) return kq;
    }
    return kq;
}

void process()
{
    sort(b+1,b+n+1);
    for (int i=1;i<=n;i++) col[b[i].se]=i;
    for (int i=1;i<=q;i++)
        if (Q[i]==1)
        {
            add(col[i],d[i]);
            maxx=max(maxx,d[i]);
            maxvt=max(maxvt,col[i]);
        }
        else //cout<<maxx-bs()<<endl;
        {
            double tt=maxx-bs();
            printf("%0.9lf\n",tt);
        }
}

int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    process();
    return 0;
}