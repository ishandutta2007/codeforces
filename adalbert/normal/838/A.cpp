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
const int md=1e9+7;

int pref[2600][2600];
int n,m;

int solve(int u)
{
    int res=0;
    for (int i=0;i<n;i+=u)
        for (int j=0;j<m;j+=u)
        {
            int l1=i;
            int l2=j;
            int r1=min(n,i+u);
            int r2=min(m,j+u);
            //cout<<l1<<' '<<l2<<' '<<r1<<' '<<r2<<'\n';
            int now=pref[r1][r2]-pref[r1][l2]-pref[l1][r2]+pref[l1][l2];
            res+=min(now,u*u-now);
        }
    //cout<<u<<' '<<res<<'\n';
    //exit(0);
    return(res);
}

signed main()
{
    cin>>n>>m;

    for (int i=1;i<=n;i++)
    {
        string st;
        cin>>st;
        for (int j=0;j<st.size();j++)
            pref[i][j+1]=st[j]-'0';
    }

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+pref[i][j];

    int ans=1e9;

    for (int k=2;k<=max(n,m);k++)
        ans=min(ans,solve(k));

    cout<<ans<<'\n';
}