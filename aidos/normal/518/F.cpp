#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;
int n, m;
	int dx[] = {0, 1, 0, -1};
	int dy[] = {1, 0, -1, 0};
	int dp[2020][2020][4][5];
	bool used[2020][2020][4][5];
	char c[2020][2020];
	int get(int x, int y, int col, int d){
		if(col > 2) return 0;
		if(x < 0 || y < 0 || x >= n || y >= m || c[x][y] != '.') return 0;
		if(x == n-1 || y == m-1 || y == 0 || x == 0) return 1;
		if(used[x][y][col][d]) return dp[x][y][col][d];
		used[x][y][col][d] = true;
		int &res = dp[x][y][col][d];
		int z = d + 2;
		if(z >= 4) z -= 4;
		for(int i = 0; i < 4; i++){
			if(z == i) continue;
			if(i != d) res += get(x+dx[i], y + dy[i], col+1, i);
			else res += get(x+dx[i], y + dy[i], col, i);
		}
		return dp[x][y][col][d];
	}


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    	cin >> n >> m;
		for(int i = 0; i < n; i++){
			scanf("%s\n", &c[i]);
		}
		ll ans = 0;
		for(int i = 1; i < n-1; i++){
			if(c[i][0] != '#') ans += get(i, 1, 0, 0);
			if(c[i][m-1] != '#') ans += get(i, m-2, 0, 2);
		}
		for(int i = 1; i < m-1; i++){
			if(c[0][i] != '#') ans += get(1, i, 0, 1);
			if(c[n-1][i] != '#') ans += get(n-2, i, 0, 3);
		}
		ans/=2;
		for(int i = 2; i<n-1; i++){
			if(c[i][0] == '#') continue;
			if(c[i-1][0] == '#') continue;
			int j = 1;
			while(j < m-1 && c[i][j] == '.' && c[i-1][j] == '.') j++;
			ans -= j - 1;
		}
		for(int i = 2; i<n-1; i++){
			if(c[i][m-1] == '#') continue;
			if(c[i-1][m-1] == '#') continue;
			int j = m-1;
			while(j > 0 && c[i][j] == '.' && c[i-1][j] == '.') j--;
			ans -= m - j - 2;
		}
		for(int i = 2; i < m-1; i++){
			if(c[0][i] != '.') continue;
			if(c[0][i-1] != '.') continue;
			int j = 1;
			while(j < n-1 && c[j][i] == '.' && c[j][i-1] == '.') j++;
			ans -= j - 1;
		}
		for(int i = 2; i < m-1; i++){
			if(c[n-1][i] != '.') continue;
			if(c[n-1][i-1] != '.') continue;
			int j = n-1;
			while(j > 0 && c[j][i] == '.' && c[j][i-1] == '.') j--;
			ans -= n - j - 2;
		}
		cout << ans << endl;



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}