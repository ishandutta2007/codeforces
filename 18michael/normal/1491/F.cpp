#include<bits/stdc++.h>
using namespace std;
int n,ans,l,r,mid,Test_num;
bool u[2002];
inline void solve()
{
	scanf("%d",&n),ans=n;
	for(int i=1;i<=n;++i)u[i]=0;
	for(int i=2,x;i<=n;++i)
	{
		printf("? 1 %d\n%d\n",i-1,i);
		for(int j=1;j<i;++j)printf("%d%c",j,j+1==i? '\n':' ');
		fflush(stdout),scanf("%d",&x);
		if(x)
		{
			u[i]=1,--ans;
			for(int j=i+1;j<=n;++j)printf("? 1 1\n%d\n%d\n",i,j),fflush(stdout),scanf("%d",&x),ans-=(u[j]=x);
			for(l=1,r=i-1;l<r;)
			{
				mid=((l+r)>>1),printf("? 1 %d\n%d\n",mid-l+1,i);
				for(int j=l;j<=mid;++j)printf("%d%c",j,j==mid? '\n':' ');
				fflush(stdout),scanf("%d",&x);
				if(x)r=mid;else l=mid+1;
			}
			u[l]=1,--ans;
			break;
		}
	}
	printf("! %d",ans);
	for(int i=1;i<=n;++i)if(!u[i])printf(" %d",i);
	puts(""),fflush(stdout);
}
int main()
{
	for(scanf("%d",&Test_num);Test_num--;)solve();
	return 0;
}