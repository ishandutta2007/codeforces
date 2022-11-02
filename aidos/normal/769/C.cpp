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
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;
char c[1010][1010];
int dis[1010][1010];
int n, m, k;
string ans;
int good(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m && (c[x][y] == '.' || c[x][y] == 'X');
}
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
string C = "DLRU";

void solve(){
	for(int i = 1; i < C.size(); i++){
		if(C[i] < C[i-1]){
			cout <<"Wrong";
			return;
		}
	}
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < n; i++)
		scanf("%s", c[i]);
	queue<pii> q;
	
	int A, B;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			dis[i][j] = inf;
			if(c[i][j] == 'X'){
				A = i;
				B = j;
				q.push(mp(i, j));
				dis[i][j] = 0;
			}
		}
	}
	if(k % 2 == 1){
		cout <<"IMPOSSIBLE" << endl;
		return;
	}
	while(q.size() > 0){
		int x = q.front().f;
		int y = q.front().s;
		q.pop();
		for(int i = 0; i < 4; i++){
			int X = dx[i] + x;
			int Y = dy[i] + y;
			if(good(X, Y) && dis[x][y] + 1 < dis[X][Y]){
				dis[X][Y] = dis[x][y] + 1;
				q.push(mp(X, Y));
			}
		}
	}
	for(int i = 1; i <= k; i++){
		int dir = -1;
		for(int j = 0; j < 4; j++){
			int x = A+dx[j];
			int y = B+dy[j];
			if(good(x, y) && dis[x][y] <= k - i){
				dir = j;
				break;
			}
		}
		if(dir == -1){
			cout <<"IMPOSSIBLE" << endl;
			return;
		}
		A += dx[dir];
		B += dy[dir];
		ans += C[dir];
	}
	printf("%s\n", ans.c_str());
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}