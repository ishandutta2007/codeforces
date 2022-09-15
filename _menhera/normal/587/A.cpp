#include<cstdio>
const int MAXN = 1010100;
int N;
int count[1010101];
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int t;
		scanf("%d",&t);
		count[t]++;
	}
	int ans = 0;
	for(int i=0;i<MAXN;i++)
	{
		count[i+1] += count[i]/2;
		count[i] %= 2;
		ans += count[i];
	}
	
	printf("%d",ans);
	return 0;
	
}