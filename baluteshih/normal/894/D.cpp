#include <iostream>
#include <vector>
#include <algorithm> 
#define __ ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

vector<long long> deg[1000050],sum[1000050];
long long N,M,arr[1000050];

void get_sum(long long n)
{
	long long i;
	sum[n].resize(deg[n].size()+1);
	for(sum[n][0]=0,i=0;i<deg[n].size();i++)
		sum[n][i+1]=sum[n][i]+deg[n][i];
}

void dfs(long long n)
{
	deg[n].push_back(0);
	if(n*2>N) 
	{
		get_sum(n);
		return;
	}
	if(n*2==N)
	{
		dfs(N),deg[n].push_back(arr[N]),get_sum(n);
		return;
	} 
	long long a,b;
	dfs(n*2),dfs(n*2+1);
	for(a=0,b=0;a<deg[n*2].size() || b<deg[n*2+1].size();)
	{
		if(a<deg[n*2].size() && b<deg[n*2+1].size())
		{
			if(deg[n*2][a]+arr[n*2]<deg[n*2+1][b]+arr[n*2+1]) deg[n].push_back(deg[n*2][a++]+arr[n*2]);
			else deg[n].push_back(deg[n*2+1][b++]+arr[n*2+1]);
		}
		else
		{
			while(a<deg[n*2].size()) deg[n].push_back(deg[n*2][a++]+arr[n*2]);
			while(b<deg[n*2+1].size()) deg[n].push_back(deg[n*2+1][b++]+arr[n*2+1]);
		}
	}
	get_sum(n);
}

long long query(long long x,long long h)
{
	long long re=upper_bound(deg[x].begin(),deg[x].end(),h)-deg[x].begin();
	return h*re-sum[x][re];
}

int main()
{__
	long long i,x,h,ans;
	cin >> N >> M;
	for(i=2;i<=N;i++)
		cin >> arr[i];
	dfs(1);
	while(M--)
	{
		cin >> x >> h;
		ans=query(x,h);
		h-=arr[x];
		while(h>0 && x/2)
		{
			ans+=query(x/2,h);
			ans-=query(x,h-arr[x]);
			x/=2,h-=arr[x];
		}
		cout << ans << "\n";
	}
}