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

struct Node
{
    int zn,l,r,push;

    Node()
    {

    }
};

const int arr=15*1e6;

Node v[arr];

int cnt=1;

void sons(int i)
{
    if (v[i].l==0)
        v[i].l=++cnt;
    if (v[i].r==0)
        v[i].r=++cnt;
}

void make_push(int i)
{
    int pl=v[i].push;
    v[i].push=0;

    v[v[i].l].push+=pl;
    v[v[i].l].zn+=pl;
    v[v[i].r].push+=pl;
    v[v[i].r].zn+=pl;
}

void pluss(int i, int tl, int tr, int l, int r)
{
    if (tl!=tr)
        sons(i);
    if (tl>=l && tr<=r)
    {
        v[i].zn++;
        v[i].push++;
        return;
    }

    if (tr<l || tl>r) return;

    make_push(i);

    int d=(tl+tr)/2;

    pluss(v[i].l,tl,d,l,r);
    pluss(v[i].r,d+1,tr,l,r);
    v[i].zn=min(v[v[i].l].zn,v[v[i].r].zn);
}

int getmin(int i, int tl, int tr,int l, int r)
{
    //cout<<tl<<' '<<tr<<' '<<l<<' '<<r<<'\n';
    if (tl!=tr)
        sons(i);
    if (tl>=l && tr<=r) return(v[i].zn);
    if (tr<l || tl>r) return(1e9);

    make_push(i);

    int d=(tl+tr)/2;
    return(min(getmin(v[i].l,tl,d,l,r),getmin(v[i].r,d+1,tr,l,r)));
}

int l[201000],r[201000];
map<int,int> mp;

signed main()
{
    int n;
    cin>>n;

    for (int i=1;i<=n;i++)
    {
        cin>>l[i]>>r[i];
        mp[l[i]];
        mp[r[i]];
        mp[l[i]-1];
        mp[r[i]+1];
    }

    int c=0;
    for (auto i:mp)
    {
        mp[i.fir]=++c;
    }

    for (int i=1;i<=n;i++)
    {
        pluss(1,0,5e6,mp[l[i]],mp[r[i]]);
    }

    for (int i=1;i<=n;i++)
    {
        //cout<<getmin(1,1,1e9,l[i],r[i])<<'\n';
        if (getmin(1,0,5e6,mp[l[i]],mp[r[i]])!=1)
        {
            cout<<i;
            return(0);
        }
    }
    cout<<-1;
}