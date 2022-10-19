#include <iostream>
#include <vector>
using namespace std;

const int N = 1003;
int n;
vector <int> graph[N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	int i, ans = 0;
	for (i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (i = 1; i <= n; i++)
	{
		if (graph[i].size() == 1)
			ans++;
	}
	cout << ans << endl;
	return 0;
}