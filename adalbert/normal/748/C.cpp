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
///-----------------------------------------------------------------------///
signed main()
{
    int n;
    cin>>n;
    string st;
    cin>>st;
    int h=0,v=0,ans=0;
    for (int i=0;i<n;i++)
        if (st[i]=='L')
        {
            if (h==2)
            {
                ans++;
                v=0;
            }
            h=1;
        } else
        if (st[i]=='R')
        {
            if (h==1)
            {
                v=0;
                ans++;
            }
            h=2;
        } else
        if (st[i]=='U')
        {
            if (v==2)
            {
                ans++;
                h=0;
            }
            v=1;
        } else
        if (st[i]=='D')
        {
            if (v==1)
            {
                ans++;
                h=0;
            }
            v=2;
        }
    ans++;
    cout<<ans;
}