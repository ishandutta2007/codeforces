#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 110000;
pair<int, pair<int, int> > point[MAXN];
pair<int, int> pivot1, pivot2;
long long area2(pair<int, int> p1, pair<int, int>p2, pair<int, int>p3)
{
	return abs((1LL*p1.first * p2.second + 1LL*p2.first*p3.second + 1LL*p3.first * p1.second) - (1LL * p1.second * p2.first + 1LL*p2.second*p3.first + 1LL* p3.second * p1.first));
}
bool cmp(pair<int, pair<int, int> > x, pair<int, pair<int, int> > y)
{
	return area2(pivot1, pivot2, x.second) < area2(pivot1, pivot2, y.second);
}
bool cmp2(pair<int, pair<int, int> > x, pair<int, pair<int, int> > y)
{
	return x.second < y.second;
}
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		point[i].first = i+1;
		scanf("%d%d",&point[i].second.first,&point[i].second.second);
	}
	sort(point,point+N,cmp2);
	pivot1=point[0].second;
	pivot2=point[1].second;
	sort(point+2, point+N, cmp);
	for(int i=2; i<N; i++)
	{
		if(area2(pivot1, pivot2, point[i].second)!=0LL)
		{
			printf("%d %d %d",point[0].first, point[1].first, point[i].first);
			return 0;
		}
	}
}