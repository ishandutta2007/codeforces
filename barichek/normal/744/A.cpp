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

const int maxint=numeric_limits<int>::max();
const ll maxll=numeric_limits<ll>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

bool ok[arr];
int step[arr];
vi reb[arr];
bool visit[arr];

pair<int,pair<bool,int>> dfs(int now)
{
    pair<int,pair<bool,int>> res={step[now],{ok[now],1}};
    visit[now]=true;
    for (auto wh:reb[now])
        if (!visit[wh])
        {
            auto rem=dfs(wh);
            res.sec.fir|=rem.sec.fir;
            res.sec.sec+=rem.sec.sec;
            res.fir+=rem.fir;
        }
    return res;
}

main()
{
    int n,m,k;
    cin>>n>>m>>k;
    while (k--)
    {
        int u;
        cin>>u;
        ok[u]=true;
    }
    while (m--)
    {
        int u,v;
        cin>>u>>v;
        step[u]++;
        step[v]++;
        reb[u].pb(v);
        reb[v].pb(u);
    }
    vector<pair<int,pair<bool,int>>> vec;
    vec.clear();
    for (int i=1;i<=n;i++)
        if (!visit[i])
            vec.pb(dfs(i));
    int max_=-1e9;
    for (auto &i:vec)
        i.fir/=2;
    int cnt_good=0;
    int cnt_good_reb=0;
    int cnt_bad=0;
    int ans=0;
    for (auto i:vec)
        if (!i.sec.fir)
            cnt_good+=i.sec.sec,
            cnt_good_reb+=i.fir;
        else
            max_=max(max_,i.sec.sec),
            ans+=i.sec.sec*(i.sec.sec-1)/2-i.fir;
    //cout<<ans<<" "<<cnt_good<<" "<<max_<<" "<<cnt_good_reb<<"\n";
    cout<<ans+(cnt_good)*(cnt_good-1)/2+cnt_good*max_-cnt_good_reb;
}