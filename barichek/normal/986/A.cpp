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

int a[arr];
int dist[101][100001];
bool use[arr];
int n,m,k,s;
vi reb[arr];

void work(int val)
{
    for (int i=1;i<=n;i++){
        use[i]=0;
        dist[val][i]=1e9;
    }
    queue<int> q;
    for (int i=1;i<=n;i++){
        if (a[i]==val){
            use[i]=1;
            dist[val][i]=0;
            q.push(i);
        }
    }
    while (!q.empty()){
        int now=q.front();
        q.pop();
        for (auto wh:reb[now]){
            if (!use[wh]){
                use[wh]=1;
                dist[val][wh]=dist[val][now]+1;
                q.push(wh);
            }
        }
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    cin>>n>>m>>k>>s;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    while (m--){
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        reb[v].pb(u);
    }
    for (int i=1;i<=k;i++){
        work(i);
    }
    for (int i=1;i<=n;i++){
        vi cur(0);
        for (int j=1;j<=k;j++){
            cur.pb(dist[j][i]);
        }
        sort(all(cur));
        int ans=0;
        for (int j=0;j<s;j++){
            ans+=cur[j];
        }
        cout<<ans<<"\n";
    }
}