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

vector<pair<pii,int>> reb[arr];
int dist[arr];
bool use[arr];
pii pred[arr];
int p[arr];

pii kek[arr];

void add_edge(int from,int to,int flow)
{
//    cout<<"from to :: "<<from<<" "<<to<<" ::: "<<flow<<"\n";
    int e1=len(reb[from]);
    int e2=len(reb[to]);
    reb[from].pb({{to,flow},e2});
    reb[to].pb({{from,0},e1});
}

int s,t; /// s must be equal to 0

bool bfs()
{
    for (int i=0;i<=t;i++){
        dist[i]=1e9;
        use[i]=0;
        pred[i]={-1,-1};
        p[i]=0;
    }
    queue<int> q;
    q.push(s);
    use[s]=1;
    dist[s]=0;
    while (!q.empty()){
        int now=q.front();
        q.pop();
        int num=0;
        for (auto wh:reb[now]){
            if (!use[wh.fir.fir]&&wh.fir.sec){
                use[wh.fir.fir]=1;
                dist[wh.fir.fir]=dist[now]+1;
                q.push(wh.fir.fir);
            }
            num++;
        }
    }
    return dist[t]<1e9;
}

void dfs(int now)
{
//    cout<<" dfs :: "<<now<<"\n";
    use[now]=1;
    if (use[t]){
        return;
    }
    for (;p[now]<len(reb[now]);){
        int to=reb[now][p[now]].fir.fir;
        if (dist[to]==dist[now]+1&&reb[now][p[now]].fir.sec){
            dfs(to);
            pred[to]={now,p[now]};
            if (use[t]){
                return;
            }
        }
        p[now]++;
    }
}

int go_back()
{
//    cout<<" go_back !!\n";
    int cur;

    cur=t;
    while (cur!=s){
//        cout<<"  "<<cur<<"\n";
        int from=pred[cur].fir;
        int num=pred[cur].sec;

        reb[from][num].fir.sec--;
//        cout<<"   new flow :: " <<reb[from][num].fir.sec<<"\n";
        reb[cur][reb[from][num].sec].fir.sec++;

        cur=from;
    }
//    cout<<"\n";

    return 1;
}

int ans=0;

void max_flow()
{
    while (bfs()){
        for (int i=0;i<=t;i++){
            p[i]=0;
        }
//        cout<<"new dfsing !!!"<<"\n";
        while (1){
            for (int i=0;i<=t;i++){
                use[i]=0;
                pred[i]={-1,-1};
            }
            dfs(s);
            if (!use[t]){
                break;
            }
//            cout<<"ans++"<<"\n";
            ans+=go_back();
        }
    }
}

int cnt1[arr];
int cnt2[arr];

int lol[arr];
int bur[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n1,n2,m;
    cin>>n1>>n2>>m;
    for (int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        cnt1[u]++;
        cnt2[v]++;
        bur[i]=v;
        add_edge(u,n1+v,1);

        kek[i]={u,len(reb[u])-1};
    }

    for (int j=1;j<=n1;j++){
        add_edge(s,j,0);
    }
    t=n1+n2+1;
    for (int j=1;j<=n2;j++){
        add_edge(n1+j,t,0);
    }

    int MAX=min(*min_element(cnt1+1,cnt1+n1+1),*min_element(cnt2+1,cnt2+n2+1));
    cout<<0<<"\n";
    for (int i=1;i<=MAX;i++){
        for (auto& j:reb[s]){
            j.fir.sec++;
        }
        for (int j=1;j<=n2;j++){
            for (auto& k:reb[n1+j]){
                if (k.fir.fir==t){
                    k.fir.sec++;
                }
            }
        }
        max_flow();
        int c2=ans;
//        cout<<"i :: "<<i<<" ans :: "<<ans<<"\n";
        int ANSWER=(n1+n2)*i-c2;
        cout<<ANSWER<<" ";
        for (int j=1;j<=n1;j++){
            lol[j]=i;
        }
        for (int j=1;j<=n2;j++){
            lol[n1+j]=i;
        }
        for (int j=1;j<=m;j++){
            if (reb[kek[j].fir][kek[j].sec].fir.sec==0){
                cout<<j<<" ";
                lol[kek[j].fir]--;
                lol[n1+bur[j]]--;
            }
        }
        for (int j=1;j<=m;j++){
            if (reb[kek[j].fir][kek[j].sec].fir.sec==1){
                if (lol[kek[j].fir]>0||lol[n1+bur[j]]>0){
                    cout<<j<<" ";
                    lol[kek[j].fir]--;
                    lol[n1+bur[j]]--;
                }
            }
        }
        cout<<"\n";
    }
}