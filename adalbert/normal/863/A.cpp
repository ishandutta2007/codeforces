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

string st;

bool palin(int l,int r)
{
    for (int i=l;i<=r;i++)
        if (st[i]!=st[r-(i-l)]) return(0);
    return(1);
}

bool null(int l, int r)
{
    for (int i=l;i<=r;i++)
        if (st[i]!='0') return(0);
    return(1);
}

signed main()
{
    cin>>st;
    for (int i=0;i<st.size();i++)
        if (palin(0,i) && null(i+1,st.size()-1))
        {
            //cout<<i<<'\n';
            cout<<"YES"<<'\n';
            return(0);
        }
    cout<<"NO";
}