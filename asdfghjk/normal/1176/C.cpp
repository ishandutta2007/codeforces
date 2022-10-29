#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,i,a[500005],num[100],ans;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		if(a[i]==4)
			++num[4];
		else if(a[i]==8)
		{
			if(num[4]>0)
				--num[4],++num[8];
			else
				++ans;
		}
		else if(a[i]==15)
		{
			if(num[8]>0)
				--num[8],++num[15];
			else
				++ans;
		}
		else if(a[i]==16)
		{
			if(num[15]>0)
				--num[15],++num[16];
			else
				++ans;
		}
		else if(a[i]==23)
		{
			if(num[16]>0)
				--num[16],++num[23];
			else
				++ans;
		}
		else
		{
			if(num[23]>0)
				--num[23],++num[46];
			else
				++ans;
		}
	}
	ans+=num[4]+num[8]*2+num[15]*3+num[16]*4+num[23]*5;
	printf("%d",ans);
	return 0;
}