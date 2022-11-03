#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define y1 humiuyn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
ld dp[9000][1010];
signed main()
{
    int k,q;
    cin>>k>>q;
    dp[0][0]=1;
    for (int i=1;i<=8000;i++)
        for (int j=0;j<=k;j++)
        {
            dp[i][j]=dp[i-1][j]*(ld(j)/ld(k))+dp[i-1][j-1]*(ld(k-j+1)/ld(k));
        }
    while (q--)
    {
        ld n;
        cin>>n;
        n/=2000;
        int now=0;
        while (dp[now][k]<n) now++;
        cout<<now<<'\n';
    }

}