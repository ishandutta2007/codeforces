#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;
int N,M;
long long l[202020],r[202020];
vector<pair< long long,int> > V;
int ans[202020];
vector<pair<pair<long long, long long>,int> > inter;
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
		scanf("%lld%lld",l+i,r+i);
	for(int i=1;i<=M;i++)
	{
		long long int t;
		scanf("%lld",&t);
		V.push_back(make_pair(t,i));
	}
	sort(V.begin(),V.end());
	for(int i=0;i<N-1;i++)
		inter.push_back(make_pair(make_pair(l[i+1]-r[i],r[i+1]-l[i]),i));
	sort(inter.begin(),inter.end());
	priority_queue<pair<long long int, int> > PQ;
	int ptr=0,cnt=0;
	for(int i=0;i<M;i++)
	{
		while(ptr<N-1 && inter[ptr].first.first<=V[i].first)
			PQ.push(make_pair(-inter[ptr].first.second,inter[ptr].second)),ptr++;
		if(PQ.empty()) continue;
		long long v=-PQ.top().first;
		if(V[i].first<=v)
		{
			ans[PQ.top().second]=V[i].second;
			PQ.pop();
			cnt++;
		}
	}
	if(!PQ.empty() || cnt!=N-1)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i=0;i<N-1;i++)
		printf("%d ",ans[i]);
	return 0;
}