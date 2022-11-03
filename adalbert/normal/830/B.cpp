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
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define time pdojegoritg
#define int ll
typedef long long ll;
typedef long double ld;
const int arr=4*1e5;
const int md=1e9+7;
int n;
int now=1;
int ans=0;
int a[arr];
set<int> pos[arr];

int v[4*arr];

int getsum(int i, int tl, int tr, int l, int r)
{
    if (tl>=l && tr<=r) return(v[i]);
    if (tl>r || tr<l) return(0);
    int d=(tl+tr)/2;
    return(getsum(i*2,tl,d,l,r)+getsum(i*2+1,d+1,tr,l,r));
}

void change(int i, int tl, int tr, int x, int y)
{
    if (tl==tr)
    {
        v[i]=y;
        return;
    }
    int d=(tl+tr)/2;
    if (x<=d) change(i*2,tl,d,x,y); else
        change(i*2+1,d+1,tr,x,y);
    v[i]=v[i*2]+v[i*2+1];
}

void get(int u)
{
    int last=*(pos[u].lower_bound(now));

    if (last>n)
    {
        ans+=getsum(1,1,n,now,n);
        ans+=getsum(1,1,n,1,last-n);
        change(1,1,n,last-n,0);
        pos[u].erase(last);
        pos[u].erase(last-n);
        now=last+1;
    } else
    {
        ans+=getsum(1,1,n,now,last);
        change(1,1,n,last,0);
        pos[u].erase(last);
        pos[u].erase(last+n);
        now=last+1;
    }
    while(now>n)
        now-=n;
}

signed main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
    {
        change(1,1,n,i,1);
        pos[a[i]].insert(i);
        pos[a[i]].insert(i+n);
    }

    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++)
    {
        get(a[i]);
    }

    cout<<ans;
}