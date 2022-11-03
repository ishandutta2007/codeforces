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
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int arr=1600;
const int md=1e9+7;

set<int> good;
map<int,set<int> > setik;
void add(int u, int pos)
{
    setik[u].insert(pos);
    if (setik[u].size()==2)
        good.insert(u);
}

vector<pair<int,int> > vec;

void dell(int u)
{
    /*cout<<setik[u].size()<<'\n';
    if (setik[u].size()<2)
        exit(1);
    */int fir=*setik[u].begin();
    setik[u].erase(fir);
    int sec=*setik[u].begin();
    setik[u].erase(sec);
    if (setik[u].size()<2)
        good.erase(u);
    add(2*u,sec);
}

int a[300000];

signed main()
{
    fast;
    int n;
    cin>>n;

    map<int,int> mp;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        add(a[i],i);
    }

    while (!good.empty())
    {
        int now=*good.begin();
        dell(now);
    }

    for (auto i:setik)
    {
        for (auto j:i.sec)
            vec.pb({j,i.fir});
    }
    cout<<vec.size()<<'\n';
    sort(vec.begin(),vec.end());
    for (auto i:vec)
        cout<<i.sec<<' ';
}