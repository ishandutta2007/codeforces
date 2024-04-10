#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vt) vt.begin(),vt.end()
const ll maxn=1e5+10,mod=1e9+7,inf=1e18;

struct ds { int sum,minv,maxv,l_max,r_max,l_min,r_min,pre_min,pre_max,suf_min,suf_max,pre_vtmin,pre_vtmax,suf_vtmin,suf_vtmax; };

struct ds2
{
    int val,l,r,u,v;
    bool operator < (ds2 const &obj) const { return val < obj.val; }
    bool operator > (ds2 const &obj) const { return val > obj.val; }
};

ds combine(ds left_child,ds right_child)
{
    if (!left_child.l_max) return right_child;
    if (!right_child.l_max) return left_child;
    ds res;
    if (left_child.maxv>right_child.maxv)
    {
        res.maxv=left_child.maxv;
        res.l_max=left_child.l_max;
        res.r_max=left_child.r_max;
    }
    else
    {
        res.maxv=right_child.maxv;
        res.l_max=right_child.l_max;
        res.r_max=right_child.r_max;
    }
    if (left_child.suf_max+right_child.pre_max>res.maxv)
    {
        res.maxv=left_child.suf_max+right_child.pre_max;
        res.l_max=left_child.suf_vtmax;
        res.r_max=right_child.pre_vtmax;
    }
    if (left_child.suf_max+right_child.sum>right_child.suf_max)
    {
        res.suf_max=left_child.suf_max+right_child.sum;
        res.suf_vtmax=left_child.suf_vtmax;
    }
    else
    {
        res.suf_max=right_child.suf_max;
        res.suf_vtmax=right_child.suf_vtmax;
    }
    if (right_child.pre_max+left_child.sum>left_child.pre_max)
    {
        res.pre_max=right_child.pre_max+left_child.sum;
        res.pre_vtmax=right_child.pre_vtmax;
    }
    else
    {
        res.pre_max=left_child.pre_max;
        res.pre_vtmax=left_child.pre_vtmax;
    }



    if (left_child.minv<right_child.minv)
    {
        res.minv=left_child.minv;
        res.l_min=left_child.l_min;
        res.r_min=left_child.r_min;
    }
    else
    {
        res.minv=right_child.minv;
        res.l_min=right_child.l_min;
        res.r_min=right_child.r_min;
    }
    if (left_child.suf_min+right_child.pre_min<res.minv)
    {
        res.minv=left_child.suf_min+right_child.pre_min;
        res.l_min=left_child.suf_vtmin;
        res.r_min=right_child.pre_vtmin;
    }
    if (left_child.suf_min+right_child.sum<right_child.suf_min)
    {
        res.suf_min=left_child.suf_min+right_child.sum;
        res.suf_vtmin=left_child.suf_vtmin;
    }
    else
    {
        res.suf_min=right_child.suf_min;
        res.suf_vtmin=right_child.suf_vtmin;
    }
    if (right_child.pre_min+left_child.sum<left_child.pre_min)
    {
        res.pre_min=right_child.pre_min+left_child.sum;
        res.pre_vtmin=right_child.pre_vtmin;
    }
    else
    {
        res.pre_min=left_child.pre_min;
        res.pre_vtmin=left_child.pre_vtmin;
    }
    res.sum=left_child.sum+right_child.sum;
    return res;
}

ds it[maxn*4];
int a[maxn],n;

void build(int id,int l,int r)
{
    if (l==r)
    {
        it[id]={a[l],a[l],a[l],l,l,l,l,a[l],a[l],a[l],a[l],l,l,l,l};
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    it[id]=combine(it[id*2],it[id*2+1]);
}

void update(int id,int l,int r,int v,int x)
{
    if (l==r)
    {
        it[id]={x,x,x,l,l,l,l,x,x,x,x,l,l,l,l};
        return;
    }
    int mid=(l+r)/2;
    if (v<=mid) update(id*2,l,mid,v,x);
    else update(id*2+1,mid+1,r,v,x);
    it[id]=combine(it[id*2],it[id*2+1]);
}

ds get(int id,int l,int r,int u,int v)
{
    if (l>v || r<u) return {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    if (u<=l && r<=v) return it[id];
    int mid=(l+r)/2;
    return combine(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}

int query(int l,int r,int k)
{
    priority_queue<ds2> max_heap;
    priority_queue<ds2,vector<ds2>,greater<ds2>> min_heap;
    ds tmp=get(1,1,n,l,r);
    int res=tmp.maxv;
    if (res<0) return 0;
    if (tmp.r_max<r)
    {
        ds tmp2=get(1,1,n,tmp.r_max+1,r);
        max_heap.push({tmp2.maxv,tmp.r_max+1,r,tmp2.l_max,tmp2.r_max});
    }
    if (l<tmp.l_max)
    {
        ds tmp2=get(1,1,n,l,tmp.l_max-1);
        max_heap.push({tmp2.maxv,l,tmp.l_max-1,tmp2.l_max,tmp2.r_max});
    }
    ds tmp2=get(1,1,n,tmp.l_max,tmp.r_max);
    min_heap.push({tmp2.minv,tmp.l_max,tmp.r_max,tmp2.l_min,tmp2.r_min});
    for (int i=2;i<=k;i++)
    if (!max_heap.empty() && max_heap.top().val>-min_heap.top().val)
    {
        ds2 tmp3=max_heap.top();
        max_heap.pop();
        int val=tmp3.val,l1=tmp3.l,r1=tmp3.r,u=tmp3.u,v=tmp3.v;
        if (val<=0) break;
        if (l1<u)
        {
            tmp2=get(1,1,n,l1,u-1);
            max_heap.push({tmp2.maxv,l1,u-1,tmp2.l_max,tmp2.r_max});
        }
        if (v<r1)
        {
            tmp2=get(1,1,n,v+1,r1);
            max_heap.push({tmp2.maxv,v+1,r1,tmp2.l_max,tmp2.r_max});
        }
        tmp2=get(1,1,n,u,v);
        min_heap.push({tmp2.minv,u,v,tmp2.l_min,tmp2.r_min});
        res+=val;
    }
    else
    {
        ds2 tmp3=min_heap.top();
        min_heap.pop();
        int val=-tmp3.val,l1=tmp3.l,r1=tmp3.r,u=tmp3.u,v=tmp3.v;
        if (val<=0) break;
        tmp2=get(1,1,n,u,v);
        max_heap.push({tmp2.maxv,u,v,tmp2.l_max,tmp2.r_max});
        if (l1<u)
        {
            tmp2=get(1,1,n,l1,u-1);
            min_heap.push({tmp2.minv,l1,u-1,tmp2.l_min,tmp2.r_min});
        }
        if (v<r1)
        {
            tmp2=get(1,1,n,v+1,r1);
            min_heap.push({tmp2.minv,v+1,r1,tmp2.l_min,tmp2.r_min});
        }
        res+=val;
    }
    return res;
}

void read()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
}

void process()
{
    int m;
    cin>>m;
    for (int i=1,t,l,r,k;i<=m;i++)
    {
        cin>>t>>l>>r;
        if (!t) update(1,1,n,l,r);
        else
        {
            cin>>k;
            cout<<query(l,r,k)<<"\n";
        }
    }
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    read();
    build(1,1,n);
    process();
    return 0;
}