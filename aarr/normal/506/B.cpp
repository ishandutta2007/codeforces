#include <iostream>

#include <vector>

using namespace std;

vector<int> in[100005];
vector<int> out[100005];
int part[100005];
int mark[100005];
int nparts = 1;
int cycpart[100005];
void dfs(int v)
{
	part[v] = nparts;
	//cout << v << " " << (int) out[v].size() << endl;
	for(int i = 0; i < out[v].size(); i ++)
	{
		if(part[out[v][i]] == 0)
		{
			dfs(out[v][i]);
		}
	}
	for(int i = 0;i < in[v].size(); i ++)
	{
		if(part[in[v][i]] == 0)
		{
			dfs(in[v][i]);
		}
	}
}
void Dfs(int v)
{
	//cout << v << " " << mark[v] << " " << (int) out[v].size() << endl;
	if(mark[v] == 1)
	{
		cycpart[part[v]] = 1;
		//cout << 76 << endl;
		return ;
	}
	if(mark[v] == 2)
	{
		return ;
	}
	mark[v] = 1;
	for(int i = 0; i < out[v].size(); i ++)
	{
		//cout << 74 << " " << out[v][i] << endl;
		Dfs(out[v][i]);
	}
	mark[v] = 2;
}
int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	for(int i = 0; i < m ; i ++)
	{
		int x, y;
		cin >> x;
		cin >> y;
		out[x].push_back(y);
		in[y].push_back(x);
	}
	for(int i = 1; i <= n; i ++)
	{
		if(part[i] == 0)
		{
			dfs(i);
			nparts ++;
		}
		//cout << part[i] << " ";
	}
	int ans = n - nparts + 1;
	for(int i = 1; i <= n; i ++)
	{
		if(mark[i] == 0)
		{
			Dfs(i);
		}
	}
	for(int i = 1; i < nparts; i ++)
	{
		//cout << cycpart[i] << " ";
		ans += cycpart[i];
	}
	cout << ans;
	return 0;
}