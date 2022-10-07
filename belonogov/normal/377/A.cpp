#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 1000;
const int inf = 1e9;

char a[maxn][maxn];
bool use[maxn][maxn];
int step[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m, k;

bool check(int x, int y){
	return 0 <= x && x < n && 0 <= y && y < m;	
}

void dfs(int x, int y){
	int x1, y1;
	use[x][y] = 1;
	for (int i = 0; i < 4; i++){
		x1 = x + step[i][0];
		y1 = y + step[i][1];
		if (check(x1, y1) && !use[x1][y1] && a[x1][y1] == '.')
			dfs(x1, y1);
	}
	if (k > 0){
		a[x][y] = 'X';
		k--;
	}
}


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	bool flag = 1;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		scanf("%s", a[i]);
	for (int i = 0; i < n && flag; i++)
		for (int j = 0; j < m && flag; j++)
			if (a[i][j] == '.'){
				dfs(i, j);
				flag = 0;
			}
	for (int i = 0; i < n; i++)
		printf("%s\n", a[i]);
	
    return 0;
}