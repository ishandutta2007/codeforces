#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 255;
const int DX[] = {-1, 0, 0, 1};
const int DY[] = {0, -1, 1, 0};

int n, m, q, p;
int cnt = 0;
char s[N][N];
int cur[N][N];
int res[N][N];
queue <pair <PII, int> > Q;

inline bool exist(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

void dfs(int x, int y, int ile){
	cur[x][y] = cnt;
	Q.push({{x, y}, ile});

	while(!Q.empty()){
		pair <PII, int> curV = Q.front();
		Q.pop();
		
		x = curV.st.st, y = curV.st.nd;
		ile = curV.nd;

		res[x][y] += ile;
		for(int i = 0; i < 4; ++i){
			int nx = x + DX[i];
			int ny = y + DY[i];
			if(exist(nx, ny) && cur[nx][ny] < cnt && s[nx][ny] != '*' && ile / 2 > 0)
				cur[nx][ny] = cnt,
				Q.push({{nx, ny}, ile / 2});
		}
	}
}

int main(){
	scanf("%d %d %d %d", &n, &m, &q, &p);
	for(int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			if(s[i][j] >= 'A' && s[i][j] <= 'Z')
				++cnt,
				dfs(i, j, (s[i][j] - 'A' + 1) * q);
		}
	
	int result = 0;	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(res[i][j] > p)
				++result;
	printf("%d\n", result);
	return 0;
}