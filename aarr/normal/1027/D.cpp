#include <iostream>

using namespace std;

int s = 0;
int c[200005];
int a[200005];
int cycle[200005];
int mark[200005];
void dfs(int i, int j)
{
	if(mark[j] == 0)
	{
		mark[j] = i;
		dfs(i, a[j]);
		return ;
	}	
	if(mark[j] == i)
	{
		int mini = 100005;
		while(cycle[j] == 0)
		{
			cycle[j] = i;
			mini = min(mini, c[j]);
			j = a[j];
		}
		s += mini;
		return ;
	}
	mark[j] = i;
}
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> c[i];
	}
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i ++)
	{
		if(mark[i] == 0)
		{
			dfs(i, i);
		}
	}
	cout << s;
	return 0;
}