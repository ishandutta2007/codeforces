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
#define int ll

int start,pl;
int n,m,a,d;

int mult(int a, int b)
{
    if (log2(a)+log2(b)>63)
        return(3e18); else
        return(a*b);
}

int get(int a, int y, int x)
{
    int l=0;
    int r=3e9;
    while (r-l>1)
    {
        int d=(l+r)/2;

        if (y+mult(d,x)>a) r=d; else l=d;
    }

    if (y+mult(l,x)>a) return(l); else return(r);
}

int get2(int a, int y, int x)
{
    int l=0;
    int r=3e9;
    while (r-l>1)
    {
        int d=(l+r)/2;

        if (y+mult(d,x)<=a) l=d; else r=d;
    }

    if (y+mult(l,x)<=a) return(l); else return(r);
}

pair<int,int> get(int s, int t)
{
    int fo=0;
    fo=get(s,0,a);
    fo*=a;
    //cout<<fo<<'\n';
    int eo=fo;
    eo=get(fo+d,0,a);
    eo*=a;
    //cout<<eo<<'\n';
    int pl=eo-fo;

    if (fo/a>n || fo>t)
        return(m_p(1,t));
    int res=1;
    int last=fo;

    int l=0;
    int r=3e9;
    while (r-l>1)
    {
        int d=(l+r)/2;
        if (last+mult(d,pl)<=t && (last+mult(d,pl)-1)<n*a)
            l=d; else
            r=d;
    }

    if (last+mult(r,pl)<=t && (last+mult(r,pl)-1)<n*a)
        last+=mult(r,pl),res+=r; else
        last+=mult(l,pl),res+=l;


    if (last+d>=t)
    {
        return(m_p(res,last));
    } else
    return(m_p(res+1,t));
}

int t[400000];

signed main()
{

    cin>>n>>m>>a>>d;
    start=-d;

    for (int i=1;i<=m;i++)
        cin>>t[i];
    sort(t+1,t+1+m);
    t[m+1]=3e18;
    m++;
    int ans=0;
    for (int i=1;i<=m;i++)
        if(t[i]>start+d)
        {
            pair<int,int> now=get(start+d,t[i]);
            start=now.sec;
            ans+=now.fir;
        }

    cout<<ans-1<<'\n';
}