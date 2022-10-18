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

#define int ll

int n,m,k;
vi color;
map<int,int> cnt;
vi reb[arr];
bool use[arr];
int ans;

int dfs(int now)
{
    int res=1;
    if (++cnt[color[now]]>cnt[ans])
        ans=color[now];
    use[now]=true;
    for (auto wh:reb[now])
        if (!use[wh])
            res+=dfs(wh);
    return res;
}

main()
{
    fast;
    cin>>n>>m>>k;
    color.resize(n);
    for (auto &i:color)
        cin>>i;
    while (m--)
    {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        reb[u].pb(v);
        reb[v].pb(u);
    }
    int res=0;
    for (int i=0;i<n;i++)
        if (!use[i])
        {
            ans=0;
            cnt.clear();
            int dop=dfs(i);
            res+=dop-cnt[ans];
        }
    cout<<res;
}