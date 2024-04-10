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

vi reb[arr];
int c[arr];
vi ans;

void dfs(int now,int pred=-1)
{
    int cnt_go=0;
    for (auto wh:reb[now]){
        if (wh!=pred){
            cnt_go++;
            dfs(wh,now);
        }
    }
    if (pred!=-1&&cnt_go>1){
        exit(!(cout<<"No"<<"\n"));
    }
    if (cnt_go==0){
        ans.pb(now);
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        c[u]++;
        c[v]++;
        reb[u].pb(v);
        reb[v].pb(u);
    }
    int root=(max_element(c+1,c+n+1)-c);
    dfs(root);
    cout<<"Yes"<<"\n";
    cout<<len(ans)<<"\n";
    for (auto i:ans){
        cout<<root<<" "<<i<<"\n";
    }
}