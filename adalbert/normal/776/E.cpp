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
int md=1e9+7;
int phi (int n)
{
	int result = n;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}
signed main()
{
    int n,k;
    cin>>n>>k;
    k=(k+1)/2;
    int ans=n;
    for (int i=1;i<=k;i++)
    {
        ans=phi(ans);
        if (ans==1) break;
    }
    cout<<ans%md;
}