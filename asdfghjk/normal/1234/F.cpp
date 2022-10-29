#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int i,j,w,mx[2200005],ans;
char s[1000005];
int main()
{
	scanf("%s",s+1);
	for(i=1;s[i];++i)
	{
		w=0;
		for(j=i;s[j]&&!(w>>(s[j]-'a')&1);++j)
		{
			w|=1<<(s[j]-'a');
			mx[w]=max(mx[w],j-i+1);
		}
	}
	for(i=0;i<20;++i)
		for(j=0;j<(1<<20);++j)
			if(j>>i&1)
				mx[j]=max(mx[j],mx[j^(1<<i)]);
	for(i=0;i<(1<<20);++i)
		ans=max(ans,mx[i]+mx[((1<<20)-1)^i]);
	printf("%d",ans);
	return 0;
}