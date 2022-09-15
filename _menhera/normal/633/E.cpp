#include<cstdio>
#include<deque>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN = 1000010;
int N, K;
int v[MAXN];
int c[MAXN];
int ans[MAXN];
deque<int> maxQ, minQ;
	
void ins(int i)
{
	while(!maxQ.empty())
	{
		if(v[maxQ.back()]<=v[i]) maxQ.pop_back();
		else break;
	}
	maxQ.push_back(i);
	
	while(!minQ.empty())
	{
		if(c[minQ.back()]>=c[i]) minQ.pop_back();
		else break;
	}
	minQ.push_back(i);
	
}
int main()
{
	scanf("%d%d",&N,&K);
	for(int i=0; i<N; i++)
	{
		scanf("%d",v+i);
		v[i]*=100;
	}
	for(int i=0;i<N;i++)
		scanf("%d",c+i);
	
	int ptr = -1; //pushed until here
	for(int i=0; i<N; i++)
	{
		if(ptr<i)
			ins(++ptr);
		if(maxQ.front()==i-1) maxQ.pop_front();
		if(minQ.front()==i-1) minQ.pop_front();
		ans[i]=min(v[maxQ.front()],c[minQ.front()]);
		
		while(max(v[maxQ.front()],v[ptr+1])<min(c[minQ.front()],c[ptr+1]))
		{
			ins(++ptr);
			ans[i]=max(ans[i],min(v[maxQ.front()],c[minQ.front()]));
		}
		ans[i]=max(ans[i],min(max(v[maxQ.front()],v[ptr+1]),min(c[minQ.front()],c[ptr+1])));
	//	printf("%d ",ans[i]);
	}
	sort(ans, ans+N);
	double aans = 0;
	double comb = (double)K/N;
	for(int i=0; i<=N-K; i++)
	{
		aans += comb*ans[i];
		comb *= N-K-i;
		comb /= N-i-1;
	}
	printf("%.12lf",aans);
}