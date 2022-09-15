#include<cstdio>
#include<cstring>
#define MOD 1000000007
int DP[1001]; //color, balls
int K;
int C[1001];
int S[1001];
int comb[2010][2010];
int bktk(int c)
{
	if(c==0) return 1;
	if(DP[c]!=-1) return DP[c];
	int res=0;
	res=comb[S[c-1]+C[c]-1][C[c]-1];
	res=(1LL*res*bktk(c-1))%MOD;
	return DP[c]=res;
}	
int main()
{
	for(int i=0;i<=2005;i++)
	{
		comb[i][i]=comb[i][0]=1;
		for(int j=1;j<i;j++)
			comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%MOD;
	}
	memset(DP,-1,sizeof(DP));
	scanf("%d",&K);
	for(int i=0;i<K;i++)
	{
		scanf("%d",C+i);
		if(i!=0) S[i]=S[i-1];
		S[i]+=C[i];
	}
	printf("%d\n",bktk(K-1));
}