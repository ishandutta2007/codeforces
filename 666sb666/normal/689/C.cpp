#include<cstdio>
long long m,pw[200001],tot,i;
int main()
{
	scanf("%lld",&m);
	for(i=1;i*i*i<=8*m;i++)pw[i]=(i+1)*(i+1)*(i+1);
	pw[i]=(i+1)*(i+1)*(i+1);
	long long l=0,r=m*8,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		tot=0;
		for(int i=1;pw[i]<=mid;i++)tot+=mid/pw[i];
		if(l==r)break;
		if(tot<m)l=mid+1;
		else r=mid;
	}
	if(tot==m)printf("%lld\n",mid);
	else printf("-1\n");
	return 0;
}