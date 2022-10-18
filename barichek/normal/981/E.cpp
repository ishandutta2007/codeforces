#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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

//#define cout cerr

#define arr (int)(1e4+1)

typedef bitset<arr> magic;

vi vh[4*arr];
magic t[4*arr];

void upd(int v,int l,int r,int tl,int tr,int val)
{
    if (l>tr||r<tl){
        return;
    }
    if (l>=tl&&r<=tr){
        vh[v].pb(val);
        return;
    }
    int m=(l+r)/2;
    upd(v*2,l,m,tl,tr,val);
    upd(v*2+1,m+1,r,tl,tr,val);
}

int n,q;
bool ans[arr];

void build(int v,int l,int r)
{
//    cout<<"build :: "<<v<<" "<<l<<" "<<r<<"\n";
    for (auto i:vh[v]){
        t[v]|=(t[v]<<i);
    }

    if (l==r){
        for (int i=1;i<=n;i++){
            if (t[v][i]){
                ans[i]=1;
            }
        }
        return;
    }

    t[v*2]=t[v];
    t[v*2+1]=t[v];

    int m=(l+r)/2;

    build(v*2,l,m);
    build(v*2+1,m+1,r);
};

void print_ans()
{
    int cnt=0;
    for (int i=1;i<=n;i++){
        if (ans[i]){
            cnt++;
        }
    }
    cout<<cnt<<"\n";
    for (int i=1;i<=n;i++){
        if (ans[i]){
            cout<<i<<" ";
        }
    }
    cout<<"\n";
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    cin>>n>>q;
    while (q--){
        int l,r,x;
        cin>>l>>r>>x;
        upd(1,1,n,l,r,x);
    }
    t[1][0]=1;
    build(1,1,n);

    print_ans();
}