#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=200005;
struct ban
{
    int l,r,d,u;
};

int n,q;
int x[N];
ban b[N];

vector<int> qd0[N],qd1[N];
vector<int> qu0[N],qu1[N];

map<int,int> ad0[N],ad1[N];
map<int,int> au0[N],au1[N];

int t[N*4];
void ubd(int tl,int tr,int x,int pos)
{
    if(tl==tr)
    {
        t[pos]++;
        return;
    }
    int m=(tl+tr)/2;
    if(x<=m)
        ubd(tl,m,x,pos*2);
    else
        ubd(m+1,tr,x,pos*2+1);
    t[pos]=t[pos*2]+t[pos*2+1];
}

int qry(int tl,int tr,int l,int r,int pos)
{
    if(r<l)
        return 0;
    if(tl==l && tr==r)
        return t[pos];
    int m=(tl+tr)/2;
    if(r<=m)
        return qry(tl,m,l,r,pos*2);
    if(l>m)
        return qry(m+1,tr,l,r,pos*2+1);
    return qry(tl,m,l,m,pos*2)+qry(m+1,tr,m+1,r,pos*2+1);
}

long long qan(long long x)
{
    return x*(x-1)/2;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("forest.in","r",stdin);
    //freopen("forest.out","w",stdout);
    scanf("%d%d",&n,&q);
    //cin>>n>>q;
    for(int i=1;i<=n;++i)
        scanf("%d",&x[i]);
        //cin>>x[i];
    for(int i=0;i<q;++i)
        scanf("%d%d%d%d",&b[i].l,&b[i].d,&b[i].r,&b[i].u);
        //cin>>b[i].l>>b[i].d>>b[i].r>>b[i].u;
    for(int i=0;i<q;++i)
    {
        qd0[b[i].l-1].push_back(b[i].d-1);
        qd1[b[i].r+1].push_back(b[i].d-1);
        qu0[b[i].l-1].push_back(b[i].u+1);
        qu1[b[i].r+1].push_back(b[i].u+1);
    }
    for(int i=1;i<=n;++i)
    {
        ubd(1,n,x[i],1);
        for(int j=0;j<qd0[i].size();++j)
            ad0[i][qd0[i][j]]=qry(1,n,1,qd0[i][j],1);
        for(int j=0;j<qu0[i].size();++j)
            au0[i][qu0[i][j]]=qry(1,n,qu0[i][j],n,1);
    }
    memset(t,0,sizeof t);
    for(int i=n;i>=1;--i)
    {
        ubd(1,n,x[i],1);
        for(int j=0;j<qd1[i].size();++j)
            ad1[i][qd1[i][j]]=qry(1,n,1,qd1[i][j],1);
        for(int j=0;j<qu1[i].size();++j)
            au1[i][qu1[i][j]]=qry(1,n,qu1[i][j],n,1);
    }
    for(int i=0;i<q;++i)
    {
        int l=b[i].l,r=b[i].r,d=b[i].d,u=b[i].u;
        long long ans=qan(n);
        ans-=qan(l-1);
        ans-=qan(n-r);
        ans-=qan(d-1);
        ans-=qan(n-u);
        ans+=qan(ad0[l-1][d-1]);
        ans+=qan(ad1[r+1][d-1]);
        ans+=qan(au0[l-1][u+1]);
        ans+=qan(au1[r+1][u+1]);
        cout<<ans<<endl;
    }
    return 0;
}