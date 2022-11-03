#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define int ll
#define y1 humiuyn
#define fir first
#define sec second
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
int cnt[101000],a[101000];
///-----------------------------------------------------------------------///
signed main()
{
    int n;
    cin>>n;
    bool ch=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        for (int j=1;j*j<a[i];j++)
            if (a[i]%j==0)
        {
            cnt[j]++;
            cnt[a[i]/j]++;
        }
        if ((int)(sqrt(a[i]))*(int)(sqrt(a[i]))==a[i] ) cnt[(int)sqrt(a[i])]++;
    }
    int ans=0;
    for (int i=2;i<=1e5;i++)
        ans=max(ans,cnt[i]);
    cout<<max(ans,(int)1);
}