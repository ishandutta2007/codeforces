#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,i,j,cnt,ans[100005];
int main()
{
	//freopen("c.in","r",stdin);
	//freopen("c.out","w",stdout);
	scanf("%d",&n);
	for(i=2;i<=n;++i)
		if(!ans[i])
		{
			++cnt;
			for(j=i;j<=n;j+=i)
				if(!ans[j])
					ans[j]=cnt;
		}
	for(i=2;i<=n;++i)
		printf("%d ",ans[i]);
	return 0;
}