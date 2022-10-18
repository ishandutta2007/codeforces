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

#define arr (int)(4e5+10)

int tree[4*arr];
bool push[4*arr];

inline int len1(int l,int r)
{
    return r-l+1;
}

void make_push(int v,int l,int r)
{
    if (l==r){
        return;
    }
    if (!push[v]){
        return;
    }
    push[v]=0;
    push[v*2]^=1;
    push[v*2+1]^=1;
    int m=(l+r)/2;
    tree[v*2]=len1(l,m)-tree[v*2];
    tree[v*2+1]=len1(m+1,r)-tree[v*2+1];
}

void upd(int v,int l,int r,int tl,int tr)
{
    make_push(v,l,r);
    if (l>tr||r<tl){
        return;
    }
    if (l>=tl&&r<=tr){
        push[v]^=1;
        tree[v]=len1(l,r)-tree[v];
        return;
    }
    int m=(l+r)/2;
    upd(v*2,l,m,tl,tr);
    upd(v*2+1,m+1,r,tl,tr);
    tree[v]=tree[v*2]+tree[v*2+1];
}

int get(int v,int l,int r,int tl,int tr)
{
    make_push(v,l,r);
    if (l>tr||r<tl){
        return 0;
    }
    if (l>=tl&&r<=tr){
        return tree[v];
    }
    int m=(l+r)/2;
    return
        get(v*2,l,m,tl,tr)+
        get(v*2+1,m+1,r,tl,tr);
}

int val[arr];

void build(int v,int l,int r)
{
    if (l==r){
        return void(tree[v]=val[l]);
    }
    int m=(l+r)/2;
    build(v*2,l,m);
    build(v*2+1,m+1,r);
    tree[v]=tree[v*2]+tree[v*2+1];
}

int tin[arr];
int tout[arr];
vi reb[arr];
int timer;

void dfs(int now,int pred)
{
    tin[now]=++timer;
    for (auto wh:reb[now]){
        if (wh!=pred){
            dfs(wh,now);
        }
    }
    tout[now]=timer;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;
    int n;
    cin>>n;
    for (int i=2;i<=n;i++){
        int p;
        cin>>p;
        reb[p].pb(i);
    }
    dfs(1,-1);
    for (int i=1;i<=n;i++){
        cin>>val[tin[i]];
    }
    build(1,1,n);
    int q;
    cin>>q;
    while (q--){
        string type;
        cin>>type;
        int v;
        cin>>v;
        if (type=="get"){
            cout<<get(1,1,n,tin[v],tout[v])<<"\n";
        }
        else{
            upd(1,1,n,tin[v],tout[v]);
        }
    }
}