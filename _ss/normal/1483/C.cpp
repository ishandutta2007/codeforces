#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N=3e5+10;
const ll inf=1e18;
struct segment_tree
{
    ll it[N*4];

    ll combine(ll t1,ll t2)
    {
        return max(t1,t2);
    }

    void build(int id,int l,int r)
    {
        if (l==r)
        {
            it[id]=-inf;
            return;
        }
        int mid=(l+r)>>1;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        it[id]=combine(it[id*2],it[id*2+1]);
    }

    void update(int id,int l,int r,int v,ll x)
    {
        if (l==r)
        {
            it[id]=x;
            return;
        }
        int mid=(l+r)>>1;
        if (v<=mid) update(id*2,l,mid,v,x);
        else update(id*2+1,mid+1,r,v,x);
        it[id]=combine(it[id*2],it[id*2+1]);
    }

    ll get(int id,int l,int r,int u,int v)
    {
        if (l>v || r<u) return -inf;
        if (u<=l && r<=v) return it[id];
        int mid=(l+r)>>1;
        return combine(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
    }

} seg;

int a[N],h[N],n;
ll dp[N],val[N];

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>h[i];
    for (int i=1;i<=n;i++) cin>>a[i];
    stack<int> st;
    for (int i=1;i<=n;i++)
    {
        val[i]=a[i]+dp[i-1];
        while (!st.empty() && h[st.top()]>h[i])
        {
            val[i]=max(val[i],val[st.top()]-a[st.top()]+a[i]);
            seg.update(1,1,n,st.top(),-inf);
            st.pop();
        }
        seg.update(1,1,n,i,val[i]);
        dp[i]=seg.get(1,1,n,1,i);
        st.push(i);
    }
    cout<<dp[n];
    return 0;
}