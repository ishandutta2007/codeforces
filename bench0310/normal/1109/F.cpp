#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Node;
using twoNodes=array<Node*,2>;

struct Node
{
    int val;
    int sz;
    int lazy;
    twoNodes kids;
    Node *p;
    Node *pathp;
    Node(int a){val=a;sz=1;lazy=0;kids[0]=kids[1]=p=pathp=nullptr;}
};

int sz(Node *me){return (me?me->sz:0);}
int side(Node *me){return (me->p?(me->p->kids[1]==me):0);}

void recalc(Node *me)
{
    if(!me) return;
    me->sz=1;
    for(Node *to:me->kids) me->sz+=sz(to);
}

void apply(Node *me)
{
    if(!me) return;
    swap(me->kids[0],me->kids[1]);
    me->lazy^=1;
}

void prop(Node *me)
{
    if(me&&me->lazy==1)
    {
        for(Node *to:me->kids) apply(to);
        me->lazy=0;
    }
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
    apply(me);
}

void cut(Node *me)
{
    access(me);
    unmake_parent(me,0);
}

void link(Node *me,Node *up)
{
    access(me);
    access(up);
    make_parent(me,0,up);
}

const int N=200005;
vector<array<int,2>> tree(4*N,{0,1});
vector<int> lazy(4*N,0);

array<int,2> min_merge(array<int,2> a,array<int,2> b)
{
    int mn=min(a[0],b[0]);
    int c=0;
    for(auto [x,cnt]:{a,b}) if(x==mn) c+=cnt;
    return {mn,c};
}

void push(int idx)
{
    for(int i=0;i<2;i++)
    {
        tree[2*idx+i][0]+=lazy[idx];
        lazy[2*idx+i]+=lazy[idx];
    }
    lazy[idx]=0;
}

void update(int idx,int l,int r,int ql,int qr,int d)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        tree[idx][0]+=d;
        lazy[idx]+=d;
    }
    else
    {
        int m=(l+r)/2;
        push(idx);
        update(2*idx,l,m,ql,min(qr,m),d);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,d);
        tree[idx]=min_merge(tree[2*idx],tree[2*idx+1]);
    }
}

array<int,2> query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return {N,0};
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    push(idx);
    return min_merge(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n+1,vector<int>(m+1,0));
    vector<array<int,2>> pos(n*m+1,{0,0});
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> a[i][j];
            pos[a[i][j]]={i,j};
        }
    }
    vector<Node*> v(n*m+1,nullptr);
    for(int i=1;i<=n*m;i++) v[i]=new Node(i);
    vector<array<int,2>> z={{1,0},{-1,0},{0,-1},{0,1}};
    auto in=[&](int r,int c)->bool{return (1<=r&&r<=n&&1<=c&&c<=m);};
    vector<int> lim(n*m+1,0);
    int idx=1;
    for(int i=1;i<=n*m;i++)
    {
        while(idx<=n*m)
        {
            auto [r,c]=pos[idx];
            vector<Node*> now;
            for(auto [dr,dc]:z)
            {
                int nr=r+dr;
                int nc=c+dc;
                if(in(nr,nc)&&i<=a[nr][nc]&&a[nr][nc]<idx) now.push_back(v[a[nr][nc]]);
            }
            int sz=now.size();
            bool ok=1;
            for(int x=0;x<sz;x++) for(int y=x+1;y<sz;y++) ok&=(find_root(now[x])!=find_root(now[y]));
            if(ok)
            {
                make_root(v[idx]);
                for(Node *to:now)
                {
                    make_root(to);
                    link(to,v[idx]);
                }
                idx++;
            }
            else break;
        }
        lim[i]=idx-1;
        auto [r,c]=pos[i];
        make_root(v[i]);
        for(auto [dr,dc]:z)
        {
            int nr=r+dr;
            int nc=c+dc;
            if(in(nr,nc)&&i<a[nr][nc]&&a[nr][nc]<idx) cut(v[a[nr][nc]]);
        }
    }
    ll res=0;
    for(int i=n*m;i>=1;i--)
    {
        update(1,1,n*m,i,lim[i],1);
        auto [r,c]=pos[i];
        for(auto [dr,dc]:z)
        {
            int nr=r+dr;
            int nc=c+dc;
            if(in(nr,nc)&&i<a[nr][nc]&&a[nr][nc]<=lim[i]) update(1,1,n*m,a[nr][nc],lim[i],-1);
        }
        res+=query(1,1,n*m,i,lim[i])[1];
    }
    cout << res << "\n";
    return 0;
}