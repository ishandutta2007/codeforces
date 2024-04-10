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

#define oryshych_jebosh main

///---program start---///

#define arr (int)(3e5+10)

pii t[4*arr];
int push[4*arr];

void make_push(int v)
{
    if (!push[v]){
        return;
    }
    t[v*2].fir+=push[v];
    t[v*2+1].fir+=push[v];
    push[v*2]+=push[v];
    push[v*2+1]+=push[v];
    push[v]=0;
}

void upd(int v,int l,int r,int tl,int tr,int val)
{
    if (!t[v].sec){
        t[v].sec=l;
    }
    if (l>tr||r<tl){
        return;
    }
    if (l>=tl&&r<=tr){
        t[v].fir+=val;
        push[v]+=val;
        return;
    }
    make_push(v);
    int m=(l+r)/2;
    upd(v*2,l,m,tl,tr,val);
    upd(v*2+1,m+1,r,tl,tr,val);
    t[v]=max(t[v*2],t[v*2+1]);
}

int l[arr];
int v[arr];
int r[arr];
vector<pii> in[arr];
vector<pii> out[arr];

void add(int x1,int y1,int x2,int y2)
{
    in[x1].pb(mp(y1,y2));
    out[x2].pb(mp(y1,y2));
}

oryshych_jebosh()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>l[i]>>v[i]>>r[i];
        add(l[i],v[i],v[i],r[i]);
    }
    int ans=0;
    int L=0;
    int R=0;
    for (int i=1;i<=3e5;i++){
        for (auto j:in[i]){
            upd(1,1,arr,j.fir,j.sec,+1);
        }
        if (ans<t[1].fir){
            ans=t[1].fir;
            L=i;
            R=t[1].sec;
        }
        for (auto j:out[i]){
            upd(1,1,arr,j.fir,j.sec,-1);
        }
    }
    vi vec(0);
    for (int i=1;i<=n;i++){
        if (l[i]<=L&&v[i]>=L&&v[i]<=R&&R<=r[i]){
            vec.pb(i);
        }
    }
    cout<<ans<<"\n";
    for (auto i:vec){
        cout<<i<<" ";
    }
    cout<<"\n";
}