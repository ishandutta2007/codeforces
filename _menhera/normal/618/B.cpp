#include<cstdio>
const int MAXN = 60;
int arr[MAXN][MAXN];
int ans[MAXN];
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			scanf("%d",&arr[i][j]);
			if(ans[i]<arr[i][j]) ans[i]=arr[i][j];
		}
	for(int i=0;i<N;i++)
	{
		if(ans[i]==N-1)
		{
			ans[i]=N;
			break;
		}
	}
	for(int i=0;i<N;i++)
		printf("%d ",ans[i]);
}