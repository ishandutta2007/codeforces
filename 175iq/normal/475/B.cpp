#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {	
	int n; cin >> n;
	int m; cin >> m;
	
	string sHor; cin >> sHor;
	string sVer; cin >> sVer;
	
	for (int y = 0 ; y < n ; y++) for (int x = 0 ; x < m ; x++) {
		vector<vector<bool>> visited(n, vector<bool>(m));
		
		visited[y][x] = true;
		vector<pair<int, int>> q = { { y , x } };
		
		for (int i = 0 ; i < q.size() ; i++) {
			int x2 = q[i].second;
			int y2 = q[i].first;
			
			int x3 = x2;
			int y3 = y2;
			if (sHor[y3] == '<') x3--; else x3++;
			if (x3 >= 0 && x3 < m && !visited[y3][x3]) {
				visited[y3][x3] = true;
				q.push_back({ y3 , x3 });
			}
			
			int x4 = x2;
			int y4 = y2;
			if (sVer[x4] == '^') y4--; else y4++;
			if (y4 >= 0 && y4 < n && !visited[y4][x4]) {
				visited[y4][x4] = true;
				q.push_back({ y4 , x4 });
			}
		}
		
		for (int y2 = 0 ; y2 < n ; y2++) for (int x2 = 0 ; x2 < m ; x2++) if (!visited[y2][x2]) {
			cout << "NO";
			return 0;
		}
	}
	
	cout << "YES";
}