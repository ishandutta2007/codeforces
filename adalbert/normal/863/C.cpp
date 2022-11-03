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

typedef long long ll;

#define int ll

pair<int,int> cost[100][100];
int last[100][100],a[5][5],b[5][5];

bool geta(int l, int r)
{
    return((l==1 && r==3) || (l==2 && r==1) || (l==3 && r==2));
}
bool getb(int l, int r)
{
    swap(l,r);
    return((l==1 && r==3) || (l==2 && r==1) || (l==3 && r==2));
}

pair<int,int> solve(int a1, int b1, int k)
{
    int c1=0;
    int c2=0;
    while(k--)
    {
        c1+=geta(a1,b1);
        c2+=getb(a1,b1);
        int aa1=a[a1][b1];
        int bb1=b[a1][b1];
        a1=aa1;
        b1=bb1;
    }
    return(make_pair(c1,c2));
}

signed main()
{
    int k,a1,b1;
    cin>>k>>a1>>b1;



    for (int i=1;i<=3;i++)
        for (int j=1;j<=3;j++)
        cin>>a[i][j];

    for (int i=1;i<=3;i++)
        for (int j=1;j<=3;j++)
        cin>>b[i][j];
if (k<100)
    {
        cout<<(solve(a1,b1,k)).fir<<' '<<(solve(a1,b1,k)).sec<<'\n';
        return(0);
    }
    int now=1;
    int c1=0,c2=0;
    while (!last[a1][b1])
    {
        c1+=geta(a1,b1);
        c2+=getb(a1,b1);
        cost[a1][b1]={c1,c2};
        last[a1][b1]=now;
        now++;
        int aa1=a[a1][b1];
        int bb1=b[a1][b1];
        a1=aa1;
        b1=bb1;
    }

    k-=last[a1][b1];
    int ans1=cost[a1][b1].fir;
    int ans2=cost[a1][b1].sec;

    c1+=geta(a1,b1);
    c2+=getb(a1,b1);
    c1-=ans1;
    c2-=ans2;

    ans1+=k/(now-last[a1][b1])*c1;
    ans2+=k/(now-last[a1][b1])*c2;

    k%=(now-last[a1][b1]);

    int aa1=a[a1][b1];
    int bb1=b[a1][b1];
    a1=aa1;
    b1=bb1;
    ans1+=(solve(a1,b1,k)).fir;
    ans2+=(solve(a1,b1,k)).sec;
    cout<<ans1<<' '<<ans2;
}