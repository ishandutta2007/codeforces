
#include <math.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 500;
vector <int> v[maxn];
bool iscat[maxn], mark[maxn];
int m, cnt;

void dfs(int v1, int cats){
	mark[v1] = true;
	if (cats > m)
		return;
	bool isleaf = true;
	for (int i = 0; i < v[v1].size(); i++){
		if (!mark[v[v1][i]]){
			int k = cats + 1;
			if (!iscat[v[v1][i]])
				k = 0;
			dfs(v[v1][i], k);
			isleaf = false;
		}
	}
	if (isleaf == true)
		cnt ++;
}

int main(){
	int n;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> iscat[i];
	for (int i = 1; i < n; i++){
		int v1, v2;
		cin >> v1 >> v2;
		v[v1].push_back(v2);
		v[v2].push_back(v1);
	}
	dfs(1, iscat[1]);
	cout << cnt << endl;
}