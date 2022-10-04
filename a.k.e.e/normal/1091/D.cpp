#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=1000005,MOD=998244353;

int n;
ll ans;

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>n;
    int fac=1;
    for(int i=n;i>0;i--)
    {
    	ans+=fac-1;
    	fac=(ll)fac*i%MOD;
    }
    ans=((ll)n*fac-n+1-ans)%MOD;
    if(ans<0)ans+=MOD;
    cout<<ans<<endl;
	return 0;
}