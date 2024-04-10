//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
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
const ll inf=1e18+10;
 
///---program start---///

vi reb[arr];
vi rreb[arr];
int p[arr];
int dist[arr];
int n;

void bfs(int s)
{
    for (int i=1;i<=n;i++){
        dist[i]=inf;
    }
    queue<int> q;
    q.push(s);
    dist[s]=0;
    while (!q.empty()){
        int now=q.front();
        q.pop();
        for (auto wh:rreb[now]){
            if (dist[wh]>dist[now]+1){
                dist[wh]=dist[now]+1;
                q.push(wh);
            }
        }
    }
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif
    
    fast;
    
    int m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        rreb[v].pb(u);
    }
    int k;
    cin>>k;
    for (int i=0;i<k;i++){
        cin>>p[i];
    }
    int t=p[k-1];
    bfs(t);
    
    int ans1=0;
    int ans2=0;
    
    for (int i=0;i+1<k;i++){
        if (dist[p[i]]==dist[p[i+1]]+1){
            // nothing
        }
        else{
            ans1++;
        }
    }
    
    for (int i=0;i+1<k;i++){
        for (auto wh:reb[p[i]]){
            if (wh!=p[i+1]&&dist[p[i]]==dist[wh]+1){
                ans2++;
                break;
            }
        }
    }
    
    cout<<ans1<<" "<<ans2<<"\n";
}