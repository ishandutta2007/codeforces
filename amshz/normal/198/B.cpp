# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;

# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const int xn = 2e5+10;

int ans[xn][2];
string a[2];

int main(){
	//fast_io;
	
	int n, k;
	cin >> n >> k;
	cin >> a[0] >> a[1];
	
	for (int i=0; i<=n+k; i++) for (int j=0; j<2; j++) ans[i][j] = -1;
	for (int i=n; i<=n+k; i++) for (int j=0; j<2; j++) a[j] += '-';
	
	queue <pii> q;
	q.push({0, 0});
	ans[0][0] = 0;
	
	while (q.size()){
		int x = q.front().F, y = q.front().S;
		q.pop();
		if (x > n-1) continue;
		if (x > 0 && ans[x-1][y] == -1 && a[y][x-1] != 'X' && ans[x][y] <= x-2) ans[x-1][y] = ans[x][y]+1, q.push({x-1, y});
		if (ans[x+1][y] == -1 && a[y][x+1] != 'X') ans[x+1][y] = ans[x][y]+1, q.push({x+1, y});
		if (a[1-y][x+k] != 'X' && ans[x+k][1-y] == -1) ans[x+k][1-y] = ans[x][y]+1, q.push({x+k, 1-y});
	}
	                     
	int mn = 1e9;
	for (int i=n; i<=n+k; i++) for (int j=0; j<2; j++) if (ans[i][j] != -1) mn = min(mn, ans[i][j]);
	
	if (mn == 1e9) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}