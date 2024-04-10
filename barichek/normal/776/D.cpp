#pragma GCC optimize("O3")
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

int color[arr];
vi vec[arr];
int value[arr];
bool use[arr];
bool ok;
vector<pii> reb[arr];
vi cur;

void dfs(int now,int color)
{
    value[now]=color;
    cur.pb(now);
    use[now]=true;
    if (!ok) return;
    for (auto wh:reb[now])
        if (!use[wh.fir])
            dfs(wh.fir,(wh.sec+color)&1);
}

main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>color[i];
    for (int i=1;i<=m;i++)
    {
        int cnt;
        cin>>cnt;
        while (cnt--)
        {
            int val;
            cin>>val;
            vec[val].pb(i);
        }
    }
    for (int i=1;i<=n;i++)
    {
        int val1=vec[i].front();
        int val2=vec[i].back();
        reb[val1].pb(mp(val2,color[i]^1));
        reb[val2].pb(mp(val1,color[i]^1));
        //cerr<<"++reb :: "<<val1<<" "<<val2<<" "<<(color[i]^1)<<"\n";
    }
    for (int i=1;i<=m;i++)
        if (!use[i])
    {
        bool cur_ans=false;

        ok=true;
        cur.clear();
        dfs(i,0);
        for (auto j:cur)
            for (auto wh:reb[j])
                ok&=(value[j]+value[wh.fir])%2==wh.sec;
        for (auto j:cur)
            use[j]=false,
            value[j]=0;
        cur_ans|=ok;

        ok=true;
        cur.clear();
        dfs(i,1);
        for (auto j:cur)
            for (auto wh:reb[j])
                ok&=(value[j]+value[wh.fir])%2==wh.sec;
        for (auto j:cur)
            value[j]=0;
        cur_ans|=ok;

        if (!cur_ans) return cout<<"NO", 0;
    }
    cout<<"YES";
}