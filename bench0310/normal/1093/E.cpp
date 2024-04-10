#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //CDQ D&C
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1,0);
    vector<int> p(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        p[a[i]]=i;
    }
    vector<int> b(n+1,0);
    vector<int> q(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin >> b[i];
        q[b[i]]=i;
    }
    vector<array<int,4>> e;
    for(int i=1;i<=n;i++) e.push_back({0,p[i],q[i],1});
    vector<bool> is_query(m+1,0);
    vector<int> res(m+1,0);
    for(int i=1;i<=m;i++)
    {
        int t;
        cin >> t;
        if(t==1)
        {
            is_query[i]=1;
            int la,ra,lb,rb;
            cin >> la >> ra >> lb >> rb;
            e.push_back({i,ra,rb,1});
            e.push_back({i,ra,lb-1,-1});
            e.push_back({i,la-1,rb,-1});
            e.push_back({i,la-1,lb-1,1});
        }
        else
        {
            int x,y;
            cin >> x >> y;
            int c=b[x],d=b[y];
            e.push_back({i,p[c],q[c],-1});
            e.push_back({i,p[d],q[d],-1});
            swap(b[x],b[y]);
            swap(q[b[x]],q[b[y]]);
            e.push_back({i,p[c],q[c],1});
            e.push_back({i,p[d],q[d],1});
        }
    }
    vector<int> s(n+1,0);
    auto upd=[&](int i,int d)
    {
        for(;i<=n;i=(i|(i+1))) s[i]+=d;
    };
    auto sum=[&](int i)->int
    {
        int r=0;
        for(;i>=0;i=(i&(i+1))-1) r+=s[i];
        return r;
    };
    function<void(int,int)> go=[&](int l,int r)
    {
        if(l==r) return;
        int mid=(l+r)/2;
        vector<array<int,5>> v;
        for(int i=l;i<=r;i++) v.push_back({e[i][1],(i>mid),e[i][2],e[i][3],e[i][0]});
        ranges::sort(v);
        for(auto [x,half,y,d,t]:v)
        {
            if(half==0&&!is_query[t]) upd(y,d);
            if(half==1&&is_query[t]) res[t]+=(d*sum(y));
        }
        for(auto [x,half,y,d,t]:v) if(half==0&&!is_query[t]) upd(y,-d);
        go(l,mid);
        go(mid+1,r);
    };
    go(0,(int)e.size()-1);
    for(int i=1;i<=m;i++) if(is_query[i]) cout << res[i] << "\n";
    return 0;
}