#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define files_ds(name) freopen(name".dat","r",stdin); freopen(name".sol","w",stdout);
#define all(a) a.begin(),a.end()
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
vi ans;
bool use[arr];

void dfs(int now=1,int pred=-1)
{
    use[now]=1;
    ans.pb(now);
    for (auto wh:reb[now])
        if (!use[wh])
            dfs(wh,now);
    if (pred!=-1)
        ans.pb(pred);
}

main()
{
    fast;
    int n,m,k;
    cin>>n>>m>>k;
    while (m--)
    {
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        reb[v].pb(u);
    }
    dfs();
    reverse(all(ans));
    int can=2*n/k+(2*n%k>0);
    for (int i=1;i<=k;i++)
    {
        vi cur_ans;
        cur_ans.clear();
        int cur_can=can;
        while (cur_can--&&!ans.empty())
            cur_ans.pb(ans.back()),
            ans.pop_back();
        if (cur_ans.empty())
            cur_ans.pb(1);
        cout<<cur_ans.size()<<" ";
        for (auto j:cur_ans)
            cout<<j<<" ";
        cout<<"\n";
    }
}