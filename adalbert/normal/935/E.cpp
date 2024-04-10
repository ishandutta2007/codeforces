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
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ll

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int md=1e9+7;

string st;
int p,m;

int nxt[100000];

int sum[100000];

vector<pair<int,int> > solvep(int l, int r)
{
    vector<pair<int,int> > res;
    if (l==r)
    {
        res.pb({st[l]-'0',st[l]-'0'});
        return(res);
    }

    vector<pair<int,int> > vec1=solvep(l+1,nxt[l]-1);
    vector<pair<int,int> > vec2=solvep(nxt[l]+1,r-1);
    for (int i=0;i<=min(ll(vec1.size()-1+vec2.size()-1+1),p);i++)
        res.pb({-1e9,1e9});

    for (int i=0;i<vec1.size();i++)
        for (int j=0;j<vec2.size();j++)
            if (i+j+1<=p)
            {
                res[i+j+1].fir=max(res[i+j+1].fir,vec1[i].fir+vec2[j].fir);
                res[i+j+1].sec=min(res[i+j+1].sec,vec1[i].sec+vec2[j].sec);
            }
    for (int i=0;i<vec1.size();i++)
        for (int j=0;j<vec2.size();j++)
            if (i+j<=p)
            {
                res[i+j].fir=max(res[i+j].fir,vec1[i].fir-vec2[j].sec);
                res[i+j].sec=min(res[i+j].sec,vec1[i].sec-vec2[j].fir);
            }


    return(res);
}

vector<pair<int,int> > solvem(int l, int r)
{
    vector<pair<int,int> > res;
    if (l==r)
    {
        res.pb({st[l]-'0',st[l]-'0'});
        return(res);
    }

    vector<pair<int,int> > vec1=solvem(l+1,nxt[l]-1);
    vector<pair<int,int> > vec2=solvem(nxt[l]+1,r-1);
    for (int i=0;i<=min(ll(vec1.size()-1+vec2.size()-1+1),m);i++)
        res.pb({-1e9,1e9});

    for (int i=0;i<vec1.size();i++)
        for (int j=0;j<vec2.size();j++)
            if (i+j+1<=m)
            {
                res[i+j+1].fir=max(res[i+j+1].fir,vec1[i].fir-vec2[j].sec);
                res[i+j+1].sec=min(res[i+j+1].sec,vec1[i].sec-vec2[j].fir);
            }
    for (int i=0;i<vec1.size();i++)
        for (int j=0;j<vec2.size();j++)
            if (i+j<=m)
            {
                res[i+j].fir=max(res[i+j].fir,vec1[i].fir+vec2[j].fir);
                res[i+j].sec=min(res[i+j].sec,vec1[i].sec+vec2[j].sec);
            }


    return(res);
}

signed main()
{
    cin>>st;
    cin>>p>>m;

    vector<int> vec;

    for (int i=0;i<st.size();i++)
        if (st[i]=='(')
            vec.pb(i); else
        if (st[i]==')')
            vec.pop_back(); else
        if (st[i]=='?')
            nxt[vec.back()]=i;

    vector<pair<int,int> > ans;
    if (p<m)
        ans=solvep(0,ll(st.size())-1); else
        ans=solvem(0,ll(st.size())-1);

    if (p<m)
    cout<<ans[p].fir<<'\n'; else
    cout<<ans[m].fir;
}
/*
*/