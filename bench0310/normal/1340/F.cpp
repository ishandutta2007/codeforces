#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
int rng(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const ll p=rng(100001,200000);
const ll mod=1000000007;
const int N=100005;
const int M=2000005;
vector<ll> pw(N,1);
int add(ll a,ll b){return (a+b)%mod;}
int mul(ll a,ll b){return (a*b)%mod;}

struct Treap;
using twoTreaps=array<Treap*,2>;

struct Treap
{
    int val;
    int h;
    bool dir;
    int sz;
    int priority;
    twoTreaps kids;
    void ini(Treap *me){(*this)=(*me);}
    void ini(int a,bool d){val=a;h=a;dir=d;sz=1;priority=rng(1,(1<<30));kids[0]=kids[1]=nullptr;}
}treap[M];

int id=0;
Treap* newTreap(Treap *me)
{
    treap[id].ini(me);
    return &treap[id++];
}
Treap* newTreap(int a,bool d)
{
    treap[id].ini(a,d);
    return &treap[id++];
}

int sz(Treap *me){return (me?me->sz:0);}

int hmerge(int a,int sa,int b,int sb,bool dir)
{
    if(dir==0) return add(mul(a,pw[sb]),b);
    else return add(mul(b,pw[sa]),a);
}

void recalc(Treap *me)
{
    if(!me) return;
    me->sz=1;
    me->h=me->val;
    if(me->kids[0])
    {
        me->h=hmerge(me->kids[0]->h,me->kids[0]->sz,me->h,me->sz,me->dir);
        me->sz+=me->kids[0]->sz;
    }
    if(me->kids[1])
    {
        me->h=hmerge(me->h,me->sz,me->kids[1]->h,me->kids[1]->sz,me->dir);
        me->sz+=me->kids[1]->sz;
    }
}

twoTreaps split(Treap *me,int cnt)
{
    if(!me) return {nullptr,nullptr};
    me=newTreap(me);
    if(sz(me->kids[0])>=cnt)
    {
        twoTreaps res=split(me->kids[0],cnt);
        me->kids[0]=res[1];
        recalc(me);
        return {res[0],me};
    }
    else
    {
        twoTreaps res=split(me->kids[1],cnt-sz(me->kids[0])-1);
        me->kids[1]=res[0];
        recalc(me);
        return {me,res[1]};
    }
}

Treap* tmerge(Treap *a,Treap *b)
{
    if(!a) return b;
    if(!b) return a;
    a=newTreap(a);
    b=newTreap(b);
    if(a->priority<b->priority)
    {
        a->kids[1]=tmerge(a->kids[1],b);
        recalc(a);
        return a;
    }
    else
    {
        b->kids[0]=tmerge(a,b->kids[0]);
        recalc(b);
        return b;
    }
}

struct Node
{
    Treap *one,*two;
    bool ok;
    Node(){one=two=nullptr;ok=1;}
    void ini(int a)
    {
        if(a>=0)
        {
            one=nullptr;
            two=newTreap(a,0);
        }
        else
        {
            one=newTreap(-a,1);
            two=nullptr;
        }
    }
    void nmerge(Node l,Node r)
    {
        if(l.ok==0||r.ok==0) ok=0;
        else
        {
            ok=1;
            int sl=(l.two?l.two->sz:0);
            int sr=(r.one?r.one->sz:0);
            int sz=min(sl,sr);
            if(sz>0)
            {
                Treap *a=l.two;
                Treap *b=r.one;
                auto [al,ar]=split(a,a->sz-sz);
                auto [bl,br]=split(b,sz);
                if(ar->h!=bl->h) ok=0;
                one=tmerge(l.one,br);
                two=tmerge(al,r.two);
            }
            else
            {
                one=tmerge(l.one,r.one);
                two=tmerge(l.two,r.two);
            }
        }
    }
};

vector<int> t(N,0);
vector<Node> tree(4*N);

void build(int idx,int l,int r)
{
    if(l==r) tree[idx].ini(t[l]);
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tree[idx].nmerge(tree[2*idx],tree[2*idx+1]);
    }
}

void update(int idx,int l,int r,int pos)
{
    if(l==r) tree[idx].ini(t[l]);
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos);
        else update(2*idx+1,m+1,r,pos);
        tree[idx].nmerge(tree[2*idx],tree[2*idx+1]);
    }
}

Node query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return Node();
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    Node tmp;
    tmp.nmerge(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
    return tmp;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> t[i];
    for(int i=1;i<=n;i++) pw[i]=mul(pw[i-1],p);
    build(1,1,n);
    int q;
    cin >> q;
    while(q--)
    {
        int tp,l,r;
        cin >> tp >> l >> r;
        if(tp==1)
        {
            t[l]=r;
            update(1,1,n,l);
        }
        else
        {
            Node res=query(1,1,n,l,r);
            if(res.one==nullptr&&res.two==nullptr&&res.ok==1) cout << "Yes\n";
            else cout << "No\n";
        }
        //so this is one of the hackiest things I've seen in a while..
        //once you're close to exceeding the buffer, just clear it and rebuild everything to avoid MLE
        //since you create $O(\log^2(n))$ nodes per query, rebuild happens every $\frac{M}{\log^2(n)}$ queries,
        //or $\frac{n \log^2(n)}{M}$ times, which for $M=O(n \log(n))$ is $O(\log(n))$ times
        if(id+5000>=M)
        {
            id=0;
            build(1,1,n);
        }
    }
    return 0;
}