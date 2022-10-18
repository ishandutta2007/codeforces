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

int n;
vi a;
int ft[1000001];

void __ft(int x,int delta)
{
    for (int i=x;i<2*arr;i|=i+1)
        ft[i]+=delta;
}

int _ft(int x)
{
    int res=0;
    for (int i=x;i>=0;i=(i&(i+1))-1)
        res+=ft[i];
    return res;
}

int _ft(int l,int r)
{
    if (l>r) return 0;
    return _ft(r)-_ft(l-1);
}

vector<pii> reb[arr];
int tin[arr];
int tout[arr];
int timer;
int timer_=-1;
int pref[arr];
vi vhod_in[arr];
vi vhod_out[arr];
int ans_in[arr];
int ans_out[arr];

void dfs(int now=1,int pred=-1,int cost=0)
{
    pref[now]=(pred==-1?0:pref[pred])+cost;
    tin[now]=++timer;
    for (auto wh:reb[now])
        if (wh.fir!=pred)
            dfs(wh.fir,now,wh.sec);
    tout[now]=timer;
}

main()
{
    fast;
    cin>>n;
    a.resize(n);
    for (auto &i:a)
        cin>>i;
    for (int i=2;i<=n;i++)
    {
        int u,cost;
        cin>>u>>cost;
        reb[i].pb(mp(u,cost));
        reb[u].pb(mp(i,cost));
    }
    dfs();
    //for (int i=1;i<=n;i++)
      //  cout<<"tin&&tout "<<i<<" :: "<<tin[i]<<" "<<tout[i]<<"\n";
    for (int i=1;i<=n;i++)
        vhod_out[tout[i]].pb(i),
        vhod_in[tin[i]].pb(i);
    vi his(n+10,0);
    set<int> setik;
    setik.clear();
    for (int i=1;i<=n;i++)
        his[i]=pref[i]-a[i-1];
    for (int i=1;i<=n;i++)
        setik.insert(his[i]),
        setik.insert(pref[i]);
    map<int,int> vh;
    vh.clear();
    int cur_vh=0;
    for (auto i:setik)
        vh[i]=cur_vh++;
    for (int i=1;i<=arr;i++)
    {
        if (vhod_in[i].empty()) continue;
        ans_in[vhod_in[i].front()]=_ft(0,vh[pref[vhod_in[i].front()]]);
        __ft(vh[his[vhod_in[i].front()]],1);
        //cout<<"update_to :: "<<vh[his[vhod_in[i].front()]]<<" with vertex "<<vhod_in[i].front()<<"\n";
        for (auto j:vhod_out[i])
            //cout<<"getting ans_out for j=="<<j<<" with vh=="<<vh[pref[j]]<<" :: "<<_ft(0,vh[pref[j]])<<"\n",
            ans_out[j]=_ft(0,vh[pref[j]]);
    }
    vi ans(n+10,0);
    for (int i=1;i<=n;i++)
        ans[i]=ans_out[i]-ans_in[i]-(/*tin[i]!=tout[i]&&*/pref[i]>=his[i]);
    for (int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
}