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
typedef long double ld;
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

int md=998244353;



int cc[5100][5100],fact[5100];

signed main()
{
    int a,b,c;
    cin>>a>>b>>c;
    cc[0][0]=1;
    for (int i=1;i<=5000;i++)
    {
        cc[i][0]=1;
        for (int j=1;j<=i;j++)
        {
            cc[i][j]=
            cc[i-1][j-1]      +cc[i-1][j];
            cc[i][j]%=md;
        }
    }

    fact[0]=1;
    for (int i=1;i<=5000;i++)
    {
        fact[i]=fact[i-1]*i;
        fact[i]%=md;
    }

    int ans1=0;
    for (int i=0;i<=min(a,b);i++)
    {
        int now=1;
        now*=cc[a][i];
        now%=md;
        now*=cc[b][i];
        now%=md;
        now*=fact[i];
        now%=md;
        ans1+=now;
        ans1%=md;
    }

    int ans2=0;
    for (int i=0;i<=min(c,b);i++)
    {
        int now=1;
        now*=cc[c][i];
        now%=md;
        now*=cc[b][i];
        now%=md;
        now*=fact[i];
        now%=md;
        ans2+=now;
        ans2%=md;
    }
    int ans3=0;
    for (int i=0;i<=min(c,a);i++)
    {
        int now=1;
        now*=cc[c][i];
        now%=md;
        now*=cc[a][i];
        now%=md;
        now*=fact[i];
        now%=md;
        ans3+=now;
        ans3%=md;
    }
    cout<<ans1*ans2%md*ans3%md;
}