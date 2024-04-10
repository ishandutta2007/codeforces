#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 10;
const int M = 100;
const int DX[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int DY[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int n;
PII prv[10][10];
bool ok[10][10];
bool knight[10][10];
vector <pair <PII, PII> > res;

bool exist(int x, int y){
	return 1 <= x && x <= 8 && 1 <= y && y <= 8;
}

void Move(PII x, PII y){
	assert(exist(x.st, x.nd) && exist(y.st, y.nd) && abs(x.st - y.st) + abs(x.nd - y.nd) == 3 && x.st != y.st && x.nd != y.nd && knight[x.st][x.nd] && !knight[y.st][y.nd]);
	res.push_back({x, y});

	knight[x.st][x.nd] = false;
	knight[y.st][y.nd] = true;
}

void Find(int x, int y, int tx, int ty){
	vector <PII> Pos;
	Pos.push_back({x, y});

	while(x != tx || y != ty){
		int cx = prv[x][y].st;
		int cy = prv[x][y].nd;
		
		x = cx, y = cy;
		Pos.push_back({x, y});
	}
	
	reverse(Pos.begin(), Pos.end());
	for(int i = 0; i + 1 < (int)Pos.size(); ++i)
		Move(Pos[i], Pos[i + 1]);
}

void change(int tx, int ty){
	queue <PII> Q;
	for(int i = 1; i <= 8; ++i)
		for(int j = 1; j <= 8; ++j)
			prv[i][j] = {0, 0};

//	puts("BFSIK");
	for(int i = 1; i <= 8; ++i)
		for(int j = 1; j <= 8; ++j)
			if(!ok[i][j] && knight[i][j]){
				Q.push({i, j});
				prv[i][j] = {i, j};
//				printf("%d %d\n", i, j);
			}
	
	while(!Q.empty()){
		PII t = Q.front();
		Q.pop();
		
		for(int i = 0; i < 8; ++i){
			int nx = t.st + DX[i], ny = t.nd + DY[i];
			if(exist(nx, ny) && prv[nx][ny] == make_pair(0, 0)){
				Q.push({nx, ny});
				prv[nx][ny] = {t.st, t.nd};
			}
		}
	}
	
	assert(prv[tx][ty] != make_pair(0, 0));
	PII last = {tx, ty};
	
	while(prv[tx][ty] != make_pair(tx, ty)){
		int nx = prv[tx][ty].st;
		int ny = prv[tx][ty].nd;
		
		if(knight[nx][ny]){
			Find(last.st, last.nd, nx, ny);
			last = {nx, ny};
		}

		tx = nx, ty = ny;
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		char s[10];
		scanf("%s", s);
		knight[s[0] - 'a' + 1][s[1] - '0'] = true;
	}
	
	
	for(int i = 1; i <= 9; ++i){
		for(int j = 1; j <= 8; ++j){
			if(n == 0){
				printf("%d\n", (int)res.size());
				for(auto v: res)
					printf("%c%c-%c%c\n", 'a' + v.st.st - 1, '0' + v.st.nd, 'a' + v.nd.st - 1, '0' + v.nd.nd);
				exit(0);
			}

			n--;
			change(j, i);
			ok[j][i] = true;
		}
	}
	
	assert(false);
	return 0;
}