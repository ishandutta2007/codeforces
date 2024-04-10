#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Node;
using twoNodes=array<Node*,2>;

struct Node
{
    int node;
    int val;
    int lazy;
    twoNodes kids;
    Node *p;
    Node *pathp;
    Node(int a){node=a;val=-1;lazy=0;kids[0]=kids[1]=p=pathp=nullptr;}
};

int side(Node *me){return (me->p?(me->p->kids[1]==me):0);}

void apply(Node *me,int val)
{
    if(!me) return;
    me->val=me->lazy=val;
}

void prop(Node *me)
{
    if(me&&me->lazy!=0)
    {
        for(Node *to:me->kids) apply(to,me->lazy);
        me->lazy=0;
    }
}

void make_parent(Node *me,int id,Node *kid)
{
    if(me) me->kids[id]=kid;
    if(kid) kid->p=me;
}

void unmake_parent(Node *me,int id)
{
    make_parent(nullptr,0,me->kids[id]);
    make_parent(me,id,nullptr);
}

void rotate_up(Node *me)
{
    Node *p=me->p;
    int id=side(me);
    if(!p->p) swap(me->pathp,p->pathp);
    make_parent(p->p,side(p),me);
    make_parent(p,id,me->kids[id^1]);
    make_parent(me,id^1,p);
}

void splay(Node *me)
{
    while(me->p)
    {
        prop(me->p->p);
        prop(me->p);
        prop(me);
        if(me->p->p)
        {
            if(side(me)==side(me->p)) rotate_up(me->p);
            else rotate_up(me);
        }
        rotate_up(me);
    }
    prop(me);
}

void detach_path(Node *me)
{
    if(me->kids[1]) me->kids[1]->pathp=me;
    unmake_parent(me,1);
}

Node* find_left(Node *me)
{
    while(me->kids[0]) me=me->kids[0];
    splay(me);
    return me;
}

vector<array<int,2>> access(Node *me)
{
    vector<array<int,2>> ch;
    me=find_left(me);
    while(me->pathp)
    {
        Node *up=me->pathp;
        me->pathp=nullptr;
        splay(up);
        ch.push_back({up->node,up->val});
        detach_path(up);
        make_parent(up,1,me);
        splay(me);
        me=find_left(me);
    }
    return ch;
}

void update(Node *me,int val)
{
    splay(me);
    me->val=val;
    apply(me->kids[0],val);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<array<int,2>> g[n+1];
    vector<array<int,2>> edges(n-1);
    for(int i=0;i<n-1;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
        edges[i]={a,b};
    }
    vector<ll> d(n+1,-1);
    d[1]=0;
    vector<int> p(n+1,0);
    function<void(int)> dfs=[&](int a)
    {
        for(auto [to,c]:g[a])
        {
            if(d[to]==-1)
            {
                p[to]=a;
                d[to]=d[a]+c;
                dfs(to);
            }
        }
    };
    dfs(1);
    vector<int> preferred(n+1,0);
    for(auto &[a,b]:edges)
    {
        if(d[a]>d[b]) swap(a,b);
        preferred[a]=b;
    }
    vector<int> ord(n-1);
    for(int i=0;i<n-1;i++) ord[i]=i+2;
    sort(ord.begin(),ord.end(),[&](int a,int b){return (d[a]<d[b]);});
    vector<Node*> v(n+1,nullptr);
    for(int i=1;i<=n;i++) v[i]=new Node(i);
    for(int a:ord)
    {
        if(preferred[p[a]]==a) make_parent(v[p[a]],1,v[a]);
        else v[a]->pathp=v[p[a]];
    }
    vector<array<ll,2>> e;
    for(int i=1;i<=m;i++)
    {
        int s,t;
        cin >> s >> t;
        vector<array<int,2>> ch=access(v[s]);
        if(s!=1) update(v[p[s]],t);
        for(auto [a,prv]:ch)
        {
            if(prv==-1) e.push_back({1,t+d[a]});
            else e.push_back({prv+d[a]+1,t+d[a]});
        }
    }
    sort(e.begin(),e.end());
    int sz=e.size();
    int idx=0;
    multiset<ll> deadlines;
    ll t=1;
    ll lim=-1;
    while(idx<sz||(!deadlines.empty()))
    {
        if(deadlines.empty()) t=e[idx][0];
        while(idx<sz&&e[idx][0]==t) deadlines.insert(e[idx++][1]);
        deadlines.erase(deadlines.begin());
        if(!deadlines.empty()&&(*deadlines.begin())==t)
        {
            lim=t;
            break;
        }
        t++;
    }
    int res=0;
    for(int i=0;i<sz;i++) res+=(lim==-1||e[i][1]<lim);
    cout << lim << " " << res << "\n";
    return 0;
}