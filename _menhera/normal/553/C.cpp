#include<cstdio>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<set>
#define MOD 1000000007
using namespace std;
int N,M;
int ufd[100100];
int Find(int a)
{
	if(ufd[a]==a) return a;
	else return ufd[a]=Find(ufd[a]);
}
void Union(int a,int b)
{
	ufd[Find(a)]=Find(b);
}
vector<pair<int, int> > love,hate;
set<int> conn[100100];
bool isdeg[100100];
int color[100100];
void setcolor(int a,int c)
{
	if(color[a]+c==3 && color[a]!=c)
	{
		puts("0");
		exit(0);
		return;
	}
	if(color[a]==c) return;
	color[a]=c;
	for(set<int>::iterator it=conn[a].begin();it!=conn[a].end();it++)
		setcolor(*it,3-c);
}
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++) ufd[i]=i;
	for(int i=0;i<M;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a--; b--;
		if(c==0) hate.push_back(make_pair(a,b));
		else love.push_back(make_pair(a,b));		
	}
	for(int i=0;i<love.size();i++)
		Union(love[i].first,love[i].second);
	for(int i=0;i<N;i++) isdeg[Find(i)]=true;
	for(int i=0;i<hate.size();i++)
	{
		int a=Find(hate[i].first),b=Find(hate[i].second);
		if(Find(a)==Find(b))
		{
			puts("0");
			return 0;
		}
		conn[a].insert(b);
		conn[b].insert(a);
	}
	int ans=(MOD+1)/2;
	for(int i=0;i<N;i++)
	{
		//printf("%d %d\n",isdeg[i],color[i]);
		if(!isdeg[i]) continue;
		if(color[i]) continue;
		ans*=2;
		ans%=MOD;
		setcolor(i,1);
	}
	printf("%d",ans);
}