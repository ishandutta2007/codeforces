#include<cstdio>
#include<bitset>
using namespace std;
bitset<300000001> vec(3);
int cnt,pri[17000001],ans;
int s(int r,int m)
{
	for(register int i=3;i<=m;i+=2)
	{
		if(!vec[i])
		{
		pri[++cnt]=i;
		if(i>=r&&!(i&2))
		ans++;
		}
		for(register int j=1;j<=cnt&&pri[j]*i<=m;j++)
		{
			vec[pri[j]*i]=1;
			if(i%pri[j]==0)
			break;
		}
	}
}
int main()
{
	int l,r;
	scanf("%d%d",&l,&r);
	s(l,r);
	if(l<=2&&r>=2)
	ans++;
	printf("%d",ans);
}
//how to  mle