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

vi reb[arr];
int step[arr];
pii ans[arr];

/// 0- left
/// 1 - up
/// 3 - right
/// 2 - down

void dfs(int now=1,int pred=-1,int from=-1,int len=1e15,int xxx=0,int yyy=0)
{
    cerr<<now<<" "<<pred<<" "<<from<<" "<<len<<" "<<xxx<<" "<<yyy<<"\n";
    int cur_put=-1;
    ans[now]=mp(xxx,yyy);
    for (auto wh:reb[now])
        if (wh!=pred)
        {
            cur_put++;
            cur_put+=(cur_put==from);
            int xxx_new=xxx;
            int yyy_new=yyy;
            if (cur_put==0)
                xxx_new-=len;
            if (cur_put==3)
                xxx_new+=len;
            if (cur_put==1)
                yyy_new+=len;
            if (cur_put==2)
                yyy_new-=len;
            dfs(wh,now,3-cur_put,len/2,xxx_new,yyy_new);
        }
}

main()
{
    int n;
    cin>>n;
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        reb[v].pb(u);
        step[u]++;
        step[v]++;
    }
    for (int i=1;i<=n;i++)
        if (step[i]>=5) return cout<<"NO", 0;
    dfs();
    cout<<"YES\n";
    for (int i=1;i<=n;i++)
        cout<<ans[i].fir<<" "<<ans[i].sec<<"\n";
}