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

int x[200000],y[200000];

signed main()
{
    int n;
    cin>>n;
    string st;
    cin>>st;

    int now1=1;
    int now2=1;

    x[0]=0;
    y[0]=0;

    for (int i=1;i<=st.size();i++)
        if (st[i-1]=='U')
    {
        x[i]=x[i-1]+1;
        y[i]=y[i-1];
    } else
    {
        x[i]=x[i-1];
        y[i]=y[i-1]+1;
    }

    int res=0;
    for (int i=1;i+2<=st.size();i++)
    {
        if (x[i]>y[i] && x[i+2]<y[i+2])
            res++;
        if (x[i]<y[i] && x[i+2]>y[i+2])
            res++;
    }

    cout<<res;
}