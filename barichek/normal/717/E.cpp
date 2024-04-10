#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int maxint=numeric_limits<int>::max();
const ll maxll=numeric_limits<ll>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ll md=1e9+7;
const ld eps=1e-10;

///---program start---///

int n,cnt[arr],color[arr];
vi reb[arr];

void dfs(int now=1,int pred=1)
{
    if (now!=1)
        color[now]^=1;
    cout<<now<<" ";
    for (auto wh:reb[now])
        if (wh!=pred&&cnt[wh]>0)
        {
            dfs(wh,now);
            cout<<now<<" ";
            color[now]^=1;
        }
    if (color[now]==0)
    {
        if (now==1)
            cout<<reb[1][0]<<" "<<1<<" "<<reb[1][0];
        else
            cout<<pred<<" "<<now<<" ",
            color[pred]^=1;
    }
}

int __dfs(int now=1,int pred=1)
{
    int res=color[now]==0;
    for (auto wh:reb[now])
        if (wh!=pred)
            res+=__dfs(wh,now);
    cnt[now]=res;
    return res;
}

main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&color[i]);
        if (color[i]==-1) color[i]=0;
    }
    for (int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        reb[u].pb(v);
        reb[v].pb(u);
    }
    __dfs();
    dfs();
}