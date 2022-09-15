#include<stdio.h>
int N, M;
char arri[20][101010];
int arr[101010][20];
int pcalc[101010];
int pcalc2[101010];
const int Kval=13;
int min(int a, int b)
{
	if(a<b) return a;
	else return b;
}
int main()
{
	scanf("%d%d\n",&N,&M);
	for(int i=0; i<N; i++)
		fgets(arri[i], sizeof(arri[i]), stdin);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			arr[j][i] = arri[i][j] - '0';
	int K = min(N, Kval);
	int ansv = 1e9;
	for(int j=0; j<M; j++)
		for(int k=0; k<N-K; k++)
			if(arr[j][K+k]) pcalc[j] |= 1<<k; 
	for(int j=0; j<M; j++)
		for(int k=0; k<K; k++)
			if(arr[j][k]) pcalc2[j] |= 1<<k;
	for(int i=0; i<(1<<K); i++)
	{
		int tarr[Kval+1][1<<(20-Kval)];
		memset(tarr, 0, sizeof(tarr));
		for(int j=0; j<M; j++)
			tarr[__builtin_popcount(pcalc2[j]^i)][pcalc[j]]++;
		for(int j=0; j< 1<<(N-K); j++)
		{
			int ans = 0;
			
			for(int k=0; k< 1<<(N-K); k++)
			{
				int tot = __builtin_popcount(j^k);
				for(int s=0; s<=K; s++)
				{
					ans += min(N-tot, tot) * tarr[s][k];
					++tot;
				}
			}
			ansv = min(ans, ansv);
		}
	}
	printf("%d\n",ansv);
	
}