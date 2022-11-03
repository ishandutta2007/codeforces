#include<bits/stdc++.h>
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
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int arr=2e5;

int ok[100];

int cnt[2000];
int rs[10000][100];
int pow_(int u, int step)
{
    if (rs[u][step]!=0)
        return(rs[u][step]);
    int res=1;
    for (int i=1;i<=step;i++)
    {
        int pres=res;
        res*=u;
        if (res/u!=pres)
        {
            rs[u][step]=2e18;
            return(2e18);
        }
    }
    rs[u][step]=res;
    return(res);
}

int get(int u)
{
    if (u==0)
        return(0);
    int res=0;

    int l=sqrt(u);
    while ((l+1)*(l+1)<=u)
        l++;
    res+=l;

    l=0;
    int r=1e6+1;

    while (r-l>1)
    {
        int d=(l+r)/2;
        if (d*d*d<=u)
            l=d; else r=d;
    }
    res+=l;
    res--;

    return(res);
}


vector<pair<int,int> > vec[100];
int ans[200000];
signed main()
{

    fast;
    int q;
    cin>>q;

    for (int i=2;i<=64;i++)
    {
        int now=i;
        vector<int> vec;
        bool ch=0;
        for (int j=2;j<=now;j++)
        {
            int cnt=0;
            while (now%j==0)
            {
                now/=j;
                cnt++;
            }
            if (cnt!=0)
            {
                vec.pb(j);
                if (cnt!=1)
                    ch=1;
            }
        }
        if (!ch)
        {
            if (vec.size()%2)
                ok[i]=1; else
                ok[i]=-1;
        }

    }


    for (int li=1;li<=q;li++)
    {
        int l,r;
        cin>>l>>r;
        l--;
        ans[li]=get(r)-get(l);

        vec[1].pb({l,-li});
        vec[1].pb({r,li});
    }

    sort(vec[1].begin(),vec[1].end());

    for (int i=4;i<=64;i++)
        if (ok[i]!=0)
        {
            int now=1;
            int nxt=pow_(now+1,i);
            for (auto j:vec[1])
            {
                while (nxt<=j.fir)
                {
                    now++;
                    nxt=pow_(now+1,i);
                }
                if (j.sec<0)
                    ans[-j.sec]-=ok[i]*(now-1); else
                    ans[j.sec]+=ok[i]*(now-1);
            }
        }

    for (int i=1;i<=q;i++)
        cout<<ans[i]<<'\n';
}
/*
1
1000000000000000
1000000000000000
*/