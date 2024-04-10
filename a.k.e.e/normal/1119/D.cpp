#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005,MOD=998244353;

int n;
ll s[MAXN],pre[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int Q;
    ll l,r;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    sort(s+1,s+n+1);
    for(int i=n;i;i--)
    	s[i]-=s[i-1];
    sort(s+2,s+n+1);
    pre[2]=s[2];
    for(int i=3;i<=n;i++)pre[i]=pre[i-1]+s[i];
    cin>>Q;
    while(Q--)
    {
    	cin>>l>>r;
    	int u=lower_bound(s+2,s+n+1,r-l+1)-s;
    	printf("%lld ",(r-l+1)*(n-u+2)+pre[u-1]);
    }
    return 0;
}