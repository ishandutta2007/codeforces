#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=300005,MOD=998244353;

int n,a[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    ll ans=0,cur=0;
    cin>>n;--n;
    for(int i=0;i<=n;i++)cin>>a[i];
    for(int i=0;i<=n;i++)
    {
    	if(a[i]>=cur*2)ans+=cur,a[i]-=cur*2,cur=0;
    	else ans+=a[i]/2,cur-=a[i]/2,a[i]%=2;
    	ans+=a[i]/3;a[i]%=3;
    	cur+=a[i];
    }
    cout<<ans<<endl;
    return 0;
}