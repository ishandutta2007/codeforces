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

const int arr=4e5;

vector<pair<int,int> > vec[arr];
int a[arr];

signed main()
{
    fast;
    int n,m;
    cin>>n>>m;

    while (m--)
    {
        int u,v,c;
        cin>>u>>v>>c;
        vec[u].pb({v,2*c});
        vec[v].pb({u,2*c});
    }

    set<pair<int,int> > setik;

    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        setik.insert({a[i],i});
    }

    while (!setik.empty())
    {
        pair<int,int> now=*setik.begin();
        setik.erase(now);
        int u=now.sec;

        for (auto i:vec[u])
        if (a[i.fir]>a[u]+i.sec)
        {
            setik.erase({a[i.fir],i.fir});
            a[i.fir]=a[u]+i.sec;
            setik.insert({a[i.fir],i.fir});
        }
    }

    for (int i=1;i<=n;i++)
        cout<<a[i]<<' ';

}
/*

*/