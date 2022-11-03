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
typedef long long  ll;
typedef double ld;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define int ll

int v[200000],t[200000],cnt[200000],ans[200000];

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>v[i];
    for (int i=1;i<=n;i++)
        cin>>t[i];

    for (int i=1;i<=n;i++)
        t[i]+=t[i-1];

    for (int i=1;i<=n;i++)
    {
        int l=i-1;
        int r=n;

        while (r-l>1)
        {
            int d=(l+r)/2;
            if (t[d]-t[i-1]<=v[i])
                l=d; else r=d;
        }

        if (t[r]-t[i-1]<=v[i])
            l=r;
        cnt[i]++;
        cnt[l+1]--;
        ans[l+1]+=v[i]-t[l]+t[i-1];
    }

    for (int i=1;i<=n;i++)
        cnt[i]+=cnt[i-1];

    for (int i=1;i<=n;i++)
        cout<<ans[i]+cnt[i]*(t[i]-t[i-1])<<' ';
}