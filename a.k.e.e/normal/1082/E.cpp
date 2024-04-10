#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
const int MAXN=500005;

int n,m,a[MAXN],d[MAXN],last[MAXN],cnt[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==m)cnt[i]=cnt[i-1]+1;
		else cnt[i]=cnt[i-1];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		d[i]=max(d[last[a[i]]]+1,cnt[i-1]+1);
		ans=max(ans,d[i]+cnt[n]-cnt[i]);
		last[a[i]]=i;
	}
	cout<<ans<<endl;
	return 0;
}