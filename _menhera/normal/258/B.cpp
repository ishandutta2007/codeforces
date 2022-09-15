#include<cstdio>
#define MOD 1000000007
int N;
int count[10];
int countf(int X,int inc)
{
	if(X==0)
	{
		count[inc]++;
		return 0;
	}
	int Xten=X;
	int digit=0;
	int digitx=1;
	while(Xten>=10)
	{
		Xten/=10;
		digit++;
		digitx*=10;
	}
	for(int i=0;i<Xten;i++)
	{
		int tinc=0;
		if(i==4 || i==7) tinc++;
		for(int j=0;j<=digit;j++)
		{
			long long res=1;
			for(int i=j+1;i<=digit;i++)
				res*=i;
			for(int i=1;i<=digit-j;i++)
				res/=i;
			for(int k=0;k<j;k++)
				res*=2;
			for(int k=j;k<digit;k++)
				res*=8;
			count[j+inc+tinc]+=res;
		}
	}
	if(Xten==4 || Xten==7) countf(X-Xten*digitx,inc+1);
	else countf(X-Xten*digitx,inc);
	return 0;
}
long long bktk(int cnt,int depth)
{
	long long res=0LL;
	if(depth==6)
	{
		//for(int i=0;i<10;i++) printf("%d ",count[i]);
		//puts("");
		for(int i=cnt+1;i<10;i++)
		{
			res+=count[i];
			res%=MOD;
		}
		return res;
		//do ans
	}
	for(int i=0;i<10;i++)
	{
		if(count[i]==0) continue;
		count[i]--;
		res+=1LL*(count[i]+1)*bktk(cnt+i,depth+1);
		res%=MOD;
		count[i]++;
	}
	return res;
}
int main()
{
	scanf("%d",&N);
	count[0]--;
	countf(N,0);
	for(int i=0;i<10;i++) fprintf(stderr,"%d ",count[i]);
	printf("%I64d",bktk(0,0));
}