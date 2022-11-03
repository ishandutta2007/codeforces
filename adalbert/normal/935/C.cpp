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


ld sqr(ld a)
{
    return(a*a);
}

signed main()
{
    ld r,x1,y1,x2,y2;

    cin>>r>>x1>>y1>>x2>>y2;

    if (sqrt(sqr(x1-x2)+sqr(y1-y2))>r)
    {
        cout<<fixed<<setprecision(9)<<x1<<' '<<y1<<' '<<r;
    } else
    if (x1==x2 && y1==y2)
    {
        cout<<fixed<<setprecision(9)<<x1+r/2.0<<' '<<y1<<' '<<r/2.0<<'\n';
    } else
    {
        ld vx=x1-x2;
        ld vy=y1-y2;
        ld dis=sqrt(sqr(vx)+sqr(vy));
        ld rdis=dis+r;
        vx=vx*rdis/dis;
        vy=vy*rdis/dis;
        ld vvx=x2+vx;
        ld vvy=y2+vy;
        ld x=(vvx+x2)/2.0;
        ld y=(vvy+y2)/2.0;
        cout<<fixed<<setprecision(9)<<x<<' '<<y<<' '<<rdis/2.0;
    }
}