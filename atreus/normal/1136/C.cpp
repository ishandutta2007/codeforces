#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
const int maxn = 500 + 10;

int a[maxn][maxn], b[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> b[i][j];
	for (int sum = 2; sum <= n + m; sum++){
		vector<int> x, y;
		for (int i = 1; i <= min(n, sum); i++){
			int j = sum - i;
			if (j > m or j <= 0)
				continue;
			x.push_back(a[i][j]);
			y.push_back(b[i][j]);
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		if (x != y)
			return cout << "NO" << endl, 0;
	}
	cout << "YES" << endl;
}