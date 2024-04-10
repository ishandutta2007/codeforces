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

int cnt=0;

struct Node
{
    int l,r,sum;

    Node()
    {
    }
};

Node v[5*arr];

void sons(int u)
{
    if (cnt>5*arr) exit(0);
    if (v[u].l==0)
        v[u].l=++cnt;
    if (v[u].r==0)
        v[u].r=++cnt;
}

void change(int i1, int i2, int tl, int tr, int x)
{
    v[i2]=v[i1];
    if (tl==tr)
    {
        v[i2].sum++;
        return;
    }
    sons(i1);
    v[i2]=v[i1];
    int d=(tl+tr)/2;
    if (x<=d)
    {
        v[i2].l=++cnt;
        change(v[i1].l,v[i2].l,tl,d,x);
    } else
    {
        v[i2].r=++cnt;
        change(v[i1].r,v[i2].r,d+1,tr,x);
    }
    v[i2].sum=v[v[i2].l].sum+v[v[i2].r].sum;
}

int get(int &i1, int &i2, int tl, int &tr, int &l, int &r)
{
    if (i2==0) return(0);
    if (tl>=l && tr<=r) return(v[i2].sum-v[i1].sum);
    if (tl>r || tr<l) return(0);
    int d=(tl+tr)/2;
    return(get(v[i1].l,v[i2].l,tl,d,l,r)+get(v[i1].r,v[i2].r,d+1,tr,l,r));
}

int root[arr];
int n,k;
vector<int> vec[arr];

map<pair<int,int>, int > mp;

int nul=0;

int get(int l,int r)
{
    if (l>r) return(0);
    if (!mp.count({l,r}))
        {
            int l_=l-1;
            mp[{l,r}]=get(root[l_],root[r],nul,n,nul,l_);
        }
    return(mp[{l,r}]);
}

int get(int nom, int l, int r)
{
    int left=*lower_bound(vec[nom].begin(),vec[nom].end(),l);
    return(left>r);
}

int a[arr],b[arr],last[arr];

int dp[36000][52];

map<int,int> coun;

void solve(int j, int tl, int tr, int l, int r)
{
    if (tl>tr) return;

    int m=(tl+tr)/2;
    int imx=0;
    coun.clear();
    dp[m][j]=0;
    int now=get(r+2,m);
    for (int i=min(r,m-1);i>=l;i--)
    {
        now+=get(a[i+1],i+2,m);
        if (now+dp[i][j-1]>dp[m][j])
        {
            dp[m][j]=now+dp[i][j-1];
            imx=i;
        }
    }

    solve(j,tl,m-1,l,imx);
    solve(j,m+1,tr,imx,r);
}

signed main()
{
    fast;
    cin>>n>>k;

    for (int i=1;i<=n;i++)
        vec[i].pb(-1e9);

    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        vec[a[i]].pb(i);
        b[i]=last[a[i]];
        last[a[i]]=i;
    }

    for (int i=1;i<=n;i++)
        vec[i].pb(1e9);

    root[0]=++cnt;
    v[1].sum=0;
    v[1].l=0;
    v[1].r=0;
    v[0].l=0;
    v[0].r=0;
    for (int i=1;i<=n;i++)
    {
        root[i]=++cnt;
        change(root[i-1],root[i],0,n,b[i]);
    }

    for (int i=1;i<=k;i++)
    {
        solve(i,i,n,i-1,n-1);
    }
    cout<<dp[n][k];
}