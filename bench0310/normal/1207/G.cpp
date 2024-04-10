#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int K=26;

struct Vertex
{
    char c;
    int p;
    array<int,K> trie;
    array<int,K> go;
    int link;
    Vertex(char nc='$',int np=-1):c(nc),p(np)
    {
        trie.fill(-1);
        go.fill(-1);
        link=-1;
    }
};

vector<Vertex> ac(1);

int add(string s)
{
    int now=0;
    for(char t:s)
    {
        int c=(t-'a');
        if(ac[now].trie[c]==-1)
        {
            ac[now].trie[c]=ac.size();
            ac.push_back(Vertex(t,now));
        }
        now=ac[now].trie[c];
    }
    return now;
}

int go(int a,char t);

int get_link(int a)
{
    if(ac[a].link==-1)
    {
        if(a==0||ac[a].p==0) ac[a].link=0;
        else ac[a].link=go(get_link(ac[a].p),ac[a].c);
    }
    return ac[a].link;
}

int go(int a,char t)
{
    int c=(t-'a');
    if(ac[a].go[c]==-1)
    {
        if(ac[a].trie[c]!=-1) ac[a].go[c]=ac[a].trie[c];
        else ac[a].go[c]=(a==0?0:go(get_link(a),t));
    }
    return ac[a].go[c];
}

const int N=400005;
vector<int> v[N];
vector<int> up(N,0);
vector<int> sub(N,0);
vector<int> big(N,0);
vector<int> head(N,0);
vector<int> pos(N,0);
int tcnt=0;

void dfs(int a)
{
    sub[a]=1;
    for(int to:v[a])
    {
        dfs(to);
        sub[a]+=sub[to];
        if(big[a]==0||sub[to]>sub[big[a]]) big[a]=to;
    }
}

void decompose(int a,int h)
{
    head[a]=h;
    pos[a]=tcnt++;
    if(big[a]!=0) decompose(big[a],h);
    for(int to:v[a]) if(to!=big[a]) decompose(to,to);
}

vector<int> tree(4*N,0);

void update(int idx,int l,int r,int x,int val)
{
    if(l==r) tree[idx]+=val;
    else
    {
        int m=(l+r)/2;
        if(x<=m) update(2*idx,l,m,x,val);
        else update(2*idx+1,m+1,r,x,val);
        tree[idx]=tree[2*idx]+tree[2*idx+1];
    }
}

int query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return query(2*idx,l,m,ql,min(qr,m))+query(2*idx+1,m+1,r,max(ql,m+1),qr);
}

int go(int a,int n)
{
    int res=0;
    while(a!=-1)
    {
        res+=query(1,0,n,pos[head[a]],pos[a]);
        a=up[head[a]];
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> id(n+1,0);
    string c(n+1,'$');
    up[0]=-1;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin >> t;
        if(t==2) cin >> up[i];
        cin >> c[i];
        v[up[i]].push_back(i);
    }
    dfs(0);
    decompose(0,0);
    int m;
    cin >> m;
    vector<int> song(m+1,0);
    vector<string> t(m+1);
    vector<int> ac_id(m+1,0);
    for(int i=1;i<=m;i++)
    {
        cin >> song[i] >> t[i];
        ac_id[i]=add(t[i]);
    }
    int sz=(int)ac.size()-1;
    vector<int> tin(sz+1,0);
    vector<int> tout(sz+1,0);
    int tnow=0;
    vector<int> g[sz+1];
    for(int i=1;i<=sz;i++) g[get_link(i)].push_back(i);
    function<void(int)> ac_dfs=[&](int a)
    {
        tin[a]=tnow++;
        for(int to:g[a]) ac_dfs(to);
        tout[a]=tnow-1;
    };
    ac_dfs(0);
    for(int i=1;i<=n;i++) id[i]=go(id[up[i]],c[i]);
    vector<int> e_add[sz+1];
    for(int i=0;i<=n;i++) e_add[tin[id[i]]].push_back(pos[i]);
    vector<array<int,2>> e[sz+1]; //query,mul
    for(int i=1;i<=m;i++)
    {
        e[tin[ac_id[i]]-1].push_back({i,-1});
        e[tout[ac_id[i]]].push_back({i,1});
    }
    vector<int> res(m+1,0);
    for(int i=0;i<=sz;i++)
    {
        for(int x:e_add[i]) update(1,0,n,x,1);
        for(auto [q,d]:e[i]) res[q]+=(d*go(song[q],n));
    }
    for(int i=1;i<=m;i++) cout << res[i] << "\n";
    return 0;
}