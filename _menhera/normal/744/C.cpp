#include<bits/stdc++.h>
using namespace std;
int N;
int dp[1<<16][200]; //state, red discount @ max blue discount 
int type[16];
int red[16];
int blue[16];
int lg[1<<16];
int allred;
int allblue;
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0; i<N; i++)
	{
		lg[1<<i] = i;
		char c;
		scanf(" %c%d%d", &c, red+i, blue+i);
		if(c=='R') type[i]=0;
		else type[i] = 1;
		allred += red[i];
		allblue += blue[i];
	}
	for(int i=0; i<(1<<N); i++)
		for(int j=0; j<200; j++)
			dp[i][j] = -2e8;
	dp[0][0] = 0;
	for(int i=1; i<(1<<N); i++)
	{
		int cnt[2]={0, 0};
		for(int j=0; j<N; j++)
			if(i&(1<<j))
				cnt[type[j]]++;
		for(int j=0; j<N; j++)
			if(i&(1<<j))
			{
				cnt[type[j]]--;
				int rd = min(cnt[0], red[j]);
				int bd = min(cnt[1], blue[j]);
				for(int k=0;k+rd<200; k++)
					dp[i][k+rd] = max(dp[i][k+rd], dp[i-(1<<j)][k]+bd);
				cnt[type[j]]++;
			}
	}
	int ans = 1e9;
	for(int i=0;i<200; i++)
	{
		ans = min ( ans, max(allred-i, allblue-dp[(1<<N)-1][i])+N ) ;
	}
	printf("%d\n",ans);
}