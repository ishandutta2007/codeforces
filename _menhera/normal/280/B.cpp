#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 150000
int N;
int val[MAXN];
int left[MAXN];
int right[MAXN];
pair<int,int> hola[MAXN];
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",val+i);
		hola[i]=make_pair(val[i],i);
		left[i]=i-1;
		right[i]=i+1;
	}
	right[N-1]=-1;
	sort(hola,hola+N);
	int ans=0;
	for(int i=0;i<N;i++)
	{
		int v=hola[i].second;
		if(left[v]!=-1) ans=max(ans,val[left[v]]^val[v]);
		if(right[v]!=-1) ans=max(ans,val[right[v]]^val[v]);
		if(left[v]!=-1) right[left[v]] = right[v];
		if(right[v]!=-1) left[right[v]] = left[v];
	}
	printf("%d",ans);
	return 0;
}