#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct obj
{
    int mn=0,cnt=0;
    int lazy=0;
    void pull(obj &a,obj &b)
    {
        mn=min(a.mn,b.mn);
        cnt=((a.mn==mn)*a.cnt+(b.mn==mn)*b.cnt);
    }
    void apply(int l)
    {
        mn+=l;
        lazy+=l;
    }
    void push(obj &a,obj &b)
    {
        a.apply(lazy);
        b.apply(lazy);
        lazy=0;
    }
};

const int N=100005;
vector<obj> tree(4*N);

void build(int idx,int l,int r)
{
    if(l==r) tree[idx].cnt=1;
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tree[idx].pull(tree[2*idx],tree[2*idx+1]);
    }
}

void update(int idx,int l,int r,int ql,int qr,int x)
{
    if(ql>qr) return;
    if(l==ql&&r==qr) tree[idx].apply(x);
    else
    {
        int m=(l+r)/2;
        tree[idx].push(tree[2*idx],tree[2*idx+1]);
        update(2*idx,l,m,ql,min(qr,m),x);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,x);
        tree[idx].pull(tree[2*idx],tree[2*idx+1]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<string> s(n+1);
    for(int i=1;i<=n;i++)
    {
        cin >> s[i];
        s[i]="$"+s[i];
    }
    auto id=[&](int r,int c)->int{return (r-1)*m+c;};
    vector<int> v[n*m+2];
    vector<int> o(n*m+1,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int r=i,c=j;
            int x=id(i,j);
            if(s[i][j]=='U'){r+=2;o[x]=id(i+1,j);}
            if(s[i][j]=='D'){r-=2;o[x]=id(i-1,j);}
            if(s[i][j]=='L'){c+=2;o[x]=id(i,j+1);}
            if(s[i][j]=='R'){c-=2;o[x]=id(i,j-1);}
            int y=id(r,c);
            if(!(1<=r&&r<=n&&1<=c&&c<=m)) y=(((i+j)&1)*(n*m+1));
            v[y].push_back(x);
        }
    }
    vector<int> tin(n*m+2,0);
    vector<int> tout(n*m+2,0);
    int tcnt=-1;
    function<void(int)> dfs=[&](int a)
    {
        tin[a]=++tcnt;
        for(int to:v[a]) dfs(to);
        tout[a]=tcnt;
    };
    dfs(n*m+1);
    build(1,1,n*m/2);
    ll res=0;
    function<void(int)> go=[&](int a)
    {
        if(o[a]!=0) update(1,1,n*m/2,tin[o[a]],tout[o[a]],1);
        int bad=(tree[1].mn==0?tree[1].cnt:0);
        res+=(n*m/2-bad);
        for(int to:v[a]) go(to);
        if(o[a]!=0) update(1,1,n*m/2,tin[o[a]],tout[o[a]],-1);
    };
    go(0);
    cout << res << "\n";
    return 0;
}