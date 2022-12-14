#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<long double> point;

const int maxn = 50 + 10;
const int inf = 3e5;

string s[maxn], t[2*maxn];
bool mark[maxn][maxn], visited[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	vector<pair<int,int>> knight;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (s[i][j] == 'x')
				mark[i][j] = 1;
			else if (s[i][j] == 'o')
				knight.push_back({i,j});
	for (int i = 0; i < 2*n-1; i++)
		for (int j = 0; j < 2*n-1; j++)
			t[i] += '.';
	for (int i = -(n-1); i < n; i++){
		for (int j = -(n-1); j < n; j++){
			bool found = 0;
			for (auto it : knight){
				int x = it.first, y = it.second;
				if (0 <= x + i and x + i < n and 0 <= y + j and y + j < n){
					if (s[x+i][y+j] == '.')
						found = 1;
				}
			}
			if (!found){
				t[i+n-1][j+n-1] = 'x';
				for (auto it : knight){
					int x = it.first, y = it.second;
					if (0 <= x + i and x + i < n and 0 <= y + j and y + j < n)
						visited[x+i][y+j] = 1;
				}
			}
		}
	}
	t[n-1][n-1] = 'o';
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (mark[i][j] and !visited[i][j])
				return cout << "NO\n", 0;
	cout << "YES\n";
	for (int i = 0; i < 2*n-1; i++)
		cout << t[i] << '\n';
}