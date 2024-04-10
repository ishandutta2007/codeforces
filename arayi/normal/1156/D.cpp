
#include <iostream>
#include <string>
#include <vector>
#define fr first
#define sc second
using namespace std;
const int N = 2e5 + 30;
long long int t[N][5];
vector <pair<int, int> > g[N];
long long int sum[N];
int a, b, c, n;
bool col[N];
void dfs(int v)
{
	
	col[v] = true;
	bool sm = true;
	for(auto p : g[v])
	{
		if(!col[p.fr])
		{
			sm = false;
			dfs(p.fr);
			
			if(p.sc)
			{
				sum[v] += 2*t[v][3]*(t[p.fr][3] + 1);
				sum[v] += t[v][3]*(t[p.fr][4]);
				sum[v] += t[v][4]*(t[p.fr][3] + 1);
				sum[v] += t[v][3]*(t[p.fr][2]);
				sum[v] += t[v][2]*(t[p.fr][3] + 1);
			}
			else
			{
				sum[v] += t[v][1]*(t[p.fr][4] + 1);
				sum[v] += t[v][3]*(t[p.fr][4] + 1);
				sum[v] += t[v][4]*t[p.fr][3];
				sum[v] += t[v][4]*(t[p.fr][1]);
				sum[v] += 2*t[v][4]*(t[p.fr][4] + 1);
				
			}
			if(p.sc)
			{
				t[v][2] += t[p.fr][2] + t[p.fr][4];
				t[v][3] += t[p.fr][3] + 1;
			}
			else
			{
				t[v][1] += t[p.fr][1] + t[p.fr][3];
				t[v][4] += t[p.fr][4] + 1;
			}
			//2*(t[i][4]*(t[i][4] - 1) + t[i][4]*t[i][3] + t[i][4]*t[i][1] + 2*t[i][3]*(t[i][3] - 1) + t[i][3]*t[i][2] + t[i][2]*t[i][3])
			
			
		}
	}

}
long long int pat;
int main()
{
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b >> c;
		g[a].push_back(make_pair(b, c));
		g[b].push_back(make_pair(a, c));
	}
	dfs(1);
	for (int i = 1; i <= n; i++)
	{
		sum[i] += 2*(t[i][3] + t[i][4]) + t[i][2] + t[i][1];
		pat += sum[i];
	}
	cout << pat;
	return 0;
}