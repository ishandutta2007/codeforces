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

void solve()
{
    int n;
    cin>>n;
    unordered_map<int,int> cnt;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        cnt[a]++;
    }
    vi kek(0);
    pair<ld,pii> ans={1e18,{-1,-1}};
    for (auto i:cnt){
        if (i.sec>=4){
            ans=min(ans,{ld(1)*(2*2*i.fir)*(2*2*i.fir)/i.fir/i.fir,{i.fir,i.fir}});
        }
        if (i.sec>=2){
            kek.pb(i.fir);
        }
    }
    sort(all(kek));
    for (int i=1;i<len(kek);i++){
        ans=min(ans,{ld(1)*(2*(kek[i]+kek[i-1]))*(2*(kek[i]+kek[i-1]))/kek[i]/kek[i-1],{kek[i],kek[i-1]}});
    }
    cout<<ans.sec.fir<<" "<<ans.sec.fir<<" "<<ans.sec.sec<<" "<<ans.sec.sec<<"\n";
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    /**

    P=2*(a+b);
    S=a*b;
    min -> P*P/S=min -> 4*(a+b)^2/(a*b) = x
    a^2+2*a*b+b^2=x*a*b

    */

    fast;

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}