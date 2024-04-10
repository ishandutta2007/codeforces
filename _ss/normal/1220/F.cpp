#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define all(vr) vr.begin(),vr.end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
const int N=4e5+10;
int n,a[N],L[N],R[N];

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

    void upd(int u,int v,int val,int len) {update_range(1,1,len,u,v,val);}
    int getv(int u,int v,int len) {return get(1,1,len,u,v); }
} seg;

void read()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
}

void process()
{
    for (int i=1;i<=n;i++) a[i+n]=a[i];
    stack<int> st;
    a[0]=0;
    st.push(0);
    for (int i=1;i<=n*2;i++)
    {
        while (a[i]<a[st.top()]) st.pop();
        L[i]=st.top()+1;
        st.push(i);
    }
    while (!st.empty()) st.pop();
    a[2*n+1]=0;
    st.push(2*n+1);
    for (int i=n*2;i;i--)
    {
        while (a[i]<a[st.top()]) st.pop();
        R[i]=st.top()-1;
        st.push(i);
    }
    for (int i=1;i<=n;i++)
    {
        if (L[i]<i) seg.upd(L[i],i-1,1,n*2);
        if (i<R[i]) seg.upd(i+1,R[i],1,n*2);
    }
    int k=0,val=seg.getv(1,n,n*2);
    for (int i=1;i<n;i++)
    {
        if (i<R[i]) seg.upd(i+1,R[i],-1,n*2);
        if (L[n+i]<n+i) seg.upd(L[n+i],n+i-1,1,n*2);
        if (n+i<R[n+i]) seg.upd(n+i+1,R[n+i],1,n*2);
        int nv=seg.getv(i+1,i+n,n*2);
        if (nv<val) val=nv,k=i;
    }
    cout<<val+1<<" "<<k;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    process();
    return 0;
}