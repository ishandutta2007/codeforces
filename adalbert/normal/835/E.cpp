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
typedef long long ll;
typedef long double ld;
const int arr=4*1e5;

int n,x,y;
int cnt=19;
map<vector<int>, bool> mp;

bool good(vector<int> vec)
{
    if (mp.count(vec)) return(mp[vec]);
    if (vec.size()==0)
        return(0);
    cnt--;
    if (cnt==-1) exit(1);
    cout<<'?'<<' '<<vec.size();
    for (int i=0;i<vec.size();i++)
        cout<<' '<<vec[i];
    cout<<'\n';
    fflush(stdout);
    int res;
    cin>>res;
    mp[vec]=(res==y || res==(x^y));
    return(res==y || res==(x^y));
}

bool get(int u, int i)
{
    return((u&(1<<i))!=0);
}

signed main()
{
    cin>>n>>x>>y;
    int last=0;
    int mask=0;
    for (int i=0;i<=9;i++)
    {
        vector<int> vec;
        for (int j=1;j<=n;j++)
            if (get(j,i)) vec.pb(j);
        if (good(vec))
        {
            //cout<<i<<'!'<<'\n';
            last=i;
            mask+=(1<<i);
        }
    }

    vector<int> vec1,vec2;
    for (int i=1;i<=n;i++)
        if (get(i,last) && (i^mask)<=n) vec1.pb(i); else
        if ((i^mask)<=n) vec2.pb(i);

    vector<int> vec;
    if (vec1.size()<vec2.size()) vec=vec1; else vec=vec2;

    int l=0;
    int r=vec.size()-1;
    while (r-l>1)
    {
        int d=(l+r)/2;
        vector<int> now;
        for (int i=0;i<=d;i++)
            now.pb(vec[i]);
        if (good(now)) r=d; else l=d;
    }

    int d=l;
    vector<int> now;
    for (int i=0;i<=d;i++)
        now.pb(vec[i]);
    if (!good(now)) l++;

    cout<<'!'<<' '<<min(vec[l],vec[l]^mask)<<' '<<max(vec[l],vec[l]^mask)<<'\n';
    fflush(stdout);
}