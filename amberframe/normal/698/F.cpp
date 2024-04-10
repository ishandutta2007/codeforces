#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <time.h>

using namespace std;
typedef long long LL;

const int maxn = 1000005;
const int N = 1000000;
const int mod = 1e9+7;

int num[maxn],s2[maxn];
int T,n,a[maxn],c[maxn],s[maxn];
int fac[maxn],to[maxn],fr[maxn];
#define clr(_) memset(_,0,sizeof _)
void solve()
{
	scanf("%d",&n);clr(s);clr(s2);clr(to);clr(fr);s[1]++;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),c[i]=i;
	for (int i=2;i*i<=n;i++) if (c[i]==i)
	for (int j=i;j<=n;j+=i) while (c[j]%i==0) c[j]/=i;
	for (int i=2;i<=n;i++) if (c[i]==i) s[n/i]++;
	for (int i=1;i<=n;i++) s2[num[i]]++;
	for (int i=1;i<=n;i++) 
	if (a[i]) {
		if (num[i/c[i]]!=num[a[i]/c[a[i]]]) {puts("0");return ;}
		int u=c[i],v=c[a[i]],cu=i>1?n/u:1,cv=a[i]>1?n/v:1;s2[num[i]]--;
		if ((i>1&&u==1)&&(a[i]>1&&v==1)) continue;
		if ((i>1&&u==1)^(a[i]>1&&v==1)) {puts("0");return ;}
		if (cu!=cv) {puts("0");return ;}
		if (to[u]&&to[u]!=v) {puts("0");return ;}
		if (fr[v]&&fr[v]!=u) {puts("0");return ;}
		if (!to[u]) to[u]=v,fr[v]=u,s[cu]--;
	}
	int ans=1;
	for (int i=1;i<=n;i++) if (s[i]) ans=(LL)ans*fac[s[i]]%mod;
	for (int i=2;i<=n;i++) if (s2[i]) ans=(LL)ans*fac[s2[i]]%mod;
	printf("%d\n",ans);
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("perm.in","r",stdin);
        freopen("perm.out","w",stdout);
    #endif
    fac[0]=1;for (int i=1;i<=N;i++) fac[i]=(LL)fac[i-1]*i%mod;
    for (int i=1;i<=N;i++) num[i]=1;
    for (int i=2;i<=N;i++) if (num[i]==1)
    for (int j=i;j<=N;j+=i) num[j]*=i;
    solve();//for (scanf("%d",&T);T--;) solve(); 
    return 0;
}