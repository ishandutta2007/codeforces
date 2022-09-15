#include<cstdio>
#include<vector>
using namespace std;
int N;
vector<int> conn[101010];
double ans;
void dfs(int a,int pa,int h)
{
	ans+=1./h;
	for(int v:conn[a])
	{
		if(v==pa) continue;
		dfs(v,a,h+1);
	}
}
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N-1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		conn[a-1].push_back(b-1);
		conn[b-1].push_back(a-1);
	}
	dfs(0,-1,1);
	printf("%.12lf",ans);
	return 0;
}