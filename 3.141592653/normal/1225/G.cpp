#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
#include<bitset>
typedef std::bitset<2002>bps;
int n,k;
int a[111];
bps dp[1<<16|15];
void adjust(bps&R)
{for(register int i=2000/k;i;i--)R[i]=R[i]|R[i*k];}
int dep[111];
#include<vector>
std::vector<int>var[111111];
int R(int x,int y)
{int V=x+y;for(;V%k==0;V/=k);return V;}
int P(int x,int y)
{int V=x+y,T=0;for(;V%k==0;V/=k,T++);return T;}
void tri(int d)
{
	register int i,ii;
	int Mx=0,My=1,cs=P(var[d][0],var[d][1]),tp;
	for(i=0;i<(int)var[d].size();i++)
		for(ii=i+1;ii<(int)var[d].size();ii++)
			if((tp=P(var[d][i],var[d][ii]))<cs)
				Mx=i,My=ii,cs=tp;
	printf("%d %d\n",var[d][Mx],var[d][My]);
	int G=R(var[d][Mx],var[d][My]);
	var[d].erase(var[d].begin()+My),
	var[d].erase(var[d].begin()+Mx),
	var[d-cs].push_back(G);
}
void calcp()
{
	int pos=(1<<n)-1,Dx=1,L=0;
	register int i;
	for(;pos;)
	{
		while(Dx*k<=2000&&dp[pos][Dx*k])Dx*=k,L++;
		for(i=0;i<n;i++)
			if(pos&(1<<i))
				if(a[i]<=Dx&&dp[pos^(1<<i)][Dx-a[i]])
					dep[i]=L,Dx-=a[i],pos^=(1<<i),
					var[dep[i]].push_back(a[i]);
	}for(i=100;i;i--)
		for(;var[i].size()>1;)tri(i);
}
int main()
{
	scanf("%d%d",&n,&k);
	register int i,ii;
	for(i=0;i<n;i++)scanf("%d",a+i);
	dp[0][0]=1;
	for(i=1;i<(1<<n);adjust(dp[i]),i++)
		for(ii=0;ii<n;ii++)
			if((1<<ii)&i)
				dp[i]|=dp[(1<<ii)^i]<<a[ii];
	if(!dp[(1<<n)-1][1])return puts("NO"),0;
	puts("YES"),calcp();
}
/*
Please don't let me down.
*/