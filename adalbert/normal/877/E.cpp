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

int v[1600000],push[1600000];

int in[300000],out[300000];

vector<int> vec[300000];
int cnt;

void dfs(int u)
{
    in[u]=++cnt;
    for (auto to:vec[u])
        if (!in[to])
        dfs(to);
    out[u]=cnt;
}

void make_push(int i, int l, int r)
{
    if (!push[i])
        return;
    push[i]=0;
    push[i*2]=!push[i*2];
    push[i*2+1]=!push[i*2+1];

    int d=(l+r)/2;
    v[i*2]=(d-l+1)-v[i*2];
    v[i*2+1]=(r-d)-v[i*2+1];
}

void rev(int i, int tl, int tr, int l, int r)
{
    if (tl>=l && tr<=r)
    {
        v[i]=(tr-tl+1)-v[i];
        push[i]=!push[i];
        return;
    }
    if (tl>r || tr<l) return;

    make_push(i,tl,tr);

    int d=(tl+tr)/2;
    rev(i*2,tl,d,l,r);
    rev(i*2+1,d+1,tr,l,r);

    v[i]=v[i*2]+v[i*2+1];
}

int get(int i, int tl, int tr, int l, int r)
{
    if (tl>=l && tr<=r)
    {
        return(v[i]);
    }
    if (tl>r || tr<l) return(0);

    make_push(i,tl,tr);

    int d=(tl+tr)/2;
    return(get(i*2,tl,d,l,r)+get(i*2+1,d+1,tr,l,r));

}

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<n;i++)
    {
        int p;
        cin>>p;
        vec[p].pb(i+1);
    }

    dfs(1);

    for (int i=1;i<=n;i++)
    {
        int p;
        cin>>p;
        if (p==1)
            rev(1,1,n,in[i],in[i]);
    }

    int q;
    cin>>q;
    while (q--)
    {
        string s;
        cin>>s;
        if (s=="get")
        {
            int a;
            cin>>a;
            cout<<get(1,1,n,in[a],out[a])<<'\n';
        } else
        {
            int p;
            cin>>p;
            rev(1,1,n,in[p],out[p]);
        }
    }
}