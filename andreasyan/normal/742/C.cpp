#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ban
{
	int x, d;
};
queue<int> q;
long long n, m, a[103],ans=1;
vector<int> g[103];
int bfs(int x)
{
	int i, j;
	int k = 0;
	int h;
	int sx=x;
	bool z=true;
	q.push(x);
	while (!q.empty())
	{
		x = q.front();
		q.pop();
		if (x==sx && !z)
			return k;
		z=false;
		for (i = 0; i < g[x].size(); i++)
		{
			h = g[x][i];
			k++;
			q.push(h);
		}
	}
}
long long gcd(long long x,long long y)
{
	if(x==0)
		return y;
	else
		return gcd(y%x,x);
}
int scd(long long x,long long y)
{
	return (x*y)/gcd(x,y);
}
int main()
{
	int i, j;
	long long x, k, ygcd=1,sum=1;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> x;
		g[i].push_back(x);
	}
	for(i=1;i<=n;i++)
	{
		a[g[i][0]]++;
		if(a[g[i][0]]==2)
		{
			cout<<"-1"<<endl;
			return 0;
		}
	}
	for(i=1;i<=n;i++)
	{
		x=bfs(i);
		if(x%2==0)
			ans=scd(ans,x/2);
		else
			ans=scd(ans,x);
	}
	cout << ans << endl;
	return 0;
}