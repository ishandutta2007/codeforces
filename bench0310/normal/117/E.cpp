#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Node;
using twoNodes=array<Node*,2>;

struct Node
{
    array<int,2> val;
    array<int,2> sum;
    int flip;
    int lazy;
    twoNodes kids;
    Node *p;
    Node *pathp;
    Node(array<int,2> a){val=sum=a;flip=lazy=0;kids[0]=kids[1]=p=pathp=nullptr;}
};

int side(Node *me){return (me->p?(me->p->kids[1]==me):0);}

void recalc(Node *me)
{
    if(!me) return;
    me->sum=me->val;
    for(Node *to:me->kids) if(to) {me->sum[0]+=to->sum[0];me->sum[1]+=to->sum[1];}
}

void apply_flip(Node *me)
{
    if(!me) return;
    swap(me->kids[0],me->kids[1]);
    me->flip^=1;
}

void apply_lazy(Node *me)
{
    if(!me) return;
    swap(me->val[0],me->val[1]);
    swap(me->sum[0],me->sum[1]);
    me->lazy^=1;
}

void prop(Node *me)
{
    if(!me) return;
    for(Node *to:me->kids)
    {
        if(me->flip==1) apply_flip(to);
        if(me->lazy==1) apply_lazy(to);
    }
    me->flip=me->lazy=0;
}

void make_parent(Node *me,int id,Node *kid)
{
    if(me) me->kids[id]=kid;
    recalc(me);
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
    recalc(me);
}

void detach_path(Node *me)
{
    if(me->kids[1]) me->kids[1]->pathp=me;
    unmake_parent(me,1);
}

Node* access(Node *me)
{
    Node *up=me;
    splay(me);
    detach_path(me);
    while(me->pathp)
    {
        up=me->pathp;
        me->pathp=nullptr;
        splay(up);
        detach_path(up);
        make_parent(up,1,me);
        splay(me);
    }
    return up;
}

Node* find_root(Node *me)
{
    access(me);
    while(me->kids[0])
    {
        me=me->kids[0];
        prop(me);
    }
    splay(me);
    return me;
}

void make_root(Node *me)
{
    access(me);
    apply_flip(me);
}

void link(Node *me,Node *up)
{
    make_root(me);
    access(up);
    make_parent(me,0,up);
}

int edges_on=0;

array<int,2> query(Node *a,Node *b)
{
    make_root(a);
    access(b);
    return (b->sum);
}

void update(Node *a,Node *b)
{
    auto [zero,one]=query(a,b);
    edges_on+=(zero-one);
    make_root(a);
    access(b);
    apply_lazy(b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<Node*> v(n+1,nullptr);
    for(int i=1;i<=n;i++) v[i]=new Node({0,0});
    array<int,2> edge={0,0};
    int edge_st=0;
    vector<int> g[n+1];
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin >> a >> b;
        if(find_root(v[a])!=find_root(v[b]))
        {
            g[a].push_back(b);
            g[b].push_back(a);
            Node *t=new Node({1,0});
            link(v[a],t);
            link(v[b],t);
        }
        else edge={a,b};
    }
    vector<int> p(n+1,-1);
    function<void(int)> dfs1=[&](int a)
    {
        for(int to:g[a])
        {
            if(p[to]==-1)
            {
                p[to]=a;
                dfs1(to);
            }
        }
    };
    p[edge[0]]=0;
    dfs1(edge[0]);
    vector<int> cycle={edge[1]};
    while(cycle.back()!=edge[0]) cycle.push_back(p[cycle.back()]);
    reverse(cycle.begin(),cycle.end());
    vector<int> cycle_pos(n+1,-1);
    int cycle_len=cycle.size();
    for(int i=0;i<cycle_len;i++) cycle_pos[cycle[i]]=i;
    vector<int> cycle_entry(n+1,-1);
    function<void(int,int)> dfs2=[&](int a,int e)
    {
        for(int to:g[a])
        {
            if(cycle_pos[to]!=-1) continue;
            if(cycle_entry[to]==-1)
            {
                cycle_entry[to]=e;
                dfs2(to,e);
            }
        }
    };
    for(int a:cycle)
    {
        cycle_entry[a]=a;
        dfs2(a,a);
    }
    while(m--)
    {
        int a,b;
        cin >> a >> b;
        int ca=cycle_entry[a];
        int cb=cycle_entry[b];
        if(ca==cb) update(v[a],v[b]);
        else
        {
            int one=abs(cycle_pos[ca]-cycle_pos[cb]);
            int two=cycle_len-one;
            bool tree=0;
            if(one==two)
            {
                int tree_side=cycle[(cycle_pos[ca]+1)%cycle_len];
                int edge_side=cycle[(cycle_pos[ca]-1+cycle_len)%cycle_len];
                if(cycle_pos[ca]>cycle_pos[cb]) swap(tree_side,edge_side);
                tree=(tree_side<edge_side);
            }
            if(one<two||tree==1) update(v[a],v[b]);
            else
            {
                if(cycle_pos[ca]>cycle_pos[cb]) swap(a,b);
                update(v[a],v[edge[0]]);
                update(v[b],v[edge[1]]);
                edge_st^=1;
            }
        }
        int res=(n-edges_on);
        if(edge_st==1&&query(v[edge[0]],v[edge[1]])[0]!=0) res--;
        cout << res << "\n";
    }
    return 0;
}