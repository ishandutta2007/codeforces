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

int x[600],y[600];
int n,m,k;

map<int,vector<pair<int,int> > > mp;

vector<pair<int,int> > remake(map<int,int> now)
{
    vector<int> res1;
    int open=0;
    for (auto i:now)
    {
        if (open==0 && open+i.sec!=0)
            res1.pb(i.fir);
        if (open!=0 && open+i.sec==0)
            res1.pb(i.fir-1);
        open+=i.sec;
    }
    vector<pair<int,int> > res;
    for (int i=0;i<res1.size();i+=2)
        res.pb({res1[i],res1[i+1]});
    return(res);
}

bool check(int d)
{
    mp.clear();
    int mx_x=0, mx_y=0, mn_x=1e9+1, mn_y=1e9+1;
    for (int i=1;i<=k;i++)
    {
        mp[max(int(1),x[i]-d)].pb({max(int(1),y[i]-d),-1});
        mp[max(int(1),x[i]-d)].pb({min(y[i]+d+1,n+1),1});
        mp[min(x[i]+d+1,m+1)].pb({max(y[i]-d,1),1});
        mp[min(x[i]+d+1,m+1)].pb({min(y[i]+d+1,n+1),-1});

    }
    mp[1];
    mp[m+1];
    vector<vector<pair<int,int> > > vec;
    vector<int> pos;

    for (auto i:mp)
    {
        vec.pb(i.sec);
        pos.pb(i.fir);
    }

    map<int,int> now;

    for (int i=0;i<vec.size()-1;i++)
    {
        //cout<<pos[i]<<'\n';
        for (int j=0;j<vec[i].size();j++)
        {
            //cout<<vec[i][j].fir<<' '<<vec[i][j].sec<<'\n';
            now[vec[i][j].fir]-=vec[i][j].sec;
        }

        vector<pair<int,int> > seg=remake(now);
        if (seg.empty())
        {
            mn_x=min(mn_x,pos[i]);
            mx_x=max(mx_x,pos[i+1]-1);
            mx_y=n;
            mn_y=1;
            continue;
        }

        if (seg.size()==1 && seg[0].fir==1 && seg[0].sec==n) continue;

        mn_x=min(mn_x,pos[i]);
        mx_x=max(mx_x,pos[i+1]-1);

        if (seg[0].fir!=1)
            mn_y=1;
        if (seg.size()==1 && seg[0].fir==1)
            mn_y=seg[0].sec+1;
        if (seg.back().sec!=n)
            mx_y=n;
        if (seg.size()==1 && seg.back().sec==n)
            mx_y=seg.back().fir-1;
        for (int j=0;j<seg.size()-1;j++)
        {
            //cout<<seg[j].fir<<' '<<seg[j].sec<<' ';
            mn_y=min(mn_y,seg[j].sec+1);
            mx_y=max(mx_y,seg[j+1].fir-1);
        }
    }
    //cout<<mx_y<<' '<<mn_y<<'\n';
    return(max(mx_y-mn_y+1,mx_x-mn_x+1)<=2*d+1);
}

signed main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++)
        cin>>y[i]>>x[i];
    //check(0);
    //return(0);
    int l=0;
    int r=max(n,m);
    while (r-l>1)
    {
        int d=(l+r)/2;
        if (check(d)) r=d; else l=d;
    }
    if (check(l)) cout<<l; else
        cout<<r;
}