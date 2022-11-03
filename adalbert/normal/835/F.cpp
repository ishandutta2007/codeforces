#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <memory.h>
#include <string.h>
#include <complex>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".sol","r",stdin); freopen (name".dat","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define time pdojegoritg
typedef long long ll;
typedef long double ld;
const int arr=4*1e5;
#define int ll

int use[arr],len[arr];
vector<pair<int,int> > vec[arr];
vector<int> way,cycle;

void get_cycle(int u, int pred)
{
    use[u]=1;
    way.pb(u);
    for (int i=0;i<vec[u].size();i++)
        if (vec[u][i].fir!=pred && cycle.empty())
        {
            if (use[vec[u][i].fir])
            {
                reverse(way.begin(),way.end());
                while (way.back()!=vec[u][i].fir)
                    way.pop_back();
                cycle=way;

            } else
            get_cycle(vec[u][i].fir,u);
        }
    way.pop_back();
    use[u]=0;
}

int dfs(int u, int p1, int p2, int pred)
{
    int res=0;
    for (int i=0;i<vec[u].size();i++)
        if(vec[u][i].fir!=pred && vec[u][i].fir!=p1 && vec[u][i].fir!=p2)
        {
            res=max(res,vec[u][i].sec+dfs(vec[u][i].fir,p1,p2,u));
        }
    return(res);
}

int prefd[arr],sufd[arr],pref[arr],suf[arr],ans[arr];
map<pair<int,int> ,int> mp;

void dell(int a, int b)
{
    vector<pair<int,int> > now;
    for (int i=0;i<vec[a].size();i++)
        if (vec[a][i].fir!=b)
        now.pb(vec[a][i]);
    vec[a]=now;
}

int mx_,imx;

void solve(int u, int ln, int pred)
{
    if (ln>mx_)
    {
        mx_=ln;
        imx=u;
    }
    for (int i=0;i<vec[u].size();i++)
        if (vec[u][i].fir!=pred)
        {
            solve(vec[u][i].fir,ln+vec[u][i].sec,u);
        }
}

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int u,v,l;
        cin>>u>>v>>l;
        vec[u].pb({v,l});
        vec[v].pb({u,l});
        mp[{u,v}]=l;
        mp[{v,u}]=l;
    }

    get_cycle(1,-1);

    for (int i=0;i<cycle.size();i++)
    {
        len[i+1]=dfs(cycle[i],cycle[(i+1)%cycle.size()],cycle[(i-1+cycle.size())%cycle.size()], -1);
    }


    int k=cycle.size();
    int now=0;
    int mx=0;
    for (int i=1;i<=k;i++)
    {
        pref[i]=now+len[i];
        prefd[i]=pref[i]+mx;
        mx=max(mx,len[i]-now);
        if (i!=k)
        now+=mp[{cycle[i-1],cycle[i]}];
    }

    for (int i=1;i<=k;i++)
        prefd[i]=max(prefd[i],prefd[i-1]);

    for (int i=1;i<=k;i++)
        pref[i]=max(pref[i],pref[i-1]);

    ans[k]=prefd[k];

    mx=0;
    now=mp[{cycle[0],cycle.back()}];
    for (int i=k;i>=1;i--)
    {
        suf[i]=now+len[i];
        sufd[i]=suf[i]+mx;
        mx=max(mx,len[i]-now);
        if (i!=1)
            now+=mp[{cycle[i-1],cycle[i-2]}];
    }

    for (int i=k;i>=1;i--)
        suf[i]=max(suf[i],suf[i+1]);

    for (int i=k;i>=1;i--)
        sufd[i]=max(sufd[i],sufd[i+1]);

    for (int i=1;i<k;i++)
        ans[i]=max({suf[i+1]+pref[i],sufd[i+1],prefd[i]});

    int mn=1e18;
    int imn=0;
    for (int i=1;i<=k;i++)
        if (ans[i]<mn)
        {
            mn=ans[i];
            imn=i;
        }
    dell(cycle[imn-1],cycle[(imn)%cycle.size()]);
    dell(cycle[(imn)%cycle.size()],cycle[imn-1]);

    solve(1,0,0);
    solve(imx,0,0);
    cout<<mx_;
}