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

int n,m;
int his[arr];
vi st[5*arr];
int tin[arr];
int tout[arr];
int timer;
int who_had_this_tin[arr];
int pref[arr];
int a[arr];
vector<pii> reb[arr];

void ___st(int v=1,int l=1,int r=n)
{
    if (l==r)
        return void(st[v].pb(his[who_had_this_tin[l]]));
    ___st(v*2,l,(l+r)/2);
    ___st(v*2+1,(l+r)/2+1,r);
    st[v].resize(r-l+1);
    merge(all(st[v*2]),all(st[v*2+1]),st[v].begin());
}

int _st(int tl,int tr,int v,int l,int r,int val)
{
    if (l>tr||r<tl) return 0;
    if (l>=tl&&r<=tr)
        return upper_bound(all(st[v]),val)-st[v].begin();
    return _st(tl,tr,v*2,l,(l+r)/2,val)+_st(tl,tr,v*2+1,(l+r)/2+1,r,val);
}

void dfs(int now=1,int pred=-1,int cost=0)
{
    pref[now]=(pred==-1?0:pref[pred])+cost;
    tin[now]=++timer;
    who_had_this_tin[tin[now]]=now;
    for (auto wh:reb[now])
        if (wh.fir!=pred)
            dfs(wh.fir,now,wh.sec);
    tout[now]=timer;
}

main()
{
    fast;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=2;i<=n;i++)
    {
        int u,cost;
        cin>>u>>cost;
        reb[u].pb(mp(i,cost));
        reb[i].pb(mp(u,cost));
    }
    dfs();
    for (int i=1;i<=n;i++)
        his[i]=pref[i]-a[i];
    ___st();
    for (int i=1;i<=n;i++)
        //cout<<"_st with i=="<<i<<" && tin tout :: "<<tin[i]<<" "<<tout[i]<<"\n",
        cout<<_st(tin[i],tout[i],1,1,n,pref[i])-1<<" ";
}