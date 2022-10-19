#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <ctime>
#include <set>
#include <iomanip>
#include <ctime>
#define fr first
#define sc second
#define lli long long int
using namespace std;
const int N = 1e5 + 1;
int n, m, x, y;
bool color[N], nerkv[N], nk[N];
vector <int> gr[N];
priority_queue <int> fpat;
vector <int> pat;
void DFS(int s)
{
	color[s] = true;
	int h;

	for (int i = 0; i < gr[s].size(); i++)
	{
		if (!color[gr[s][i]] && !nk[gr[s][i]])
			fpat.push(-gr[s][i]), nk[gr[s][i]] = true;
	}
	if (!fpat.empty())
	{
		h = -fpat.top();
		if (!nerkv[h]) 
			pat.push_back(h), nerkv[h] = true;
		fpat.pop();
		DFS(h);
		

	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	fpat.push(-1);
	nk[1] = true;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	DFS(1);
	for (int i = 0; i < pat.size(); i++)
	{
		cout << pat[i] << " ";
	}
	while (!fpat.empty())
	{
		cout << fpat.top() << " ";
		fpat.pop();
	}
	return 0;
}