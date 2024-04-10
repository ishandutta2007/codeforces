#include<cstdio>
#define MAXN 53
using namespace std;
char board[MAXN][MAXN+1];
char ans[MAXN*2][MAXN*2];
char newboard[MAXN][MAXN+1];
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%s",board[i]);
	for(int i=-(N-1);i<=N-1;i++)
		for(int j=-(N-1);j<=N-1;j++)
			ans[i+N][j+N]='x';
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			for(int k=0;k<N;k++)
				for(int s=0;s<N;s++)
					if(board[i][j]=='o' && board[k][s]=='.') ans[k-i+N][s-j+N]='.';
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(board[i][j]=='o') newboard[i][j]='o';
			else newboard[i][j]='.';
		}
	}
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(board[i][j]=='o')
				for(int k=0;k<N;k++)
					for(int s=0;s<N;s++)
					{
						if(newboard[k][s]!='.') continue;
						if(ans[k-i+N][s-j+N]=='x')
							newboard[k][s]='x';
					}
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(board[i][j]!=newboard[i][j])
			{
				puts("NO");
				return 0;
			}
	ans[N][N]='o';
	puts("YES");
	for(int i=-(N-1);i<=N-1;i++,puts(""))
		for(int j=-(N-1);j<=N-1;j++)
			putchar(ans[i+N][j+N]);
	return 0;
}