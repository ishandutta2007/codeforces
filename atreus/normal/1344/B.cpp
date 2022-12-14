#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<long double> point;

const int maxn = 1000 + 10;

string s[maxn];
int par[maxn*maxn];
int cmp;
int row[maxn], col[maxn], a[maxn], b[maxn];

int get_par(int v){
	return par[v] < 0 ? v : par[v] = get_par(par[v]);
}

void merge(int v, int u){
	if ((v = get_par(v)) == (u = get_par(u)))
		return;
	cmp --;
	par[v] = u;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++){
		bool fi = 0, se = 0;
		for (int j = 0; j < m; j++){
			if (s[i][j] == '#')
				fi = 1;
			if (s[i][j] == '.')
				se |= fi;
			if (s[i][j] == '#' and se == true)
				return cout << -1 << endl, 0;
		}
	}
	for (int j = 0; j < m; j++){
		bool fi = 0, se = 0;
		for (int i = 0; i < n; i++){
			if (s[i][j] == '#')
				fi = 1;
			if (s[i][j] == '.')
				se |= fi;
			if (s[i][j] == '#' and se == true)
				return cout << -1 << endl, 0;
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] == '#'){
				cmp += (s[i][j] == '#');
				row[i] = true;
				col[j] = true;
			}
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] == '#' or (row[i] == false and col[j] == false)){
				a[i] = 1;
				b[j] = 1;
			}
	int sum = 0;
	for (int i = 0; i < max(n, m); i++)
		sum += a[i] + b[i];
	if (sum != n + m)
		return cout << -1 << endl, 0;
	memset(par, -1, sizeof par);
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] == '#' and s[i+1][j] == '#')
				merge(i*m+j, (i+1)*m+j);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m-1; j++)
			if (s[i][j] == '#' and s[i][j+1] == '#')
				merge(i*m+j, i*m+j+1);
	cout << cmp << endl;
}