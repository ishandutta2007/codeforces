#include<cstdio>
double dp[202020][52];
int rev[202020][52];
double T[202020];
double normacc[202020];
double invacc[202020];
double racc[202020];
int N, K;
void getdp(int L, int R, int K) // (L, R) excl
{
	if(L+2>R) return;
	int M=(L+R)/2;
//	printf("%d %d %d %d %d \n",L,M, R,rev[L][K],rev[R][K]);	
	//available dprange: [rev[L][K], min(M-1,rev[R][K]) ]  incl
	int mini=0;
	double dpval=1e99;
	for(int i=rev[L][K]; i<M && i<=rev[R][K]; i++)
	{
		//i+1~M incl 
		double ans = dp[i][K-1] + racc[M]-racc[i] - (invacc[M]-invacc[i])*normacc[i];
		if(ans<dpval)
		{
			dpval=ans;
			mini=i;
		}
	}
	rev[M][K]=mini;
	dp[M][K]=dpval;
	getdp(L,M,K);
	getdp(M,R,K);
	return;
}
int main()
{
	scanf("%d%d",&N,&K);
	for(int i=1; i<=N; i++)
	{
		scanf("%lf",T+i);
		normacc[i]=normacc[i-1]+T[i];
		invacc[i]=invacc[i-1]+1/T[i];
		dp[i][1]=racc[i]=racc[i-1]+normacc[i]/T[i];
	}
	
	for(int i=2; i<=K; i++)
	{
		rev[N+1][i]=N;
		getdp(0, N+1, i);
	}
	printf("%.12lf",dp[N][K]);
}