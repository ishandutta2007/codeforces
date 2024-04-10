# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 2e3+10;
const int xm = 26+10;
const int SQ = 320;
const int sq = 1e3+10;
const ll inf = 1e18+10;


int n,m, qq;
char A[xn][xn], B[xn][xn];
int x1[xm], y1[xm], x2[xm], y2[xm];
int tot;
void Solve() {
	for (int i = 1; i <= 26; i++) x1[i] = y1[i] = x2[i] = y2[i] = 0;
	tot = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string st;
		cin >> st;
		st = '.' + st;
		for(int j = 1; j <= m; j++) {
			A[i][j] = st[j];
			B[i][j] = '.';
			if (A[i][j]=='.') continue;
			int yo = A[i][j]-'a'+1;
			tot = max(tot,yo);
			if (x1[yo]==0) x1[yo] = i , y1[yo] = j;
			x2[yo] = i; y2[yo] = j;
		}
	}
	if(!tot) {
		cout << "YES" << endl << 0 << endl;
		return;
	}
	for(int i = 1; i <= tot; i++) {
		if (!x1[i]) x1[i] = x1[tot], y1[i] = y1[tot], x2[i] = x2[tot], y2[i] = y2[tot];
		if(x1[i] != x2[i] && y1[i] != y2[i]) {
			cout << "NO" << endl;
			return;
		}
		for(int x = x1[i]; x <= x2[i]; x++) {
			for(int y = y1[i]; y <= y2[i]; y++) {
				B[x][y] = 'a'+i-1;
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if (A[i][j] != B[i][j]) {
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl << tot << endl;
	for(int i = 1; i <= tot; i++) {
		cout << x1[i] << sep << y1[i] << sep << x2[i] << sep << y2[i] << endl;
	}
}
 
int main() {
	cin >> qq;
	while (qq--) Solve();
}