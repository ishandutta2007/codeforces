#include <iostream>
#include <vector>

using namespace std;

struct edge
{
	int from, to;
	int idx;
};

bool dfs(int v, vector< vector<int> >& edges, vector<char>& color)
{
	for (int i = 0; i < edges[v].size(); ++i) {
		int w = edges[v][i];
		if (color[w] == '0') {
			color[w] = (color[v] == 'i') ? 'o' : 'i';
			if (!dfs(w, edges, color)) return false;
		} else {
			if (color[v] == color[w]) return false;
		}
	}
	return true;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<edge> edges(m);
	for (int i = 0; i < m; ++i) {
		cin >> edges[i].from >> edges[i].to;
		if (edges[i].from > edges[i].to) swap(edges[i].from, edges[i].to);
		edges[i].idx = i;
	}

	vector< vector<int> > graph(m);

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			int f1 = edges[i].from, t1 = edges[i].to,
				f2 = edges[j].from, t2 = edges[j].to;

			if ((f1 < f2 && f2 < t1 && t1 < t2) || (f2 < f1 && f1 < t2 && t2 < t1)) {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	vector<char> color(m, '0');
	for (int v = 0; v < m; ++v) {
		if (color[v] == '0') {
			color[v] = 'i';
			if (!dfs(v, graph, color)) {
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}

	for (int i = 0; i < m; ++i) cout << color[i];
	cout << endl;
}