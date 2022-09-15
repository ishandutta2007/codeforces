#include<cstdio>
#include<vector>
#include<unordered_set>
using namespace std;
int N,M;
unordered_set<int> conn[200200];
int indeg[200200];
int s[500500];
int e[500500];
int sz=0;
vector<pair<int,int> > S; 
bool used[500500];
void dfs(int a)
{
	unordered_set<int>::iterator it;
	for(;!conn[a].empty();it=conn[a].begin())
	{
		it=conn[a].begin();
		int V=*it;
		conn[a].erase(it);
		if(used[V])continue;
		used[V]=true;
		int dest=s[V]+e[V]-a;
		dfs(dest);
		S.push_back(make_pair(dest,a));
		if(conn[a].empty()) return;
	}
	return;
}
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		s[sz]=a;
		e[sz]=b;
		conn[a].insert(sz);
		conn[b].insert(sz);
		sz++;
		indeg[a]++;
		indeg[b]++;
	}
	int tg=-1;
	for(int i=0;i<N;i++)
		if(indeg[i]%2==1)
		{
			if(tg==-1) tg=i;
			else
			{
				s[sz]=tg;
				e[sz]=i;
				conn[tg].insert(sz);
				conn[i].insert(sz);
				sz++;
				indeg[tg]++;
				indeg[i]++;
				tg=-1;
			}
		}
	dfs(0);
	if(sz%2==1)
	{
		printf("%d\n",sz+1);
		puts("1 1");
	}
	else
		printf("%d\n",sz);
	for(int i=0;i<S.size();i++)
	{
		if(i%2)
			printf("%d %d\n",S[i].first+1,S[i].second+1);
		else
			printf("%d %d\n",S[i].second+1,S[i].first+1);
	}
	return 0;
}