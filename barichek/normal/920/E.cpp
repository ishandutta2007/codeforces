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

#define prev prev_____

set<int> open;
vi reb[arr];
int C;
int n;

void dfs(int now)
{
    open.erase(now);
    C++;

    vi cur_go(0);

    int prev=n+1;
    while (!reb[now].empty()){
        int lol=reb[now].back();
        reb[now].pop_back();

        auto it=open.upper_bound(lol);
        while (it!=open.end()&&*it<prev){
            cur_go.pb(*it);
            it++;
        }

        prev=lol;
    }

    for (auto i:cur_go){
        open.erase(i);
    }
    for (auto i:cur_go){
        dfs(i);
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        reb[x].pb(y);
        reb[y].pb(x);
    }
    for (int i=1;i<=n;i++){
        open.insert(i);
        reb[i].pb(0);
        reb[i].pb(n+1);
        sort(all(reb[i]));
    }

    vi ans(0);
    for (int i=1;i<=n;i++){
        if (open.count(i)){
            C=0;
            dfs(i);
            ans.pb(C);
        }
    }

    sort(all(ans));

    cout<<len(ans)<<"\n";
    for (auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}