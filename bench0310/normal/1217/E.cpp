#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int inf=(1<<30)-1;
const int N=200005;
array<int,9> id={inf,inf,inf,inf,inf,inf,inf,inf,inf};
struct node
{
    array<int,9> a;
    int best;
    node(){a=id;best=2*inf;}
};
vector<node> tree(4*N,node());
vector<int> val(N,0);

int h(int a)
{
    int x=0;
    for(int i=0;i<9;i++)
    {
        if((a%10)>0) x|=(1<<i);
        a/=10;
    }
    return x;
}

node operator+(const node &a,const node &b)
{
    if(a.a==id) return b;
    if(b.a==id) return a;
    node c;
    c.best=min(a.best,b.best);
    for(int i=0;i<9;i++)
    {
        if(a.a[i]!=inf&&b.a[i]!=inf) c.best=min(c.best,a.a[i]+b.a[i]);
        c.a[i]=min(a.a[i],b.a[i]);
    }
    return c;
}

void build(int idx,int l,int r)
{
    if(l==r)
    {
        int x=h(val[l]);
        for(int i=0;i<9;i++) if(x&(1<<i)) tree[idx].a[i]=val[l];
    }
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tree[idx]=tree[2*idx]+tree[2*idx+1];
    }
}

void update(int idx,int l,int r,int pos)
{
    if(l==r)
    {
        tree[idx].a=id;
        int x=h(val[l]);
        for(int i=0;i<9;i++) if(x&(1<<i)) tree[idx].a[i]=val[l];
    }
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos);
        else update(2*idx+1,m+1,r,pos);
        tree[idx]=tree[2*idx]+tree[2*idx+1];
    }
}

node query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return node();
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return query(2*idx,l,m,ql,min(qr,m))+query(2*idx+1,m+1,r,max(ql,m+1),qr);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> val[i];
    build(1,1,n);
    while(m--)
    {
        int t,a,b;
        cin >> t >> a >> b;
        if(t==1)
        {
            val[a]=b;
            update(1,1,n,a);
        }
        else
        {
            int res=query(1,1,n,a,b).best;
            if(res==2*inf) res=-1;
            cout << res << "\n";
        }
    }
    return 0;
}