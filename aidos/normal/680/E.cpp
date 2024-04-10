#include <bits/stdc++.h>

#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define LL long long
#define mp make_pair
#define pb push_back
#define f first                                        
#define s second

using namespace std;

const int N = 505;
const int mod = 1e9 + 7;

char s[N][N];
int n, k;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int clr[N][N], was[N][N], size[N*N], dis[N*N], cnt;
int d[N][N], e[N][N];
int cur, ans;

bool check(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < n && s[x][y] == '.';
}

void dfs(int i, int j, int color) {
	was[i][j] = 1;
	clr[i+1][j+1] = color;
	size[color]++;
	for(int k = 0; k < 4; ++k) {
		int x = i + dx[k], y = j + dy[k];
		if(check(x,y) && !was[x][y]) {
			dfs(x, y, color);
		}
	}
}

void add(int i, int j) { 
	int &x = dis[clr[i][j]];
	x++;
	if(x == 1) cur += size[clr[i][j]];
}
void del(int i, int j) { 
	int &x = dis[clr[i][j]];
	x--;
	if(x == 0) cur -= size[clr[i][j]];
}

int main() {
  #ifndef ONLINE_JUDGE
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif
		scanf("%d%d", &n, &k);
		for(int i=0; i<n; ++i)
			scanf("\n%s", s[i]);
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j) {
				if(s[i][j] == 'X' || was[i][j]) 
					continue;
				dfs(i, j, ++cnt);
			}
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=n; ++j) {
				d[i][j] = d[i-1][j] + d[i][j-1] - d[i-1][j-1] + (s[i-1][j-1]=='.');
				if(i>=k && j>=k) 
					e[i][j] = d[i][j] - d[i-k][j] - d[i][j-k] + d[i-k][j-k];
			}
		for(int i=k; i<=n; ++i) {
			for(int j=1; j<=k; ++j)
				add(i-k, j), add(i+1, j);
			for(int r=i-k+1; r<=i; ++r)
				for(int c=0; c<=k+1; ++c)
					add(r, c);
			for(int j=k; j<=n; ++j) {
				ans = max(ans, cur - e[i][j] + k * k);
				del(i-k, j-k+1), add(i-k, j+1);
				del(i+1, j-k+1), add(i+1, j+1);
				for(int l=i-k+1; l<=i; ++l)
					del(l, j-k), add(l, j+2);
				//ans = max(ans, cur - e[i][j] + k * k);
			}
			memset(dis,0,sizeof dis), cur=0;
		}
		cout << ans;
  return 0;
}