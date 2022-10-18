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

#define arr int(2e6+10)

int n,m;
vi reb[arr];
int komp[arr];
bool use[arr];
int s,t,ds,dt;
int komp_;
vector<pii> ans;

void dfs(int now)
{
    komp[now]=komp_;
    use[now]=true;
    for (auto wh:reb[now])
        if (!use[wh])
            ans.pb(mp(now,wh)),
            dfs(wh);
}

main()
{
    cin>>n>>m;
    bool is_st=false;
    while (m--)
    {
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        reb[v].pb(u);
    }
    cin>>s>>t>>ds>>dt;
    for (auto i:reb[s])
        if (i==t)
            is_st=true;
    use[s]=true;
    use[t]=true;
    for (int i=1;i<=n;i++)
        if (!use[i])
        {
            komp_++;
            dfs(i);
        }
    //for (auto i:ans)
      //  cout<<i.fir<<" "<<i.sec<<" !!!\n";
    set<int> with_s;
    map<int,int> how_s;
    set<int> with_t;
    map<int,int> how_t;
    set<int> s_and_t;
    for (auto i:reb[s])
        if (i!=t)
        {
            with_s.insert(komp[i]),
            how_s[komp[i]]=i;
        }
    for (auto i:reb[t])
        if (i!=s)
        {
            with_t.insert(komp[i]),
            how_t[komp[i]]=i;
        }
    //cout<<"with_s:\n";
    //for (auto i:with_s)
      //  cout<<i<<" ";
    //cout<<"\n";
    //cout<<"with_t:\n";
    //for (auto i:with_t)
      //  cout<<i<<" ";
    //cout<<"\n";
    for (auto i:with_s)
        if (!with_t.count(i))
        {
            //cout<<i<<" @@111@\n";
            ans.pb(mp(s,how_s[i]));
            ds--;
        }
        else s_and_t.insert(i);
    for (auto i:with_t)
        if (!with_s.count(i))
        {
            //cout<<i<<" @@222@\n";
            ans.pb(mp(t,how_t[i]));
            dt--;
        }
    //for (auto i:ans)
      //  cout<<i.fir<<" "<<i.sec<<" !!!\n";
    if (is_st&&with_s.empty())
    {
        ds--;
        dt--;
        ans.pb(mp(s,t));
    }
    else
    {
        int to_s=-1e7;
        int to_t=-1e7;
        for (auto i:s_and_t)
            if (ds>dt)
                ds--,
                to_s=i,
                ans.pb(mp(how_s[i],s));
            else
                dt--,
                to_t=i,
                ans.pb(mp(how_t[i],t));
        if (ds>0&&to_t!=-1e7)
            ans.pb(mp(how_s[to_t],s)),
            ds--;
        elif (dt>0&&to_s!=-1e7)
            ans.pb(mp(how_t[to_s],t)),
            dt--;
        elif (is_st)
            ans.pb(mp(s,t)),
            ds--,
            dt--;
    }
    if (ds<0||dt<0||ans.size()!=n-1) return cout<<"No", 0;
    cout<<"Yes\n";
    for (auto i:ans)
        cout<<i.fir<<" "<<i.sec<<"\n";
}