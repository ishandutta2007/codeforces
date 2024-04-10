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
int type[200000],color[1000];
signed main()
{
    int n;
    cin>>n;
    int mx=1;
    for (int i=2;i<=n+1;i++)
    {
        if (type[i]!=0) continue;
        type[i]=1;
        for (int j=i*2;j<=n+1;j+=i)
        {
            type[j]=2;
            mx=2;
        }

    }
    cout<<mx<<'\n';
    for (int i=2;i<=n+1;i++)
        cout<<type[i]<<' ';
}