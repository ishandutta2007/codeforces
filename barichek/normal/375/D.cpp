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

int tin[arr];
int tout[arr];
vi reb[arr];
int timer;
int color_of_vertex[arr];
int color_of_position_in_array[arr];
int bsize=470;

int cnt[arr];
int answer[arr];

void dfs(int now=1,int pred=-1)
{
    tin[now]=++timer;
    for (auto wh:reb[now])
        if (wh!=pred)
            dfs(wh,now);
    tout[now]=timer;
}

int ans[arr];

const bool cmp(const pair<pii,pii>& lhs,const pair<pii,pii>& rhs)
{
    if (lhs.fir.fir/bsize!=rhs.fir.fir/bsize){
        return lhs.fir.fir<rhs.fir.fir;
    }
    return lhs.fir.sec<rhs.fir.sec;
}

inline void add(int pos)
{
    answer[++cnt[color_of_position_in_array[pos]]]++;
}

inline void del(int pos)
{
    answer[cnt[color_of_position_in_array[pos]]--]--;
}

int n,m;
pair<pii,pii> req[arr];

void do_sqrt()
{
    sort(req,req+m);
    int l=1,r=1;
    for (int j=0;j<m;j++){
        int L=req[j].fir.fir;
        int R=req[j].fir.sec;
        while (r<=R)
            add(r++);
        while (l>L)
            add(--l);
        while (l<L)
            del(l++);
        while (r>R+1)
            del(--r);
        ans[req[j].sec.sec]=answer[req[j].sec.fir];
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d",&color_of_vertex[i]);
    for (int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        reb[u].pb(v);
        reb[v].pb(u);
    }
    dfs();
    for (int i=1;i<=n;i++)
        color_of_position_in_array[tin[i]]=color_of_vertex[i];
    for (int i=1;i<=m;i++)
    {
        int v,k;
        scanf("%d%d",&v,&k);
        req[i-1]=mp(mp(tin[v],tout[v]),mp(k,i));
    }
    do_sqrt();
    for (int i=1;i<=m;i++)
        cout<<ans[i]<<"\n";
}