# include <bits/stdc++.h>

using namespace std;

const int xn = 1e3+10;
bool f[xn][xn];
pair <int,int> t[xn];

int main(){
	int n, m, q, w;
	cin >> n >> m;
	for (int i=1; i<=n; i++) t[i].second = i;
	for (int i=1; i<=m; i++) cin >> q >> w, f[q][w] = 1, f[w][q] = 1, t[q].first++, t[w].first++;
	cout << n-1 << endl;
	for (int i=1; i<=n; i++){
		if (t[i].first == 0){
			for (int j=1; j<=n; j++){
				if (j != i) cout << i << ' ' << j << endl;
			}
			return 0;
		}
	}
}