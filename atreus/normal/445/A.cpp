#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 100;
string c[maxn];

int main (){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> c[i];
		for (int j = 0; j < c[i].size(); j++){
			if (c[i][j] == '.'){
				if ((i + j) % 2 == 0)
					c[i][j] = 'B';
				else
					c[i][j] = 'W';
			}
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
			cout << c[i][j];
		cout << endl;
	}
}