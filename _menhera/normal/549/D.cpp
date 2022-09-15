#include<cstdio>
char str[101][101];
int map[100][100];
int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
		scanf("%s",str[i]);
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(str[i][j]=='W') map[i][j]++;
			else map[i][j]--;
	int cnt=0;
	for(int i=N-1;i>=0;i--)
		for(int j=M-1;j>=0;j--)
		{
			if(map[i][j]!=0)
			{
				for(int s=0;s<=i;s++)
					for(int t=0;t<=j;t++)
						map[s][t]-=map[i][j];
				cnt++;
			}
		}
	printf("%d",cnt);
	
}