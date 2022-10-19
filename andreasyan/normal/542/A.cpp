#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=200005,M=N*8,MM=1000000000;
struct ban
{
    int ll,rr;
    int rll,rrr;
    int l,r;
    int g;
    int i;
};

bool so1(const ban& a,const ban& b)
{
    if(a.r<b.r)
        return true;
    if(a.r>b.r)
        return false;
    return a.g<b.g;
}

bool so2(const ban& a,const ban& b)
{
    if(a.r<b.r)
        return true;
    if(a.r>b.r)
        return false;
    return a.g>b.g;
}

struct bans
{
    bans *l,*r;
    long long maxu;
    int maxi;
    bans()
    {
        l=r=0;
        maxu=maxi=0;
    }
    ~bans(){}
};

void ave(bans* pos)
{
    if(pos->l==0)
        pos->l=new bans;
    if(pos->r==0)
        pos->r=new bans;
}

void ubd(int tl,int tr,int x,int i,long long y,bans* pos)
{
    if(tl==tr)
    {
        if(pos->maxu<y)
        {
            pos->maxu=y;
            pos->maxi=i;
        }
        return;
    }
    ave(pos);
    int m=(tl+tr)/2;
    if(x<=m)
    {
        ubd(tl,m,x,i,y,pos->l);
    }
    else
    {
        ubd(m+1,tr,x,i,y,pos->r);
    }
    if(pos->l->maxu>pos->r->maxu)
    {
        pos->maxu=pos->l->maxu;
        pos->maxi=pos->l->maxi;
    }
    else
    {
        pos->maxu=pos->r->maxu;
        pos->maxi=pos->r->maxi;
    }
}

pair<long long,int> qry(int tl,int tr,int l,int r,bans* pos)
{
    if(tl==l && tr==r)
        return m_p(pos->maxu,pos->maxi);
    int m=(tl+tr)/2;
    if(r<=m)
    {
        if(pos->l==0)
            return m_p(0,0);
        return qry(tl,m,l,r,pos->l);
    }
    if(l>m)
    {
        if(pos->r==0)
            return m_p(0,0);
        return qry(m+1,tr,l,r,pos->r);
    }
    pair<long long,int> ll,rr;
    if(pos->l==0)
        ll=m_p(0,0);
    else
        ll=qry(tl,m,l,m,pos->l);
    if(pos->r==0)
        rr=m_p(0,0);
    else
        rr=qry(m+1,tr,m+1,r,pos->r);
    if(ll.first>rr.first)
        return ll;
    else
        return rr;
}

void qnd(bans* pos)
{
    if(pos->l!=0)
        qnd(pos->l);
    if(pos->r!=0)
        qnd(pos->r);
    delete pos;
}

int n,m;
ban a[N],b[N];

long long ans;
int ans1,ans2;
int main()
{
    //freopen("input.txt","r",stdin);
    vector<ban> v;
    vector<pair<int,int> > u;
    //cin>>n>>m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        a[i].i=i;
        //cin>>a[i].l>>a[i].r;
        scanf("%d%d",&a[i].l,&a[i].r);
        a[i].g=-1;
        u.push_back(m_p(a[i].l,i));
        u.push_back(m_p(a[i].r,i));
        u.push_back(m_p(MM-a[i].l,i));
        u.push_back(m_p(MM-a[i].r,i));
    }
    for(int i=1;i<=m;++i)
    {
        b[i].i=i;
        //cin>>b[i].l>>b[i].r>>b[i].g;
        scanf("%d%d%d",&b[i].l,&b[i].r,&b[i].g);
        u.push_back(m_p(b[i].l,i));
        u.push_back(m_p(b[i].r,i));
        u.push_back(m_p(MM-b[i].l,i));
        u.push_back(m_p(MM-b[i].r,i));
    }
    u.push_back(m_p(0,0));
    //////////////////////////////////////////
    sort(u.begin(),u.end());
    int z=0;
    for(int i=0;i<u.size();++i)
    {
        if(i && u[i].first!=u[i-1].first)
            ++z;
        if(u[i].second>0)
        {
            int j=u[i].second;
            if(a[j].l==u[i].first)
                a[j].ll=z;
            if(a[j].r==u[i].first)
                a[j].rr=z;
            if(MM-a[j].l==u[i].first)
                a[j].rll=z;
            if(MM-a[j].r==u[i].first)
                a[j].rrr=z;
            if(b[j].l==u[i].first)
                b[j].ll=z;
            if(b[j].r==u[i].first)
                b[j].rr=z;
            if(MM-b[j].l==u[i].first)
                b[j].rll=z;
            if(MM-b[j].r==u[i].first)
                b[j].rrr=z;
        }
    }
    for(int i=1;i<=n;++i)
        v.push_back(a[i]);
    for(int i=1;i<=m;++i)
        v.push_back(b[i]);
    //////////////////////////////////////////
    sort(v.begin(),v.end(),so1);
    bans* t=new bans;
    for(int i=0;i<v.size();++i)
    {
        ban x=v[i];
        if(x.g==-1)
            ubd(0,M,x.ll,x.i,(x.r-x.l),t);
        else
        {
            pair<long long,int> y=qry(0,M,x.ll,x.rr,t);
            y.first*=x.g;
            if(y.first>ans)
            {
                ans=y.first;
                ans1=y.second;
                ans2=x.i;
            }
        }
    }
    qnd(t);
    t=new bans;
    for(int i=0;i<v.size();++i)
    {
        ban x=v[i];
        if(x.g==-1)
            ubd(0,M,x.ll,x.i,x.r,t);
        else
        {
            pair<long long,int> y=qry(0,M,0,x.ll,t);
            y.first=y.first-x.l;
            y.first*=x.g;
            if(y.first>ans)
            {
                ans=y.first;
                ans1=y.second;
                ans2=x.i;
            }
        }
    }
    sort(v.begin(),v.end(),so2);
    qnd(t);
    t=new bans;
    for(int i=0;i<v.size();++i)
    {
        ban x=v[i];
        if(x.g!=-1)
            ubd(0,M,x.ll,x.i,1LL*x.g*(x.r-x.l),t);
        else
        {
            pair<long long,int> y=qry(0,M,x.ll,x.rr,t);
            if(y.first>ans)
            {
                ans=y.first;
                ans1=x.i;
                ans2=y.second;
            }
        }
    }
    for(int i=0;i<v.size();++i)
    {
        ban x=v[i];
        v[i].r=MM-x.l;
        v[i].l=MM-x.r;
        v[i].rr=v[i].rll;
        v[i].ll=v[i].rrr;
    }
    sort(v.begin(),v.end(),so1);
    qnd(t);
    t=new bans;
    for(int i=0;i<v.size();++i)
    {
        ban x=v[i];
        if(x.g==-1)
            ubd(0,M,x.ll,x.i,x.r,t);
        else
        {
            pair<long long,int> y=qry(0,M,0,x.ll,t);
            y.first=y.first-x.l;
            y.first*=x.g;
            if(y.first>ans)
            {
                ans=y.first;
                ans1=y.second;
                ans2=x.i;
            }
        }
    }
    //////////////////////////////////////////
    cout<<ans<<endl;
    if(ans)
    {
        cout<<ans1<<' '<<ans2<<endl;
    }
    return 0;
}