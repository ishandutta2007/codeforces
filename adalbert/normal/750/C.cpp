#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define int ll
#define y1 humiuyn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
int d[300000],c[300000];
///-----------------------------------------------------------------------///
signed main()
{
    fast;
    ll n;
    cin>>n;
    int p2=0;
    for (int i=1;i<=n;i++)
    {
        cin>>c[i]>>d[i];
        if (d[i]==2 && p2==0) p2=i;
    }
    if (p2==0)
    {
        cout<<"Infinity";
        return(0);
    }
    int mx=1e15;
    int mn=-1e15;
    for (int i=1;i<=n;i++)
    {
        if (mn>mx)
        {
            cout<<"Impossible";
            return(0);
        }
        if (d[i]==1 && mx<1899)
        {
            cout<<"Impossible";
            return(0);
        }
        if (d[i]==2 && mn>1899)
        {
            cout<<"Impossible";
            return(0);
        }
        if (d[i]==1)
            mn=max(mn,(ll)1900);
        if (d[i]==2)
            mx=min(mx,(ll)1899);
        mn+=c[i];
        mx+=c[i];
    }
    if (mn>mx)
        {
            cout<<"Impossible";
            return(0);
        }
   cout<<mx;
}