#pragma GCC optimize("O3")
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
bool use[arr];

void dfs(int now)
{
    use[now]=1;
    for (auto wh:reb[now]){
        if (!use[wh]){
            dfs(wh);
        }
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,m;
    cin>>n>>m;
    int ans=0;
    for (int i=1;i<=n;i++){
        int k;
        cin>>k;
        if (k==0){
            use[i]=1;
            ans++;
        }
        while (k--){
            int l;
            cin>>l;
            reb[i].pb(n+l);
            reb[n+l].pb(i);
        }
    }
    int ans1=0;
    for (int i=1;i<=n;i++){
        if (!use[i]){
            dfs(i);
            ans1++;
        }
    }
    cout<<ans+(ans1==0?0:ans1-1)<<"\n";
}