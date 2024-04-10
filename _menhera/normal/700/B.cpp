#include<cstdio>
#include<vector>
using namespace std;
int N, K;
bool Univ[202020];
int sz[202020];
int centr[202020];
vector<int> conn[202020];
void dfsSize(int a, int pa)
{
	sz[a] = Univ[a];
	centr[a] = 0;
	for(const int& x: conn[a])
	{
		if(x==pa) continue;
		dfsSize(x, a);
		sz[a] += sz[x];
		if(centr[a] < sz[x]) centr[a] = sz[x];
	}
	if(centr[a] < K-sz[a]) centr[a] = K-sz[a];
}
long long calcAns(int a, int pa, int de)
{
	long long ans = 0;
	if(Univ[a]) ans += de;
	for(const int& x: conn[a])
	{
		if(x==pa) continue;
		ans += calcAns(x, a, de+1);
	}
	return ans;
}
int main()
{
	scanf("%d%d",&N,&K);
	K *= 2;
	for(int i=0; i<K; i++)
	{
		int t;
		scanf("%d",&t);
		Univ[t] = true;
	}
	
	for(int i=1; i<N; i++)
	{
		int a, b;
		scanf("%d%d",&a,&b);
		conn[a].push_back(b);
		conn[b].push_back(a);
	}
	dfsSize(1, -1);
	int mini = 1;
	for(int i=1; i<=N; i++)
		if(centr[mini]>centr[i])
			mini = i;
	
	printf("%lld",calcAns(mini, -1, 0));
	
}