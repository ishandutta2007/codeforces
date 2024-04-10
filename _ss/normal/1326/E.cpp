#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e6+10;
int n,p[N],q[N],vt[N];

struct segment_tree
{
    int it[N*4],lazy[N*4];

    int combine(int t1,int t2)
    {
        return max(t1,t2);
    }

    void down(int id)
    {
        int tmp=lazy[id];
        it[id*2]+=tmp;
        it[id*2+1]+=tmp;
        lazy[id*2]+=tmp;
        lazy[id*2+1]+=tmp;
        lazy[id]=0;
    }

    void update_range(int id,int l,int r,int u,int v,int x)
    {
        if (l>v || r<u) return;
        if (u<=l && r<=v)
        {
            it[id]+=x;
            lazy[id]+=x;
            return;
        }
        down(id);
        int mid=(l+r)>>1;
        update_range(id*2,l,mid,u,v,x);
        update_range(id*2+1,mid+1,r,u,v,x);
        it[id]=combine(it[id*2],it[id*2+1]);
    }

    int get(int id,int l,int r,int u,int v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return it[id];
        down(id);
        int mid=(l+r)>>1;
        return combine(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
    }
} seg;

bool check(int x)
{
    return (seg.get(1,1,n,1,n)>0);
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i],vt[p[i]]=i;
    for (int i=1;i<=n;i++) cin>>q[i];
    int res=n;
    cout<<res<<" ";
    seg.update_range(1,1,n,1,vt[res],1);
    for (int i=1;i<n;i++)
    {
        seg.update_range(1,1,n,1,q[i],-1);
        while (!check(res))
        {
            res--;
            seg.update_range(1,1,n,1,vt[res],1);
        }
        cout<<res<<" ";
    }
    return 0;
}