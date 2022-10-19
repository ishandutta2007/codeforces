//#pragma GCC optimize(2)
// Happy TLE and WA every day!
// by: zxb the vegetable chicken
#include<bits/stdc++.h>
#define mp              make_pair
#define rep(i,n)        for(int i = 0; i < n; i++)
#define foreach(i,c)    for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define BINF            0x7fffffff
#define INF             0x3f3f3f3f
#define LINF            4557430888798830399
#define pb              push_back
#define F               first
#define S               second
#define Time            clock()/CLOCKS_PER_SEC
//#define usingFiles
using namespace std;

typedef unsigned int ui;
typedef pair<int, int> pii;
typedef long long ll;

inline bool Read(int& x){
	x = 0;
	int c;
	int sign = 1;
	while( (c = getchar()) < '0' || c > '9' ) if(c == '-') sign = -1;
	x = c ^ '0';
	while( (c = getchar()) >= '0' && c <= '9' ) x = (x<<3) + (x<<1) + (c ^ '0');
	x *= sign;
	return 1;
}

inline bool Write(int x){
	if(x >= 10) Write(x / 10);
	putchar(x % 10 + '0');
	return 1;
}

const int rp = 666666;
const bool debug = 1;
const bool I_good_vegetable_a = 1;
const int dx[] = {0, 1, -1, 0};
const int dy[] = {1, 0, 0, -1};

int n, m, p;
int expandSpeed[10];
int ans[10];
string grid[1010];
int player[1010][1010];
queue<pair<pair<int, int>, int> > q[10];
bool inr(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;
}

signed main(){
	ios::sync_with_stdio(false);
	#ifdef usingFiles
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	memset(player, -1, sizeof(player));
	cin >> n >> m >> p;
	rep(i, p) cin >> expandSpeed[i];
	rep(i, n){
		cin >> grid[i];
		rep(j, m){
			if(isdigit(grid[i][j])){
				player[i][j] = (grid[i][j] - '1');
				q[player[i][j]].push(mp(mp(i, j), expandSpeed[player[i][j]]));
			}
		}
	}
	while(1){
		bool update = 0;
		rep(i, p){
			queue<pair<pair<int, int>, int> > newq;
			if(q[i].empty()) continue;
			update = 1;
			while(!q[i].empty()){
				pair<pair<int, int>, int> now = q[i].front(); q[i].pop();
				int x = now.F.F, y = now.F.S, dept = now.S;
				if(dept == 0) newq.push(mp(mp(x, y), expandSpeed[i]));
				else rep(dir, 4){
					int nx = x + dx[dir], ny = y + dy[dir];
					if(inr(nx, ny) && grid[nx][ny] == '.' && player[nx][ny] == -1){
						q[i].push(mp(mp(nx, ny), dept - 1));
						player[nx][ny] = i;
					}
				}
			}
			q[i] = newq;
		}
		if(!update) break;
	}
	rep(i, n){
		rep(j, m){
			if(player[i][j] >= 0){
				ans[player[i][j]]++;
			}
		}
	}
	rep(i, p) cout << ans[i] << " ";
	return 0;
}