#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 60 + 10;
const int mod = 1e9 + 7;

string s[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> s[i];
		int minx = n, maxx = -1, miny = m, maxy = -1;
		int aminx = n, amaxx = -1, aminy = m, amaxy = -1;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (s[i][j] == 'P'){
					minx = min(minx, i);
					maxx = max(maxx, i);
					miny = min(miny, j);
					maxy = max(maxy, j);
				}
				else{
					aminx = min(aminx, i);
					amaxx = max(amaxx, i);
					aminy = min(aminy, j);
					amaxy = max(amaxy, j);
				}
			}
		}
		if (maxx == -1){
			cout << 0 << '\n';
			continue;
		}
		if (minx != 0 or maxx != n - 1 or miny != 0 or maxy != m - 1){
			cout << 1 << '\n';
			continue;
		}
		if (s[0][0] == 'A' or s[0][m - 1] == 'A' or s[n - 1][0] == 'A' or s[n - 1][m - 1] == 'A'){
			cout << 2 << '\n';
			continue;
		}
		bool is2 = 0;
		for (int i = 0; i < n; i++){
			bool p = 0;
			for (int j = 0; j < m; j++)
				if (s[i][j] == 'P')
					p = 1;
			if (p == 0)
				is2 = 1;
		}
		for (int j = 0; j < m; j++){
			bool p = 0;
			for (int i = 0; i < n; i++)
				if (s[i][j] == 'P')
					p = 1;
			if (p == 0)
				is2 = 1;
		}
		if (is2){
			cout << 2 << '\n';
			continue;
		}
		if (aminx == 0 or amaxx == n - 1 or aminy == 0 or amaxy == m - 1){
			cout << 3 << '\n';
			continue;
		}
		if (amaxx != -1){
			cout << 4 << '\n';
			continue;
		}
		cout << "MORTAL\n";
	}
}