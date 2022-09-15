#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<pair<int,int> > V;
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		V.emplace_back(x,y);
	}
	sort(V.begin(),V.end());
	int ind=upper_bound(V.begin(),V.end(),make_pair(0,0))-V.begin();//[0,ind)
	if(N-ind==ind)
	{
		int ans=0;
		for(int i=0;i<N;i++) ans+=V[i].second;
		printf("%d",ans);
		return 0;
	}
	if(ind<N-ind)
	{
		int ans=0;
		for(int i=0;i<2*ind+1;i++) ans+=V[i].second;
		printf("%d",ans);
		return 0;
	}
	if(ind>N-ind)
	{
		int ans=0;
		for(int i=N-2*(N-ind)-1;i<N;i++) ans+=V[i].second;
		printf("%d",ans);
		return 0;
	}
}