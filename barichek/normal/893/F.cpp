#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
#define int long long

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

struct node
{
    node *l,*r;
    int val;

    node()
    {
        val=2e9;
        l=r=0;
    }
};

void build(node*& v,int l,int r)
{
    v=new node();
    if (l==r){
        return;
    }
    int m=(l+r)/2;
    build(v->l,l,m);
    build(v->r,m+1,r);
}

void upd(node*& v,node* pv,int l,int r,int pos,int val)
{
    if (l!=r){
        v->l=pv->l;
        v->r=pv->r;
    }
    v->val=pv->val;
    if (l==r){
        v->val=min(v->val,val);
        return;
    }
    int m=(l+r)/2;
    if (pos<=m){
        v->l=new node();
        upd(v->l,pv->l,l,m,pos,val);
    }
    else{
        v->r=new node();
        upd(v->r,pv->r,m+1,r,pos,val);
    }
    v->val=min(v->l->val,v->r->val);
}

int get(node* v,int l,int r,int tl,int tr)
{
    if (l>tr||r<tl){
        return 2e9;
    }
    if (l>=tl&&r<=tr){
        return v->val;
    }
    int m=(l+r)/2;
    return min(
               get(v->l,l,m,tl,tr),
               get(v->r,m+1,r,tl,tr)
               );
}

node* roots[arr];
int tin[arr];
int tout[arr];
vi reb[arr];
int timer;
vi vh[arr];
int last[arr];
int cnt;
int a[arr];
int n,r;
int q;
int rem_deep[arr];

void dfs(int now,int pred,int deep)
{
    rem_deep[now]=deep;
    vh[deep].pb(now);
    tin[now]=++timer;
    for (auto wh:reb[now]){
        if (wh!=pred){
            dfs(wh,now,deep+1);
        }
    }
    tout[now]=timer;
}

void build()
{
    build(roots[0],1,n);
    for (int i=1;i<=n;i++){
        last[i]=cnt;
        if (!vh[i].empty()){
            for (auto j:vh[i]){
                cnt++;
                roots[cnt]=new node();
                upd(roots[cnt],roots[cnt-1],1,n,tin[j],a[j]);
            }
            last[i]=cnt;
        }
    }
}

int get(int x,int k)
{
    return get(roots[last[min(n,rem_deep[x]+k)]],1,n,tin[x],tout[x]);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;
    cin>>n>>r;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        reb[v].pb(u);
    }
    dfs(r,-1,1);
    build();
    cin>>q;
    int last=0;
    while (q--){
        int p,q;
        cin>>p>>q;
        int x=(p+last)%n+1;
        int k=(q+last)%n;
        cout<<(last=get(x,k))<<"\n";
    }
}