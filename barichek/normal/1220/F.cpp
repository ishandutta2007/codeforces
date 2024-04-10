//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
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

int a[2*arr];
int t[8*arr];
int push[8*arr];

void make_push(int v)
{
    t[v*2]+=push[v];
    t[v*2+1]+=push[v];

    push[v*2]+=push[v];
    push[v*2+1]+=push[v];

    push[v]=0;
}

void upd(int v,int l,int r,int tl,int tr,int val)
{
    if (l>tr||r<tl){
        return;
    }
    if (l>=tl&&r<=tr){
        t[v]+=val;
        push[v]+=val;
        return;
    }
    make_push(v);
    int m=(l+r)/2;
    upd(v*2,l,m,tl,tr,val);
    upd(v*2+1,m+1,r,tl,tr,val);
    t[v]=max(t[v*2],t[v*2+1]);
}

void upd(int tl,int tr,int val)
{
//    cout<<"upd :: "<<tl<<" "<<tr<<" "<<val<<"\n";
    if (tl>tr){
        return;
    }
    upd(1,1,2*arr,tl,tr,val);
}

int get(int v,int l,int r,int tl,int tr)
{
    if (l>tr||r<tl){
        return -1e9;
    }
    if (l>=tl&&r<=tr){
        return t[v];
    }
    make_push(v);
    int m=(l+r)/2;
    return max(
               get(v*2,l,m,tl,tr),
               get(v*2+1,m+1,r,tl,tr)
               );
}

int first_left[2*arr];
int first_right[2*arr];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=n+1;i<=2*n;i++){
        a[i]=a[i-n];
    }
    if (1){
        deque<pii> s;
        s.pb(mp(-1e9,0));
        for (int i=1;i<=2*n;i++){
            while (s.back().fir>a[i]){
                s.pop_back();
            }
            first_left[i]=s.back().sec;
            s.pb(mp(a[i],i));
        }
    }
    if (1){
        deque<pii> s;
        s.pb(mp(-1e9,2*n+1));
        for (int i=2*n;i>=1;i--){
            while (s.back().fir>a[i]){
                s.pop_back();
            }
            first_right[i]=s.back().sec;
            s.pb(mp(a[i],i));
        }
    }
//    for (int i=1;i<=2*n;i++){
//        cout<<i<<" "<<first_left[i]<<" "<<first_right[i]<<"\n";
//    }
    pii ans=mp(1e9,-1);
    auto process=[&](int pos,int val)
    {
        upd(first_left[pos]+1,pos-1,val);
        upd(pos+1,first_right[pos]-1,val);
    };
    for (int i=1;i<=n;i++){
        process(i,+1);
    }
    for (int i=1,cyc=0;i<=n;i++,cyc++){
//        cout<<"start i :: "<<i<<" !!!\n";
        ans=min(ans,mp(get(1,1,2*arr,i,i+n-1),cyc));
        process(i,-1);
        process(i+n,+1);
//        cout<<"ans :: "<<ans.fir<<" "<<ans.sec<<"\n";
    }
    cout<<ans.fir+1<<" "<<ans.sec<<"\n";
}