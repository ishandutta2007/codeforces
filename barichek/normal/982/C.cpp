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
int p[arr];
int cost[arr];

void dfs(int now,int pred)
{
    cost[now]=1;
    p[now]=pred;
    for (auto wh:reb[now]){
        if (wh!=pred){
            dfs(wh,now);
        }
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
    if (n%2==1){
        cout<<-1<<"\n";
        return 0;
    }
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        reb[v].pb(u);
        c[u]++;
        c[v]++;
    }
    dfs(1,1);
    int ans=0;
    set<int> q;
    q.clear();
    for (int i=1;i<=n;i++){
        if (c[i]==1&&i!=1){
            q.insert(i);
        }
    }
    while (!q.empty()){
        int now=*q.begin();
        q.erase(q.begin());

//        cout<<"now :: "<<now<<" :: "<<cost[now]<<"\n";

        if (cost[now]%2==1&&now==1){
            cout<<-1<<"\n";
            return 0;
        }

        if (now!=1&&cost[now]%2==0){
            ans++;
        }

        if (now!=1){
            cost[p[now]]+=cost[now];
            c[p[now]]--;
            if ((c[p[now]]==1&&p[now]!=1)||(c[p[now]]==0&&p[now]==1)){
                q.insert(p[now]);
            }
        }
    }

    cout<<ans<<"\n";
}