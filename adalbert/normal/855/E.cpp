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

int dp[75][12][3000],dp2[75][12][3000];

void solvedp(int step)
{
    dp[0][step][0]=1;


    for (int i=0;i<70;i++)
        for (int mask=0;mask<(1<<step);mask++)
            for (int now=0;now<step;now++)
                dp[i+1][step][mask^(1<<now)]+=dp[i][step][mask];
}

void solvedp2(int step)
{
    for (int i=1;i<step;i++)
        dp2[1][step][(1<<i)]=1;

    for (int i=1;i<70;i++)
        for (int mask=0;mask<(1<<step);mask++)
            for (int now=0;now<step;now++)
                dp2[i+1][step][mask^(1<<now)]+=dp2[i][step][mask];
}

vector<int> parse(int u, int step)
{
    vector<int> res;

    while (u!=0)
    {
        res.pb(u%step);
        u/=step;
    }
    reverse(res.begin(),res.end());
    return(res);
}

int get(int step, int u)
{
    vector<int> vec=parse(u,step);

    int ans=0;
    int mask=0;


    for (int i=0;i<vec.size();i++)
    {
        for (int now=(i==0);now<vec[i];now++)
        {
            ans+=dp[vec.size()-i-1][step][mask^(1<<now)];
        }
        mask^=(1<<vec[i]);
    }
    for (int len=1;len<vec.size();len++)
        ans+=dp2[len][step][0];

    return(ans);
}

signed main()
{

    for (int i=2;i<=10;i++)
        solvedp(i);
    for (int i=2;i<=10;i++)
        solvedp2(i);

    //return(0);

    int n;
    cin>>n;
    while (n--)
    {
        int step,l,r;
        cin>>step>>l>>r;
        cout<<get(step,r+1)-get(step,l)<<'\n';
    }
}