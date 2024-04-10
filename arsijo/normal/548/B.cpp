#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define x first
#define y second
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define print2(ar, n, m) for(int i = 0; i < n; i++){ for(int j = 0; j < m; j++) cout << ar[i][j]; cout << endl; }
#define print(ar, n) for(int i = 0; i < n; i++) cout << ar[i] <<  " ";
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef pair<int, int> ii;
typedef long long ll;
typedef double ld;
const int IM = 2e9;
const ld E = 1e-9;
const int MAX = 30000;
int ar[MAX], pos = 0, t = 0;

int main() {

	int n, m, q;
	cin >> n >> m >> q;

	map<int, int> ma;

	int ar[n][m], ans[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> ar[i][j];
		int g = 0, a = 0;
		for (int j = 0; j < m; j++)
			if (ar[i][j] == 1) {
				a++;
				g = max(g, a);
			} else
				a = 0;
		ans[i] = g;
		ma[g]++;
	}

	while (q--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		ar[a][b] = 1 - ar[a][b];
		int g = 0, c = 0;
		for (int j = 0; j < m; j++)
			if (ar[a][j] == 1) {
				c++;
				g = max(g, c);
			} else
				c = 0;
		if(g != ans[a]){
			ma[ans[a]]--;
			if(ma[ans[a]] == 0)
				ma.erase(ans[a]);
			ma[g]++;
			ans[a] = g;
		}
		cout << ma.rbegin()->first << endl;
	}

}