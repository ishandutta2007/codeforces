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

int x[arr],y[arr],s[arr];
int pref[210][210][12];

signed main()
{
    int n,q,c;
    cin>>n>>q>>c;
    for (int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i]>>s[i];
    }
    for (int t=0;t<=c;t++)
    {
        for (int i=1;i<=n;i++)
            pref[x[i]][y[i]][t]+=(s[i]+t)%(c+1);
        for (int i=1;i<=200;i++)
            for (int j=1;j<=200;j++)
                pref[i][j][t]=pref[i-1][j][t]+pref[i][j-1][t]-pref[i-1][j-1][t]+pref[i][j][t];
    }

    while (q--)
    {
        int t,x1,y1,x2,y2;
        cin>>t>>x1>>y1>>x2>>y2;
        t%=(c+1);
        if (x1>x2)
            swap(x1,x2);
        if (y1>y2)
            swap(y1,y2);
        x1--;
        y1--;
        cout<<pref[x2][y2][t]-pref[x1][y2][t]-pref[x2][y1][t]+pref[x1][y1][t]<<'\n';
    }
}