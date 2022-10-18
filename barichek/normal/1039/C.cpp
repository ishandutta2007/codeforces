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

#define arr (int)(5e5+10)

int sum(int a,int b)
{
    a+=b;
    a%=md;
    if (a<0){
        a+=md;
    }
    return a;
}

int mult(int a,int b)
{
    a*=b;
    a%=md;
    if (a<0){
        a+=md;
    }
    return a;
}

int bpow(int a,int n)
{
    int res=1;
    while (n){
        if (n&1){
            res=res*a%md;
        }
        n/=2;
        a=a*a%md;
    }
    return res;
}

int c[arr];

int cur_ans;

bool use[arr];
int sum_sizes;
int count_comp;
vi reb[arr];

void dfs(int now)
{
    use[now]=1;
    sum_sizes++;
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

    fast;

    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,pii>> edges(0);
    for (int i=1;i<=n;i++){
        cin>>c[i];
    }
    while (m--){
        int u,v;
        cin>>u>>v;
        int val=c[u]^c[v];
        edges.pb({val,{u,v}});
    }
    sort(all(edges));
    int ans=mult(bpow(2,n),(1ll<<k)%md);
    for (int i=0;i<len(edges);){

        sum_sizes=0;
        count_comp=0;

        int j;

        j=i;
        while (j<len(edges)&&edges[j].fir==edges[i].fir){
            int u=edges[j].sec.fir;
            int v=edges[j].sec.sec;

            reb[u].pb(v);
            reb[v].pb(u);

            j++;
        }

        j=i;
        while (j<len(edges)&&edges[j].fir==edges[i].fir){
            int u=edges[j].sec.fir;
            int v=edges[j].sec.sec;

            if (!use[u]){
                dfs(u);
                count_comp++;
            }

            j++;
        }

        j=i;
        while (j<len(edges)&&edges[j].fir==edges[i].fir){
            int u=edges[j].sec.fir;
            int v=edges[j].sec.sec;

            use[u]=0;
            use[v]=0;
            reb[u].clear();
            reb[v].clear();

            j++;
        }

        cur_ans=sum(bpow(2,sum_sizes),-bpow(2,count_comp));
        cur_ans=mult(cur_ans,bpow(2,n-sum_sizes));

        ans=sum(ans,-cur_ans);

        i=j;
    }
    cout<<ans<<"\n";
}