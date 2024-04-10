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
///#define int long long

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

vi reb1[arr];
vi reb2[arr];
bool use[arr];
int comp[arr];
const int M=70/4+1;
int dist[1ll<<M][71];
bool q_visit[1ll<<M][71];

void dfs(int now,int c)
{
    comp[now]=c;
    use[now]=1;
    for (auto wh:reb1[now]){
        if (!use[wh]){
            dfs(wh,c);
        }
    }
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,m,a,b;
    cin>>n>>m>>a>>b;
    for (int i=0;i<m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        if (c==a){
            reb1[u].pb(v);
            reb1[v].pb(u);
        }
        if (c==b){
            reb2[u].pb(v);
            reb2[v].pb(u);
        }
    }
    int c=0;
    int cc=1e5;
    for (int i=1;i<=n;i++){
        if (!use[i]){
            dfs(i,++c);
            int cnt=0;
            for (int j=1;j<=n;j++){
                if (comp[j]==c){
                    cnt++;
                }
            }
            if (cnt<=3){
                for (int j=1;j<=n;j++){
                    if (comp[j]==c){
                        comp[j]=cc;
                    }
                }
                cc--;
                c--;
            }
        }
    }

//    for (int i=1;i<=n;i++){
//        cout<<"comp["<<i<<"] :: "<<comp[i]<<"\n";
//    }

    priority_queue<pair<int,pii>,
    vector<pair<int,pii>>,
    greater<pair<int,pii>>> s;
    int start_mask=0;
    if (comp[1]<=c){
        start_mask|=(1ll<<(comp[1]-1));
    }
    for (int m=0;m<(1ll<<c);m++){
        for (int j=1;j<=n;j++){
            if (j==1&&m==start_mask){
                dist[m][j]=0;
            }
            else{
                dist[m][j]=2e9+1;
            }
            s.emplace(mp(dist[m][j],mp(m,j)));
        }
    }

    function<bool(int,int)> have_bit=[&](int m,int bit)
    {
        return m&(1ll<<bit);
    };

    while (!s.empty()){
        pii now=s.top().sec;
        s.pop();
        if (q_visit[now.fir][now.sec]){
            continue;
        }
        q_visit[now.fir][now.sec]=1;
        for (auto wh:reb1[now.sec]){
            if (comp[wh]>c||comp[now.sec]==comp[wh]||!have_bit(now.fir,comp[wh]-1)){
                int to_m=now.fir|(comp[wh]>c?0:(1ll<<(comp[wh]-1)));
                if (dist[to_m][wh]>dist[now.fir][now.sec]+a){
                    dist[to_m][wh]=dist[now.fir][now.sec]+a;
                    s.emplace(mp(dist[to_m][wh],mp(to_m,wh)));
                }
            }
        }
        for (auto wh:reb2[now.sec]){
            if ((comp[wh]>c||!have_bit(now.fir,comp[wh]-1))
                &&(comp[wh]!=comp[now.sec])){
                int to_m=now.fir|(comp[wh]>c?0:(1ll<<(comp[wh]-1)));
                if (dist[to_m][wh]>dist[now.fir][now.sec]+b){
                    dist[to_m][wh]=dist[now.fir][now.sec]+b;
                    s.emplace(mp(dist[to_m][wh],mp(to_m,wh)));
                }
            }
        }
    }

    for (int j=1;j<=n;j++){
        int ans=2e9+1;
        for (int m=0;m<(1ll<<c);m++){
            ans=min(ans,dist[m][j]);
        }
        cout<<ans<<" ";
    }
    cout<<"\n";
}