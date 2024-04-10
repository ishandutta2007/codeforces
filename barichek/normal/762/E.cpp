#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
///#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

/// sydoran is our lord
/// melnyk is our krevedka
/// oryshych is our kaban
/// mitsa is our batya
/// kek is our cheburek
/// oros is our down
/// goban is our huyoban
/// pechora is our maksim
/// arsijo is our tascher
/// filip is our petuh
/// vetal is our vseukr
/// archi is our pihpih

#define null NULL

int randll(int iter=2)
{
    int res=0;
    while (iter--)
        res<<=15,
        res|=rand();
    return res;
}

struct item
{
    int key,prior,size;
    item *left,*right;
    item(int val_=0)
    {
        key=val_;
        prior=randll();
        size=1;
        left=null;
        right=null;
    }
};

typedef item* pitem;

int get_size(pitem t)
{
    return t?t->size:0;
}

void recalc(pitem &t)
{
    if (!t) return;
    t->size=get_size(t->left)+get_size(t->right)+1;
}

void merge(pitem &t,pitem l,pitem r)
{
    if (!l||!r)
        return void(t=l?l:r);
    if (l->prior>r->prior)
        merge(l->right,l->right,r), t=l;
    else
        merge(r->left,l,r->left), t=r;
    recalc(t);
}

void split(pitem t,pitem &l,pitem &r,int key)
{
    if (!t)
        return void(l=r=null);
    if (t->key>key)
        split(t->left,l,t->left,key), r=t;
    else
        split(t->right,t->right,r,key), l=t;
    recalc(l);
    recalc(r);
}

void insert(pitem &Tree,int val)
{
    item *L,*R;
    split(Tree,L,R,val);
    merge(Tree,L,new item(val));
    merge(Tree,Tree,R);
}

void erase(pitem &Tree,int val)
{
    item *L,*ans,*R;
    split(Tree,L,R,val);
    split(L,L,ans,val-1);
    merge(Tree,L,R);
}

int get(pitem &Tree,int l,int r)
{
    item *L,*ans,*R;
    split(Tree,L,R,r);
    split(L,L,ans,l-1);
    int to_return=get_size(ans);
    merge(Tree,L,ans);
    merge(Tree,Tree,R);
    return to_return;
}

struct node
{
    int x,r,f;
    node() {}
    node(int x_,int r_,int f_)
    {
        x=x_;
        r=r_;
        f=f_;
    }

    void read()
    {
        scanf("%d%d%d",&x,&r,&f);
        return;
        cin>>x>>r>>f;
    }
};

bool cmp_r(node &a,node &b)
{
    return a.r<b.r||(a.r==b.r&&a.x<b.x);
}

item *roots[arr];

main()
{
    srand(time(0));
    int n,k;
    cin>>n>>k;
    vector<node> a;
    a.clear();
    a.resize(n);
    for (auto &i:a)
        i.read();
    sort(all(a),cmp_r);
    reverse(all(a));
    ll ans=0;
    for (auto i:a)
    {
        for (int j=max(1,i.f-k);j<=min(10000,i.f+k);j++)
            ans+=get(roots[j],i.x-i.r,i.x+i.r);
        insert(roots[i.f],i.x);
    }
    cout<<ans;
}