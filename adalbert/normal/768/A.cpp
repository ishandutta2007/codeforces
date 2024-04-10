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
int a[200000];
signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int mn=a[1];
    int mx=a[1];
    for (int i=1;i<=n;i++)
    {
        mn=min(mn,a[i]);
        mx=max(mx,a[i]);
    }
    int ans=0;
    for (int i=1;i<=n;i++)
        if (a[i]>mn && a[i]<mx) ans++;
    cout<<ans;
}