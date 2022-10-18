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

vi reb[arr];
vi rreb[arr];
int ans[arr];
int cnt[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    int n,m;
    cin>>n>>m;
    while (m--){
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        rreb[v].pb(u);
    }
    set<int> s;
    s.clear();
    for (int i=1;i<=n;i++){
        if (reb[i].empty()){
            s.insert(i);
        }
    }
    int cur=n;
    while (!s.empty()){
        int now=*(--s.end());
        s.erase(now);
        ans[now]=cur--;
        for (auto wh:rreb[now]){
            if (++cnt[wh]==len(reb[wh])){
                s.insert(wh);
            }
        }
    }
    for (int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}