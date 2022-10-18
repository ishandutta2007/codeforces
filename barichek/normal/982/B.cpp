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

int ans[2*arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n;
    cin>>n;
    set<pii> s1;
    s1.clear();
    for (int i=1;i<=n;i++){
        int w;
        cin>>w;
        s1.insert({w,i});
    }
    set<pii> s2;
    s2.clear();
    string s;
    cin>>s;
    for (int i=0;i<len(s);i++){
        if (s[i]=='0'){
            auto kek=*s1.begin();
            s1.erase(s1.begin());
            ans[i]=kek.sec;
            s2.insert(kek);
        }
        else{
            auto kek=*(--s2.end());
            s2.erase(--s2.end());
            ans[i]=kek.sec;
        }
    }
    for (int i=0;i<len(s);i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}