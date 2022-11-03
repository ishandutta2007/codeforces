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
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define vi vector<int>
#define endl "\n"

#define next odtjgodirhg

int n,m,k;

int a[2000][2000],len[2000][2000];

signed main()
{
    fast;
    cin>>n>>m>>k;

    for (int i=1;i<=n;i++)
    {
        string st;
        cin>>st;
        for (int j=1;j<=m;j++)
            a[i][j]=(st[j-1]=='#');
    }

    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        len[i][j]=1e9;
    len[x1][y1]=0;

    queue<pair<int,int> > q;
    q.push({x1,y1});

    while (!q.empty())
    {
        if (len[x2][y2]!=1e9) break;
        pair<int,int> u=q.front();
        q.pop();
        int i=u.fir;
        int j=u.sec;

        for (int p=1;p<=k;p++)
        {

            if (i+p>n) break; //if (len[i+p][j]==len[i][j]+1) continue;
            if (a[p+i][j]) break;
            if (len[p+i][j]==len[i][j]) break;

            if (len[i+p][j]==1e9)
            q.push({i+p,j});

            len[p+i][j]=min(len[p+i][j],len[i][j]+1);
        }
        for (int p=1;p<=k;p++)
        {

            if (j+p>m) break;//if (len[i][j+p]==len[i][j]+1) continue;
            if (a[i][j+p]) break;
            if (len[i][j+p]==len[i][j]) break;

            if (len[i][j+p]==1e9)
            q.push({i,j+p});

            len[i][j+p]=min(len[i][j+p],len[i][j]+1);

        }

        for (int p=1;p<=k;p++)
        {


            if (i-p==0) break;//if (len[i-p][j]==len[i][j]+1) continue;
            if (a[i-p][j]) break;
            if (len[i-p][j]==len[i][j]) break;

            if (len[i-p][j]==1e9)
            q.push({i-p,j});
            len[i-p][j]=min(len[i-p][j],len[i][j]+1);
        }
        for (int p=1;p<=k;p++)
        {


            if (j-p==0) break;//if (len[i][j-p]==len[i][j]+1) continue;
            if (a[i][j-p]) break;
            if (len[i][j-p]==len[i][j]) break;

            if (len[i][j-p]==1e9)
            q.push({i,j-p});
            len[i][j-p]=min(len[i][j-p],len[i][j]+1);
        }
    }

    if (len[x2][y2]==1e9)
        cout<<-1; else
        cout<<len[x2][y2];
}