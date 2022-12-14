#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1000 + 10;

int a[maxn][maxn];
vector<int> row[maxn], col[maxn];

int get(int x, int X, int y, int Y){
	if (x > y){
		swap(x, y);
		swap(X, Y);
	}
	return max(X + (y - x), Y);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> a[i][j];
			row[i].push_back(a[i][j]);
			col[j].push_back(a[i][j]);
		}
	}
	for (int i = 0; i < n; i++){
		sort(row[i].begin(), row[i].end());
		row[i].resize(unique(row[i].begin(), row[i].end()) - row[i].begin());
	}
	for (int i = 0; i < m; i++){
		sort(col[i].begin(), col[i].end());
		col[i].resize(unique(col[i].begin(), col[i].end()) - col[i].begin());
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			int idx1 = lower_bound(row[i].begin(), row[i].end(), a[i][j]) - row[i].begin() + 1;
			int idx2 = lower_bound(col[j].begin(), col[j].end(), a[i][j]) - col[j].begin() + 1;
			cout << get(idx1, row[i].size(), idx2, col[j].size()) << " ";
		}
		cout << '\n';
	}
}