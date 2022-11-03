#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define fir first
#define sec second
#define pb push_back
using namespace std;
typedef double ld;
typedef long long ll;
const int arr=5e5;
vector<ll> vec[4];
int n,m;
void solve1()
{
    ll ans=0;
    for (int i=1;i<vec[1].size();i++)
        vec[1][i]+=vec[1][i-1];
    for (int i=1;i<vec[2].size();i++)
        vec[2][i]+=vec[2][i-1];
    for (int i=0;i<vec[3].size();i++)
    {
        int remains=m-(i+1)*3;
        if (remains>=0) ans=max(ans,vec[3][i]);
        if (remains<2) continue;
        ans=max(ans,vec[3][i]+vec[2][min(int(vec[2].size())-1,remains/2-1)]);
    }
    if (m>=2)
        ans=max(ans,vec[2][min(int(vec[2].size())-1,m/2-1)]);
    //if (ans==40003999) exit(1);
    cout<<ans;
    exit(0);
}
void solve2()
{
    ll ans=0;
    for (int i=1;i<vec[1].size();i++)
        vec[1][i]+=vec[1][i-1];
    for (int i=1;i<vec[2].size();i++)
        vec[2][i]+=vec[2][i-1];
    for (int i=0;i<vec[3].size();i++)
    {
        int remains=m-(i+1)*3;
        if (remains==0) ans=max(ans,vec[3][i]);
        if (remains<1) continue;
        ans=max(ans,vec[3][i]+vec[1][min(int(vec[1].size())-1,remains-1)]);
    }
    if (m>=1)
        ans=max(ans,vec[1][min(int(vec[1].size())-1,m-1)]);
    if (ans==40003999) exit(1);
    cout<<ans;
    exit(0);
}
void solve12()
{
    int ans=0;
    for (int i=0;i<vec[3].size();i++)
    {
        if ((i+1)*3<=m) ans=vec[3][i];
    }
    //if (ans==40003999) exit(1);
    cout<<ans;
    exit(0);
}
///---program start---///
main()
{

    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        int t,cost;
        cin>>t>>cost;
        vec[t].pb(cost);
    }
    for (int i=1;i<=3;i++)
    {
        sort(vec[i].begin(),vec[i].end());
        reverse(vec[i].begin(),vec[i].end());
    }
    for (int i=1;i<vec[3].size();i++)
        vec[3][i]+=vec[3][i-1];
    if (vec[1].empty() && !vec[2].empty()) solve1();
    if (vec[2].empty() && !vec[1].empty()) solve2();
    if (vec[1].empty() && vec[2].empty()) solve12();
    vector<ll> odd;
    vector<ll> fresh;
    int pluss=0;
    pluss=vec[1][0];
    for (int i=0;i+1<vec[1].size();i+=2)
        fresh.pb(vec[1][i]+vec[1][i+1]);
    if (vec[1].size()%2==1)
        fresh.pb(vec[1][vec[1].size()-1]);
    for (int i=0;i<vec[2].size();i++)
        fresh.pb(vec[2][i]);
    for (int i=1;i+1<vec[1].size();i+=2)
        odd.pb(vec[1][i]+vec[1][i+1]);
    if (vec[1].size()%2==0)
        odd.pb(vec[1][vec[1].size()-1]);
    for (int i=0;i<vec[2].size();i++)
        odd.pb(vec[2][i]);

    sort(odd.begin(),odd.end());
    sort(fresh.begin(),fresh.end());
    reverse(odd.begin(),odd.end());
    reverse(fresh.begin(),fresh.end());
    for (int i=1;i<odd.size();i++)
        odd[i]+=odd[i-1];
    for (int i=1;i<fresh.size();i++)
        fresh[i]+=fresh[i-1];


    ll ans=0;
    for (int i=0;i<vec[3].size();i++)
    {
        if ((i+1)*3>m) continue;
        int remains=m-(i+1)*3;
        if (remains%2==0)
        {
            if (remains!=0)
            {
                ans=max(ans,vec[3][i]+fresh[min(int(fresh.size())-1,remains/2-1)]);
            } else
            {
                ans=max(ans,vec[3][i]);
            }
        } else
        {
            if (remains!=1)
            {
                ans=max(ans,vec[3][i]+pluss+odd[min(int(odd.size())-1,remains/2-1)]);
            } else
            {
                ans=max(ans,vec[3][i]+pluss);
            }
        }
    }
    int remains=m;
    if (remains%2==0)
    {
        if (remains!=0)
        {
            ans=max(ans,fresh[min(int(fresh.size())-1,remains/2-1)]);
        }
    } else
    {
        if (remains!=1)
        {
            ans=max(ans,pluss+odd[min(int(odd.size())-1,remains/2-1)]);
        } else
        {
            ans=max(ans,ll(pluss));
        }
    }
    cout<<ans;
}