#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define files_ds(name) name!=""?freopen(name".dat","r",stdin),freopen(name".sol","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
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

#define null 0

struct item
{
    int val,min_,prior,size;
    item *left,*right;

    item() {}
    item(int val_=0)
    {
        val=val_;
        min_=val_;
        prior=rand();
        left=null;
        right=null;
        size=1;
    }
};

typedef item* pitem;

int get_size(pitem t)
{
    if (!t) return 0;
    return t->size;
}

int get_min_(pitem t)
{
    if (!t) return 2e9;
    return t->min_;
}

void recalc(pitem t)
{
    if (!t) return;
    t->size=get_size(t->left)+get_size(t->right)+1;
    t->min_=min({get_min_(t->left),get_min_(t->right),t->val});
}

void split_size(pitem t,pitem& l,pitem& r,int key)
{
    if (!t){
        return void(l=r=null);
    }
    int size_l=get_size(t->left)+1;
    if (size_l<=key){
        split_size(t->right,t->right,r,key-size_l), l=t;
    }
    else{
        split_size(t->left,l,t->left,key), r=t;
    }
    recalc(l);
    recalc(r);
}

void merge(pitem &t,pitem l,pitem r)
{
    if (!l||!r){
        return void(t=l?l:r);
    }
    if (l->prior>r->prior){
        merge(l->right,l->right,r), t=l;
    }
    else{
        merge(r->left,l,r->left), t=r;
    }
    recalc(t);
}

pitem Tree=null;

inline int get_min(int pref)
{
    pitem t1,t2;
    split_size(Tree,t1,t2,pref);
    int to_return=get_min_(t1);
    merge(Tree,t1,t2);
    return to_return;
}

int get_pos_min(pitem t)
{
    if (get_min_(t)==get_min_(t->left)){
        return get_pos_min(t->left);
    }
    if (get_min_(t)==t->val){
        return get_size(t->left)+1;
    }
    return get_size(t->left)+1+get_pos_min(t->right);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    srand(228*228);

    int n;
    scanf("%d",&n);
    vi a(n);
    for (int i=0;i<len(a);i++){
        scanf("%d",&a[i]);
        merge(Tree,Tree,new item(a[i]));
    }
    sort(all(a));
    ll ans=n;
    for (auto i:a){
        int res=get_pos_min(Tree);
        ans+=res-1;
        pitem t1,t2,t3;
        split_size(Tree,t1,t2,res-1);
        split_size(t2,t2,t3,1);
        merge(Tree,t3,t1);
    }
    cout<<ans<<"\n";
}