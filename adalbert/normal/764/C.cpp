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
bool ch;
int cnt[200000], s[200000],  f[200000],c[200000];
signed main()
{
    fast;
    int n;
    cin>>n;
    for (int i=1;i<n;i++)
    {
        cin>>s[i]>>f[i];
    }
    for (int i=1;i<=n;i++)
        cin>>c[i];
    for (int i=1;i<n;i++)
    {
        if (c[s[i]]!=c[f[i]]) cnt[s[i]]++,cnt[f[i]]++;
    }
    int mx=0;
    int imx=1;
    for (int i=1;i<=n;i++)
        if (cnt[i]>mx)
    {
        mx=cnt[i];
        imx=i;
    }
    for (int i=1;i<n;i++)
    {
        if (c[s[i]]!=c[f[i]] && s[i]!=imx && f[i]!=imx) ch=1;
    }
    if (ch) cout<<"NO"; else
    {
        cout<<"YES"<<'\n';
        cout<<imx;
    }
}