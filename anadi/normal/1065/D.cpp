#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 11;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

const int DX[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int DY[] = {-1, 1, -2, 2, -2, 2, -1, 1};

const int DX2[] = {-1, -1, 1, 1, -1, 0, 0, 1};
const int DY2[] = {-1, 1, -1, 1, 0, -1, 1, 0};

struct T{
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, t = 0;
	T(int _x1 = 0, int _y1 = 0, int _x2 = 0, int _y2 = 0, int _t = 0){
		x1 = _x1, y1 = _y1, x2 = _x2, y2 = _y2, t = _t;
	}
	
	void write(){
		printf("TUTAJ %d %d %d %d %d\n", x1, y1, x2, y2, t);
	}
};

PII operator+(PII a, PII b){
	return {a.st + b.st, a.nd + b.nd};
}

int n;
int nr[N][N];
pair <int, int> pl[N * N];
pair <int, int> dist[N][N][N][N][3];

struct cmp{
	bool operator()(T a, T b){
		return dist[a.x1][a.y1][a.x2][a.y2][a.t] > dist[b.x1][b.y1][b.x2][b.y2][b.t];
	}
};

priority_queue <T, vector <T>, cmp> Q;

bool exist(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

void go(T a, T b, PII add){
	if(dist[a.x1][a.y1][a.x2][a.y2][a.t] + add < dist[b.x1][b.y1][b.x2][b.y2][b.t]){
		dist[b.x1][b.y1][b.x2][b.y2][b.t] = dist[a.x1][a.y1][a.x2][a.y2][a.t] + add;
		Q.push(b);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j){
			scanf("%d", &nr[i][j]);
			pl[nr[i][j]] = {i, j};
		}
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			for(int ii = 1; ii <= n; ++ii)
				for(int jj = 1; jj <= n; ++jj)
					for(int t = 0; t < 3; ++t)
						dist[i][j][ii][jj][t] = {MX, MX};
	
	for(int t = 0; t < 3; ++t){
		dist[pl[1].st][pl[1].nd][pl[1].st][pl[1].nd][t] = {0, 0};
		Q.push(T(pl[1].st, pl[1].nd, pl[1].st, pl[1].nd, t));
	}
	
	while(!Q.empty()){
		T cur = Q.top();
//		cur.write();
		Q.pop();
		
		if(pl[nr[cur.x1][cur.y1] + 1] == make_pair(cur.x2, cur.y2))
			go(cur, {cur.x2, cur.y2, cur.x2, cur.y2, cur.t}, {0, 0});

		for(int t = 0; t < 3; ++t)
			go(cur, {cur.x1, cur.y1, cur.x2, cur.y2, t}, {1, 1});
		
		if(cur.t == 0)
			for(int t = 0; t < 8; ++t){
				T b = cur;
				b.x2 += DX[t], b.y2 += DY[t];
				
				if(exist(b.x2, b.y2))
					go(cur, b, {1, 0});
			}
		
		if(cur.t == 1)
			for(int t = 0; t < 4; ++t)
				for(int cnt = 1; true; ++cnt){
					T b = cur;
					b.x2 += cnt * DX2[t], b.y2 += cnt * DY2[t];
					
					if(!exist(b.x2, b.y2))
						break;
					go(cur, b, {1, 0});
				}

		if(cur.t == 2)
			for(int t = 4; t < 8; ++t)
				for(int cnt = 1; true; ++cnt){
					T b = cur;
					b.x2 += cnt * DX2[t], b.y2 += cnt * DY2[t];
					
					if(!exist(b.x2, b.y2))
						break;
					go(cur, b, {1, 0});
				}
	}
	
	PII res = {MX, MX};
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			for(int t = 0; t < 3; ++t)
				res = min(res, dist[pl[n * n].st][pl[n * n].nd][i][j][t]);
	
	printf("%d %d\n", res.st, res.nd);
	return 0;
}