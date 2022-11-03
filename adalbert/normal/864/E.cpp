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
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define time pdojegoritg
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")

#define int ll

struct Node
{
    int pos,t,d,cost;
};

const bool operator < (const Node &i, const Node &j)
{
    return(i.d<j.d);
}

Node a[500];

int pred[110][2100],dp[110][2100];

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].t>>a[i].d>>a[i].cost;
        a[i].pos=i;
    }

    sort(a+1,a+1+n);

    for (int i=1;i<=n;i++)
        for (int time=0;time<=2010;time++)
        {
            if (time+a[i].t<a[i].d)
            {
                if (dp[i-1][time]+a[i].cost>dp[i][time+a[i].t])
                {
                    dp[i][time+a[i].t]=dp[i-1][time]+a[i].cost;
                    pred[i][time+a[i].t]=1;
                }
            }

            if (dp[i-1][time]>dp[i][time])
            {
                dp[i][time]=dp[i-1][time];
                pred[i][time]=0;
            }
        }



    int mx=-1;
    int imx=0;

    for (int i=0;i<=2000+10;i++)
        if (dp[n][i]>mx)
        {
            mx=dp[n][i];
            imx=i;
        }

    cout<<mx<<'\n';

    int now=imx;

    vector<int> vec;
    for (int i=n;i>=1;i--)
    {
        if (pred[i][now]==1)
        {
            vec.pb(a[i].pos);
            now-=a[i].t;
        }
    }

    reverse(vec.begin(),vec.end());

    cout<<vec.size()<<'\n';
    for (int i=0;i<vec.size();i++)
        cout<<vec[i]<<' ';
}

/*
3
3 7 4
3 7 6
2 6 5

*/