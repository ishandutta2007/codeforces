
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
#define files(name) freopen(name".sol","r",stdin); freopen (name".dat","w",stdout);
#define time pdojegoritg

#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define int ll

typedef long long ll;
typedef long double ld;
const int arr=4*1e5;
const int md=1e9+7;

int n,m,k,q;

struct point
{
    int x,y,time;
};

const bool operator <(const point &i, const point &j)
{
    return(i.time<j.time);
}

int sum[1000][1000];

point a[500*500+10];

bool check(int u)
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            sum[i][j]=0;

    for (int i=1;i<=u;i++)
        sum[a[i].x][a[i].y]=1;

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+sum[i][j];

    for (int i=k;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (sum[i][j]-sum[i-k][j]-sum[i][j-k]+sum[i-k][j-k]==k*k) return(1);
    return(0);
}

signed main()
{
    cin>>n>>m>>k>>q;
    for (int i=1;i<=q;i++)
    {
        cin>>a[i].x>>a[i].y>>a[i].time;
    }

    sort(a+1,a+1+q);

    int l=1;
    int r=q;
    if (!check(r))
    {
        cout<<-1;
        return(0);
    }

    while (r-l>1)
    {
        int d=(l+r)/2;
        if (check(d)) r=d; else
            l=d;
    }

    if (check(l)) cout<<a[l].time; else
        cout<<a[r].time;
}