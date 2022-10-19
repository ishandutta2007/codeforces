
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;


long long mod = 1000000007;

vector< vector < vector<vector<int> > > > graph;
vector<int> answer;
vector<vector<vector<int>> > connections;
vector<int> however;
void addedge(int x, int y, int z, int i) {
	if (x == y) {
		however.push_back(i);
		return;
	}
	if (graph[z][x].size() != 0) {
		auto a = graph[z][x][0];
		//x and y linked with index i
		//x and a[0] linked with index a[1]

		connections[i].push_back({ a[1], !a[2] });
		graph[z][x].clear();
		graph[z][a[0]].clear();
		addedge(a[0], y, z, i);
		return;
	}
	if (graph[z][y].size() != 0) {
		auto a = graph[z][y][0];
		//x and y linked with index i
		//y and a[0] linked with index a[1]

		connections[i].push_back({ a[1], a[2] });
		graph[z][y].clear();
		graph[z][a[0]].clear();
		addedge(x, a[0], z, i);
		return;
	}

	graph[z][x].push_back({ y, i, 1 });
	graph[z][y].push_back({ x, i, 0 });
}

void set2(int i, int h) {
	answer[i] = h+1;
	for (auto p : connections[i]) {
		set2(p[0], p[1] ^ h ^ 1);
	}
}

void set3(int z, int x, int h) {
	if (answer[graph[z][x][0][1]] != 0) return;

	set2(graph[z][x][0][1], h ^ graph[z][x][0][2]);
	if (graph[1 - z][x].size()) {
		set3(!z, x, !h);
	}
	if (graph[1 - z][graph[z][x][0][0]].size()) {
		set3(!z, graph[z][x][0][0], h);
	}
}


int main()
{
	int n, m;
	cin >> n >> m;
	//to, index, whichway
	graph = vector< vector < vector<vector<int> > > >(2, vector < vector<vector<int> > >(n));
	connections = vector<vector<vector<int>> >(m);
	answer = vector<int>(m, 0);

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		x--;
		y--;
		z--;
		addedge(x, y, z, i);
	}
	int ans = 0;
	for (auto z : however) {
		set2(z, 1);
	}
	for (int z = 0; z < 2; z++) {
		for (int x = 0; x < n; x++) {
			if (graph[z][x].size() != 0) {
				if (z == 0) ans++;
				set3(z, x, 1);
			}
		}
	}
	cout << ans << endl;
	for (int i = 0; i < m; i++) {
		cout << (answer[i]);
	}
}