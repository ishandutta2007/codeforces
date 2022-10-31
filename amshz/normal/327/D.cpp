# include <bits/stdc++.h>
 
using namespace std;
 
# define F first
# define S second
# define endl '\n'
 
const int xn = 5e2+10;
bool a[xn][xn], mark[xn][xn];
vector <int> hx[xn*xn];
vector <int> hy[xn*xn];
int n, m, ans, t;
 
void DFS(int x, int y, int d){
	if (mark[x][y]) return;
	mark[x][y] = true;
	hx[d].push_back(x);
	hy[d].push_back(y);
	if (x > 0 and a[x-1][y]) DFS(x-1, y, d+1);
	if (x < n-1 and a[x+1][y]) DFS(x+1, y, d+1);
	if (y > 0 and a[x][y-1]) DFS(x, y-1, d+1);
	if (y < m-1 and a[x][y+1]) DFS(x, y+1, d+1);
}
 
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin >> n >> m;
	string g;
	for (int i=0; i<n; i++){
		cin >> g;
		for (int j=0; j<m; j++)
			if (g[j] == '.') a[i][j] = 1, ans++;
	}
	
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (!mark[i][j] and a[i][j]) DFS(i, j, 0), t++;
			
	cout << 3*ans-2*t << endl;
	
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (a[i][j]) cout << "B " << i+1 << ' ' << j+1 << endl;
	
	for (int i=xn*xn-10; i>=1; i--){
		for (int j=0; j<hx[i].size(); j++){
			cout << "D " << hx[i][j]+1 << ' ' << hy[i][j]+1 << endl;
			cout << "R " << hx[i][j]+1 << ' ' << hy[i][j]+1 << endl;
		}
	}
	
}