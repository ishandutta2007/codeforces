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

int f[arr];

void inc(int pos,int val)
{
    for (int i=pos;i<arr;i|=i+1){
        f[i]+=val;
    }
}

int get(int pos)
{
    int res=0;
    for (int i=pos;i>=0;i&=i+1,i--){
        res+=f[i];
    }
    return res;
}

int get(int l,int r)
{
    if (l>r){
        return 0;
    }
    return get(r)-get(l-1);
}

vector<pair<pii,int>> rxq;
vector<pair<pii,int>> qxr;

int pos[arr];

int foo(int kek,int l,int r)
{
    int L=lower_bound(all(qxr),mp(mp(kek,l),-md*md))-qxr.begin();
    int R=upper_bound(all(qxr),mp(mp(kek,r),md*md))-qxr.begin();
    return get(L,R-1);
}

map<pair<pii,int>,vi> pos_in_qxr;

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++){
        int x,r,q;
        cin>>x>>r>>q;
        rxq.pb({{r,x},q});
        qxr.pb({{q,x},r});
    }
    sort(all(rxq));
    reverse(all(rxq));
    sort(all(qxr));
    for (int i=0;i<len(qxr);i++){
        pos_in_qxr[mp(mp(qxr[i].sec,qxr[i].fir.sec),qxr[i].fir.fir)].pb(i);
    }

    int ans=0;
    for (auto i:rxq){
        int r=i.fir.fir;
        int x=i.fir.sec;
        int q=i.sec;
        for (int j=q-k;j<=q+k;j++){
            ans+=foo(j,x-r,x+r);
        }
        int kek=pos_in_qxr[i].back();
        pos_in_qxr[i].pop_back();
        inc(kek,+1);
    }
    cout<<ans<<"\n";
}