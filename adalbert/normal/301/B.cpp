#include <bits/stdc++.h>
using namespace std;
#define sec second
#define fir first
#define pb push_back
#define mp make_pair
typedef long double ld;
typedef int ll;
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
///------------------------------------------------------------///
ll use[10000],x[10000],y[1000],n,d,a[10000];
///------------------------------------------------------------///
void dfs(ll u, ll cost, vector <ll> vec)
{
    use[u]=cost;
    vec[u-1]=1;
    for (int i=1;i<=n;i++)
        if ((abs(x[u]-x[i])+abs(y[u]-y[i]))*d-a[i]+cost<=use[i] && vec[i-1]==0)
        {
            vec[i-1]=1;
            dfs(i,(abs(x[u]-x[i])+abs(y[u]-y[i]))*d-a[i]+cost,vec);
            vec[i-1]=0;
        }
}
///------------------------------------------------------------///
int main()
{
    cin>>n>>d;
    for (int i=2;i<=n-1;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    vector <ll> vec;
    for (int i=1;i<=n;i++)
        vec.pb(0);
    for (int i=1;i<=n;i++)
        use[i]=1e10;
    dfs(1,0,vec);
    cout<<max(0,use[n]);
}