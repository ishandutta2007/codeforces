#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define fir first
#define sec second
#define pb push_back
#define int long long
using namespace std;
typedef double ld;
typedef long long ll;
const int md=1e9+7;
int get_hesh(vector<int> vec)
{
    int res=0;
    for (int i=0;i<vec.size();i++)
    {
        res*=800000;
        res+=vec[i];
        res%=md;
    }
    return(res);
}

vector<int> vec[500000];
int hesh[500000];
map<vector<int>,int> mp;
set<int> setik[500000];
void bad()
{
    cout<<"NO";
    exit(0);
}
int now=0,ans[500000];
void dfs(int u)
{
    ans[u]=++now;
    for (auto i:setik[u])
        if (ans[i]==0) dfs(i);
}
int n,m;
void good(int i)
{
    cout<<"YES"<<'\n';
    dfs(i);
    for (int i=1;i<=n;i++)
        cout<<ans[hesh[i]]<<' ';

    exit(0);
}
///---program start---///
main()
{
    cin>>n>>m;
    while (m--)
    {
        int a,b;
        cin>>a>>b;
        vec[a].pb(b);
        vec[b].pb(a);
    }
    for (int i=1;i<=n;i++)
        vec[i].pb(i);
    for (int i=1;i<=n;i++)
    {
        sort(vec[i].begin(),vec[i].end());
        //hesh[i]=get_hesh(vec[i]);
        mp[vec[i]]++;
    }
    int cnt=0;
    for (auto i:mp)
    {
        mp[i.fir]=++cnt;
    }
    for (int i=1;i<=n;i++)
    {
        hesh[i]=mp[vec[i]];
    }
    for (int i=1;i<=n;i++)
        for (int j=0;j<vec[i].size();j++)
            if (hesh[i]!=hesh[vec[i][j]])
            {
                setik[hesh[i]].insert(hesh[vec[i][j]]);
              //  setik[hesh[vec[i][j]]].insert(hesh[i]);
            }
    //cout<<setik[hesh[5]].size()<<'\n';
    for (int i=1;i<=n;i++)
        if (setik[hesh[i]].size()>2)
        bad();

    for (int i=1;i<=n;i++)
        if (setik[hesh[i]].size()<=1 )
    {
        good(hesh[i]);
    }
    bad();


}