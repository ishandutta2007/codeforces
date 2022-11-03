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
    int n,k;
    cin>>n>>k;
    int t=240;
    t-=k;
    int i=0;
    while (t-5*(i+1)>=0 && i+1<=n)
    {
        t-=5*(i+1);
        i++;
    }
    cout<<i;
}