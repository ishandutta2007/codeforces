#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int A[101010];
int cnt[101010];
int ans[101010];
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0; i<N; i++)
	{
		scanf("%d",A+i);
		A[i] --;
	}
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++) cnt[j] = 0;
		priority_queue<pair<int, int>,vector<pair<int, int> > > Q;
		
		for(int j=i; j<N; j++)
		{	//[i, j] incl
			cnt[A[j]]++;
			Q.push(make_pair(cnt[A[j]],-A[j]));
			//printf("%d %d\n",cnt[A[j]],A[j]);
			while(!Q.empty())
			{
				pair<int, int> tmp = Q.top();
				if(cnt[-tmp.second]!=tmp.first) Q.pop();
				else break;
			}
			//printf("%d %d",Q.top().first,Q.top().second);
			ans[-Q.top().second]++;
		}
	}
	for(int i=0; i<N; i++) printf("%d ",ans[i]);
}