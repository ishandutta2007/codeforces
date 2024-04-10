#include<cstdio>
int N;
char str[110][110];
int arr[110][110];
bool vis[110];
int cnt[110];
int ok()
{
	for(int i=0;i<N;i++) if(!cnt[i]) return i;
	return -1;
}
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%s",&str[i]);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			arr[i][j]=str[i][j]-'0';
	for(int i=0;i<N;i++) scanf("%d",cnt+i);
	int ans=0;
	while(true)
	{
		int v=ok();
		if(v==-1) break;
		vis[v]=true;
		for(int i=0;i<N;i++)
			cnt[i]-=arr[v][i];
		ans++;
	}
	printf("%d\n",ans);
	for(int i=0;i<N;i++) if(vis[i]) printf("%d ",i+1);
	return 0;
}