#include <math.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, cnt = -1;
vector <int> v[120], lan[120];
bool mark[120];

void dfs(int x){
	mark[x] = true;
	for (int i = 0; i < v[x].size(); i++)
		if (!mark[v[x][i]])
			dfs(v[x][i]);
}

int main(){
	cin >> n >> m;
	bool endcode = true;
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		if (k > 0)
            endcode = false;
		for (int j = 1; j <= k; j++){
			int qp;
			cin >> qp;
			lan[qp].push_back(i);
		}
	}
	if (endcode == true){
        cout << n << endl;
        return 0;
	}
	for (int i = 1; i <= m; i++){
		if (lan[i].size() <= 1)
			continue;
		for (int j = 0; j < lan[i].size() - 1; j++){
			for (int k = j + 1; k < lan[i].size(); k++){
				v[lan[i][j]].push_back(lan[i][k]);
				v[lan[i][k]].push_back(lan[i][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++){
		if (!mark[i]){
			cnt ++;
			dfs(i);
		}
	}
	cout << cnt << endl;
}