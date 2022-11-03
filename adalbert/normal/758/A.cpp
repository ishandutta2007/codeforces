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
int a[10000];
signed main()
{
    int n;
    cin>>n;
    int mx=0,ans=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    for  (int i=1;i<=n;i++)
    {
        ans+=mx-a[i];
    }
    cout<<ans;
}