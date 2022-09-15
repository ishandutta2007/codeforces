#include<cstdio>
#include<cstring>
#include<vector>
long long fact[21];
char str[51][33];
int N,M;
long long AV[1048576];
int cnt[1048576];
int dkr[20];
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%s",str[i]);
	M=strlen(str[0]);
	fact[0]=1LL;
	for(int i=1;i<=M;i++) fact[i]=i*fact[i-1];
	double ans=0;
	if(N==1)
	{
		puts("0");
		return 0;
	}
	for(int j=1;j<(1<<M);j++)
	{
		int k=j;
		while(k)
		{
			k-=k&(-k);
			cnt[j]++;
		}
	}
	long long t=0;
	for(int i=0;i<N;i++)
	{

		AV[0]=(1LL<<N)-1;
		for(int x=0;x<M;x++)
		{
			AV[1<<x]=0;
			for(int k=0;k<N;k++)
				if(str[i][x]==str[k][x]) AV[1<<x]|=1LL<<k;
		}
		for(int j=1;j<(1<<M);j++)
		{
			int lb=j&(-j);
			if(j!=lb) AV[j]=AV[j-lb]&AV[lb];
			if(AV[j]==(1LL<<i))
				t+=fact[cnt[j]]*fact[M-cnt[j]];
			if(t>=fact[M])
			{
				ans+=1;
				t-=fact[M];
			}				
		}
	}
	ans+=(double)t/fact[M];
	printf("%.12lf",M+1-ans/N);
	return 0;
}