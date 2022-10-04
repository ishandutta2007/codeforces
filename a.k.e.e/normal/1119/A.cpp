#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=300005,MOD=998244353;

int n,c[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int x,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++)
    {
    	if(c[i]!=c[1])ans=max(ans,i-1);
    	if(c[i]!=c[n])ans=max(ans,n-i);
    }
    cout<<ans<<endl;
    return 0;
}