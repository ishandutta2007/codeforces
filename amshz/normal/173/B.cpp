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

const int xn = 1e3+10;

int dis[2][xn];
char a[xn][xn];

int main(){
	fast_io;
	
	int n, m;
	cin >> n >> m;
	
	string g;
	for (int i=0; i<n; i++){
		cin >> g;
		for (int j=0; j<m; j++) a[i][j] = g[j];
	}
	
	for (int i=0; i<2; i++)
		for (int j=0; j<max(n, m); j++) dis[i][j] = -1;
	
	queue <pair <bool, int> > q;
	q.push({1, 0});
	dis[1][0] = 0;
	while (q.size()){
		int v = q.front().S, f = q.front().F;
		q.pop();
		
		if (!f){
			for (int i=0; i<n; i++)
				if (a[i][v] == '#' && dis[!f][i] == -1) q.push({!f, i}), dis[!f][i] = dis[f][v]+1;
		}
		else{
			for (int i=0; i<m; i++)
				if (a[v][i] == '#' && dis[!f][i] == -1) q.push({!f, i}), dis[!f][i] = dis[f][v]+1;
		}
	}
	cout << dis[1][n-1];
	return 0;
}