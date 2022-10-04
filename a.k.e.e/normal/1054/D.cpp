#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
const int MAXN=200005;

int n,k,a[MAXN];
ll calc(ll x)
	{return x*(x-1)/2;}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]^=a[i-1];
	}
	for(int i=1;i<=n;i++)
		if(a[i]>=(1<<(k-1)))
			a[i]^=((1<<k)-1);
	sort(a+1,a+n+1);
	ll cnt=1,ans=(ll)n*(n+1)/2;
	for(int i=1;i<=n;i++)
		if(a[i]==a[i-1])++cnt;
		else
		{
			ans-=calc(cnt/2)+calc(cnt-cnt/2);
			cnt=1;
		}
	ans-=calc(cnt/2)+calc(cnt-cnt/2);
	cout<<ans<<endl;
	return 0;
}