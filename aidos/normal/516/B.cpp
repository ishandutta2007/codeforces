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


char c[2020][2020];
queue < int > q;
bool used[2020][2020];
int fr[2020][2020];
int cnt[2020][2020];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m;
void upd(int x, int y){
 		for(int k = 0; k < 4; k++){
			int nx = dx[k] + x;
			int ny = dy[k] + y;
			if(nx < 0 || nx >= n || ny < 0 || ny >= m || used[nx][ny] || c[nx][ny] == '*') continue;
			cnt[nx][ny]--;
			if(cnt[nx][ny] == 1) q.push(nx * m + ny);
		}
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%s", &c[i]);
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(c[i][j]=='*') continue;
			for(int k = 0; k < 4; k++){
				int x = dx[k] + i;
				int y = dy[k] + j;
				if(x < 0 || x >= n || y < 0 || y >=m || c[x][y] == '*') continue;
				cnt[i][j]++;
			}
			if(cnt[i][j] == 0){
				cout << "Not unique\n";
				return 0;	
			}
			if(cnt[i][j] == 1) q.push(i*m + j);	
		}
	}
	memset(fr, -1, sizeof fr);

	while(q.size() > 0){
		int t = q.front();
		int x = t/m;
		int y = t % m;
		q.pop();
		if(cnt[x][y] == 0) continue;
		for(int k = 0; k < 4; k++){
			int nx = dx[k] + x;
			int ny = dy[k] + y;
			if(nx < 0 || nx >= n || ny < 0 || ny >= m || used[nx][ny] || c[nx][ny] == '*') continue;
			used[nx][ny] = true;
			used[x][y] = true;
			cnt[nx][ny] = 0;
			cnt[x][y] = 0;
			fr[nx][ny] = t;
			fr[x][y] = nx * m + ny;
			upd(nx, ny);
		}

	}
	for(int i = 0;  i < n; i++){
		for(int j = 0; j < m; j++){
			if(c[i][j] == '*') continue;
			if(!used[i][j]){
				cout << "Not unique\n";
				return 0;
			}	
		}
	}
	for(int i = 0;  i < n; i++){
		for(int j = 0; j < m; j++){
			if(c[i][j] == '*') printf("*");
			else{
				int x = fr[i][j] / m;
				int y = fr[i][j] % m;
				if(x > i){
					printf("^");
				}
				else if(x < i){
					printf("v");
				}
				else if(y > j){
					printf("<");
				}
				else {
					printf(">");
				}
			}
		}
		printf("\n");
	}
		


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}