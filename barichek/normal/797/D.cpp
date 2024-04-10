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

#ifdef I_love_Maria_Ivanova
    #define debug if (1)
#else
    #define debug if (0)
#endif

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

multiset<int> L;
multiset<int> R;
map<int,bool> can;
map<int,int> cnt;
int n;
int val[arr];
int l[arr];
int r[arr];

void dfs(int now)
{
    if (now==-1){
        return;
    }
    if (L.empty()||*L.rbegin()<=val[now]){
        if (R.empty()||*R.begin()>=val[now]){
            can[val[now]]=1;
        }
    }
    R.insert(val[now]);
    dfs(l[now]);
    R.erase(R.find(val[now]));
    L.insert(val[now]);
    dfs(r[now]);
    L.erase(L.find(val[now]));
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    fast;
    cin>>n;
    set<int> root;
    for (int i=1;i<=n;i++){
        root.insert(i);
    }
    for (int i=1;i<=n;i++){
        cin>>val[i]>>l[i]>>r[i];
        root.erase(l[i]);
        root.erase(r[i]);
        can[val[i]];
        cnt[val[i]]++;
    }
    dfs(*root.begin());
    int ans=0;
    for (auto i:can){
        if (i.sec==0){
            ans+=cnt[i.fir];
        }
    }
    cout<<ans<<"\n";
}