#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int n,cnt,vis[305];
vector<int>circle[305*305];
inline vector<int> make(int a,int b,int c,int d)
{
	vector<int> vec;vec.clear();
	vec.push_back(a);vec.push_back(b);
	vec.push_back(c);vec.push_back(d);
	return vec;
}
inline vector<int> make(int a,int b,int c)
{
	vector<int> vec;vec.clear();
	vec.push_back(a);vec.push_back(b);vec.push_back(c);
	return vec;
}
inline void work1()
{
	for(int i=1;i<=2;i++)
	{
		++cnt;
		for(int j=1;j<=3;j++)circle[cnt].push_back(j);
	}
	for(int i=5;i<=n;i+=2)
	{
		int u=i-1,v=i;
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=cnt;j++)if(circle[j].size()==3)
		{
			if(circle[j][0]%2==0&&!vis[circle[j][0]]&&circle[j][1]==circle[j][0]+1)
			{
				vis[circle[j][0]]=1;
				circle[++cnt]=make(circle[j][0],u,circle[j][1],circle[j][2]);
				circle[++cnt]=make(circle[j][0],u,circle[j][1],v);
				circle[j][2]=v;
			}
			else if(circle[j][1]%2==0&&!vis[circle[j][1]]&&circle[j][2]==circle[j][1]+1)
			{
				vis[circle[j][1]]=1;
				circle[++cnt]=make(circle[j][1],u,circle[j][2],circle[j][0]);
				circle[++cnt]=make(circle[j][1],u,circle[j][2],v);
				circle[j][0]=v;sort(circle[j].begin(),circle[j].end());
			}
		}
		circle[++cnt]=make(1,u,v);circle[++cnt]=make(1,u,v);
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
	{
		printf("%d",(int)circle[i].size());for(int j=0;j<circle[i].size();j++)printf(" %d",circle[i][j]);
		puts("");
	}
}
inline void work2()
{
	circle[++cnt]=make(1,2,3);
	circle[++cnt]=make(1,2,4);
	circle[++cnt]=make(1,3,4);
	circle[++cnt]=make(2,3,4);
	for(int i=6;i<=n;i+=2)
	{
		int u=i-1,v=i;
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=cnt;j++)if(circle[j].size()==3)
		{
			if(circle[j][0]%2==1&&!vis[circle[j][0]]&&circle[j][1]==circle[j][0]+1&&circle[j][0]<u)
			{
				vis[circle[j][0]]=1;
				circle[++cnt]=make(circle[j][0],u,circle[j][1],circle[j][2]);
				circle[++cnt]=make(circle[j][0],u,circle[j][1],v);
				if(circle[cnt][0]==1)circle[cnt]=make(1,u,v),circle[++cnt]=make(2,u,v);
				circle[j][2]=v;
			}
			else if(circle[j][1]%2==1&&!vis[circle[j][1]]&&circle[j][2]==circle[j][1]+1&&circle[j][1]<u)
			{
				vis[circle[j][1]]=1;
				circle[++cnt]=make(circle[j][1],u,circle[j][2],circle[j][0]);
				circle[++cnt]=make(circle[j][1],u,circle[j][2],v);
				circle[j][0]=v;sort(circle[j].begin(),circle[j].end());
			}
		}
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
	{
		printf("%d",(int)circle[i].size());for(int j=0;j<circle[i].size();j++)printf(" %d",circle[i][j]);
		puts("");
	}
}
int main()
{
	scanf("%d",&n);
	if(n&1)work1();
	else work2();
	return 0;
}