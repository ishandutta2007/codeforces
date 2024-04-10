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

pair<int,vector<int>> solve(int n,int s)
{
    int bl=n/s+(n%s!=0);
    vector<int> res;
    int ans=0;
    for (int i=bl;i>=1;i--){
        for (int j=(i-1)*s+1;j<=min(n,i*s);j++){
            res.pb(j);
        }
    }
    ans+=bl;
    ans+=s;
    return mp(ans,res);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;
    int s=1;
    while ((s+1)*(s+1)<=n){
        s++;
    }
    pair<int,vi> ans={1e9,{}};
    for (int i=max(1ll,s-2);i<=min(n,s+2);i++){
        ans=min(ans,solve(n,i));
    }
    for (auto i:ans.sec){
        cout<<i<<" ";
    }
}