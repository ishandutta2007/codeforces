#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=1000000;
vector<ll> cookies(4*(N+5),0);
vector<ll> req(4*(N+5),0);

void update(int idx,int l,int r,int pos,int val)
{
    if(l==r)
    {
        cookies[idx]+=val;
        req[idx]+=(ll(val)*pos);
    }
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,val);
        else update(2*idx+1,m+1,r,pos,val);
        cookies[idx]=cookies[2*idx]+cookies[2*idx+1];
        req[idx]=req[2*idx]+req[2*idx+1];
    }
}

ll opt(int idx,int l,int r,ll t)
{
    if(l==r) return min(cookies[idx],t/l);
    int m=(l+r)/2;
    if(req[2*idx]>t) return opt(2*idx,l,m,t);
    else return cookies[2*idx]+opt(2*idx+1,m+1,r,t-req[2*idx]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll t;
    cin >> n >> t;
    vector<ll> x(n+1,0);
    for(int i=1;i<=n;i++) cin >> x[i];
    vector<ll> tx(n+1,0);
    for(int i=1;i<=n;i++) cin >> tx[i];
    vector<array<ll,2>> v[n+1];
    for(int i=2;i<=n;i++)
    {
        ll p,l;
        cin >> p >> l;
        v[p].push_back({i,l});
    }
    vector<ll> mx(n+1,0);
    function<void(int,ll)> dfs=[&](int a,ll now)
    {
        update(1,1,N,tx[a],x[a]);
        mx[a]=opt(1,1,N,max(0ll,t-now));
        vector<ll> nxt;
        for(auto [to,l]:v[a])
        {
            dfs(to,now+2*l);
            nxt.push_back(mx[to]);
        }
        sort(nxt.begin(),nxt.end(),greater<ll>());
        if(nxt.size()>=2) mx[a]=max(mx[a],nxt[1]);
        if(a==1) mx[a]=max(mx[a],nxt[0]);
        update(1,1,N,tx[a],-x[a]);
    };
    dfs(1,0);
    cout << mx[1] << "\n";
    return 0;
}