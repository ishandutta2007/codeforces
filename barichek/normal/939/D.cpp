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

int p[arr];

int f(int v)
{
    return p[v]==v?v:p[v]=f(p[v]);
}

void unite(int u,int v)
{
    u=f(u);
    v=f(v);
    p[u]=v;
}

vi kek[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    for (int i='a';i<='z';i++){
        p[i]=i;
    }

    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    for (int i=0;i<n;i++){
        unite(s[i],t[i]);
    }
    for (int i='a';i<='z';i++){
        kek[f(i)].pb(i);
    }
    vector<pii> ans(0);
    for (int i=0;i<arr;i++){
        for (int j=1;j<len(kek[i]);j++){
            ans.pb({kek[i][j-1],kek[i][j]});
        }
    }
    cout<<len(ans)<<"\n";
    for (auto i:ans){
        cout<<char(i.fir)<<" "<<char(i.sec)<<"\n";
    }
}