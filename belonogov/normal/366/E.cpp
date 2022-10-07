#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;
#define mp make_pair
#define pb push_back
#define fr first
#define sc second

const int MAXN = 2e3 + 3;
const int INF = 1e9;

int a[MAXN][MAXN];
int b[MAXN * MAXN];
bool use[20][20];
int bestAns = 0;
int n, m;
vector < pair < int, int > > t[10];

void solve2(int x){
	int mn, mx;
	for (int i = 0; i < n; i++){
		mn = INF;
		mx = -INF;
		for (int j = 0; j < m; j++){
			if (a[i][j] == x){
				mn = min(mn, j);
				mx = max(mx, j);				
			}
		}
		if (mn != INF){
			t[x].pb(mp(i, mn));
			t[x].pb(mp(i, mx));			
		}
	}
}

inline int dist(pair < int, int > & a, pair < int, int > &  b){
	return abs(a.fr - b.fr) + abs(a.sc - b.sc);	
}

void solve(int x, int y){
	for (int i = 0; i < (int)t[x].size(); i++)
		for (int j = 0; j < (int)t[y].size(); j++)
			bestAns = max(bestAns, dist(t[x][i], t[y][j]));
}

int main(){
// 	freopen("in", "r", stdin);
	int k, s;
	scanf("%d%d%d%d\n", &n, &m, &k, &s);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			scanf("%d", &a[i][j]);
			a[i][j]--;			
		}
	for (int i = 0; i < s; i++){
		scanf("%d", &b[i]);
		b[i]--;
	}
	for (int i = 0; i < s - 1; i++)
		use[b[i]][b[i + 1]] = use[b[i + 1]][b[i]] = 1;
	for (int i = 0; i < k; i++)
		solve2(i);
	
	
	for (int i = 0; i < k; i++)
		for (int j = i; j < k; j++)
			if (use[i][j])
				solve(i, j);
	cout << bestAns << endl;
	return 0;
}