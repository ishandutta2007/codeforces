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
#define int ll
typedef long long ll;
typedef long double ld;
const int arr=4*1e5;
const int md=1e9+7;

int ans=1;

int pow(int u, int step)
{
    if (step==0) return(1);
    if (step%2) return(pow(u,step-1)*u%md);
    return(pow(u*u%md,step/2));
}

struct reb
{
    int to,cost,t;
    reb();
    reb(int to_, int cost_, int t_)
    {
        to=to_;
        cost=cost_;
        t=t_;
    }
};

struct way
{
    int r,b,cost;
    way();
    way(int r_, int b_, int cost_)
    {
        r=r_;
        b=b_;
        cost=cost_;
    }
};

vector<reb> vec[arr];

vector<int> visit;

int sum[arr],mx[arr],use[arr],n;

void dfs(int u, int pred)
{
    visit.pb(u);
    sum[u]=1;
    mx[u]=0;
    for (int i=0;i<vec[u].size();i++)
        if(vec[u][i].to!=pred && !use[vec[u][i].to])
        {
            dfs(vec[u][i].to,u);
            sum[u]+=sum[vec[u][i].to];
            mx[u]=max(mx[u],sum[vec[u][i].to]);
        }
}

vector<way> ways;

void get(int u, int pred, int r, int b, int cost)
{
    if (use[u]) return;
    ways.pb(way(r,b,cost));

    for (int i=0;i<vec[u].size();i++)
        if (vec[u][i].to!=pred && !use[vec[u][i].to])
        {
            get(vec[u][i].to,u,r+vec[u][i].t,b+(vec[u][i].t==0),cost*vec[u][i].cost%md);
        }
}

struct Node
{
    int d, s;
    Node()
    {
        d=1;
        s=0;
    }
};

Node v1[16*arr+2],v2[16*arr+2];

void add1(int i, int tl, int tr, int x, int y)
{
    if (tl==tr)
    {
        v1[i].s++;
        v1[i].d*=y;
        v1[i].d%=md;
        return;
    }

    int d=(tl+tr)/2;
    if (x<=d)
        add1(i*2,tl,d,x,y); else
        add1(i*2+1,d+1,tr,x,y);

    v1[i].s=v1[i*2].s+v1[i*2+1].s;
    v1[i].d=v1[i*2].d*v1[i*2+1].d%md;
}

void add2(int i, int tl, int tr, int x, int y)
{
    if (tl==tr)
    {
        v2[i].s++;
        v2[i].d*=y;
        v2[i].d%=md;
        return;
    }

    int d=(tl+tr)/2;
    if (x<=d)
        add2(i*2,tl,d,x,y); else
        add2(i*2+1,d+1,tr,x,y);

    v2[i].s=v2[i*2].s+v2[i*2+1].s;
    v2[i].d=v2[i*2].d*v2[i*2+1].d%md;
   // cout<<v2[i].d<<' '<<v2[i].s<<' '<<y<<"!!!!!!!!!"<<'\n';
}

pair<int,int> get1(int i, int tl, int tr, int l, int r)
{
    if (tl>=l && tr<=r) return(make_pair(v1[i].d,v1[i].s));
    if (tl>r || tr<l) return(make_pair(1,0));

    int d=(tl+tr)/2;
    pair<int,int> g1=get1(i*2,tl,d,l,r);
    pair<int,int> g2=get1(i*2+1,d+1,tr,l,r);

    return(make_pair(g1.fir*g2.fir%md, g1.sec+g2.sec));
}

pair<int,int> get2(int i, int tl, int tr, int l, int r)
{
    if (tl>=l && tr<=r) return(make_pair(v2[i].d,v2[i].s));
    if (tl>r || tr<l) return(make_pair(1,0));

    int d=(tl+tr)/2;
    pair<int,int> g1=get2(i*2,tl,d,l,r);
    pair<int,int> g2=get2(i*2+1,d+1,tr,l,r);

    return(make_pair(g1.fir*g2.fir%md, g1.sec+g2.sec));
}

void clear_(int n)
{
    for (int i=0;i<=n;i++)
    {
        v1[i]=Node();
        v2[i]=Node();
    }
}

void solve(int u)
{

    if (use[u]) return;
    visit.clear();
    dfs(u,-1);

    int root=0;
    for (int i=0;i<visit.size();i++)
        if (max(mx[visit[i]],visit.size()-sum[visit[i]])<=visit.size()/2)
        root=visit[i];

    if (root==0) return;
    //cout<<root<<"kldsidrhfsguesghregf"<<'\n';
    u=root;
    n=visit.size();
    clear_(16*n);

    for (int i=0;i<vec[u].size();i++)
    {
        ways.clear();
        get(vec[u][i].to,u,vec[u][i].t,!vec[u][i].t,vec[u][i].cost);

        for (int j=0;j<ways.size();j++)
        {
            if (ways[j].r<=ways[j].b*2 && ways[j].b<=ways[j].r*2)
            {
                ans*=ways[j].cost;
                ans%=md;
            }
            //cout<<ways[j].r<<' '<<ways[j].b<<' '<<ways[j].cost<<'\n';
            pair<int,int> f1=get1(1,0,4*n,0,2*ways[j].r-ways[j].b+2*n);
            pair<int,int> f2=get2(1,0,4*n,2*ways[j].b-ways[j].r+2*n+1,4*n);

            //cout<<f1.fir<<' '<<f1.sec<<'\n';
            //cout<<f2.fir<<' '<<f2.sec<<'\n';
            //swap(f1,f2);
            ans*=f1.fir*pow(ways[j].cost,f1.sec)%md;
            ans%=md;
            ans*=pow(f2.fir*pow(ways[j].cost,f2.sec)%md,md-2);
            ans%=md;
            //cout<<ans<<'\n';
        }
        for (int j=0;j<ways.size();j++)
        {
            add1(1,0,4*n,ways[j].b-2*ways[j].r+2*n,ways[j].cost);
            add2(1,0,4*n,ways[j].r-2*ways[j].b+2*n,ways[j].cost);
        }
        //cout<<"!!!!!!!!!!!!!"<<'\n';
    }
    use[u]=1;
    //exit(0);
    for (int i=0;i<vec[u].size();i++)
        solve(vec[u][i].to);

}

signed main()
{
    cin>>n;
    for (int i=1;i<n;i++)
    {
        int u,v,d,t;
        cin>>u>>v>>d>>t;
        vec[u].pb(reb(v,d,t));
        vec[v].pb(reb(u,d,t));
    }

    solve(1);

    cout<<ans;
}