
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

int a[arr],b[arr],f[arr];
vector<pair<int,int> > vec[arr];

void dfs(int u)
{
    f[u]=b[u]-a[u];
    for (int i=0;i<vec[u].size();i++)
    {
        dfs(vec[u][i].fir);
        if (f[vec[u][i].fir]<0)
        {
            int pl=f[vec[u][i].fir]*vec[u][i].sec;
            if (pl/vec[u][i].sec!=f[vec[u][i].fir])
            {
                cout<<"NO";
                exit(0);
            }

            if (f[u]<0)
            if (max(log10(ld(abs(f[u]))),log10(ld(abs(pl))))>17.0)
            {
                cout<<"NO";
                exit(0);
            }

            f[u]=f[u]+pl;


        } else
        {
            f[u]+=f[vec[u][i].fir];
        }

    }
}

signed main()
{

    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>b[i];
    for (int i=1;i<=n;i++)
        cin>>a[i];

    for (int i=2;i<=n;i++)
    {
        int x,k;
        cin>>x>>k;
        vec[x].pb({i,k});
    }

    dfs(1);

    if (f[1]<0) cout<<"NO"; else
        cout<<"YES";
}