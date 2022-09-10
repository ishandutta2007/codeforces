#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define mp make_pair
#define st first
#define nd second
#define PII pair <int, int>
#define PLL pair <LL, LL>
#define pb push_back

const int mxn = 1e3 + 7;

int n, m;
int d[4 * mxn * mxn];
char s[mxn][mxn];
PII S, M;
bool V[4 * mxn * mxn][4];

void change(int a, int b){
	if(s[a][b] == '+' || s[a][b] == '*')
		return;
	if(s[a][b] == '-'){
		s[a][b] = '|';
		return ;
	}
	if(s[a][b] == '|'){
		s[a][b] = '-';
		return;
	}
	
	if(s[a][b] == 'L'){
		s[a][b] = 'U';
		return;
	}
	
	if(s[a][b] == 'R'){
		s[a][b] = 'D';
		return;
	}

	if(s[a][b] == 'U'){
		s[a][b] = 'R';
		return;
	}

	if(s[a][b] == 'D'){
		s[a][b] = 'L';
		return;
	}

	if(s[a][b] == '^'){
		s[a][b] = '>';
		return;
	}

	if(s[a][b] == '>'){
		s[a][b] = 'v';
		return;
	}

	if(s[a][b] == 'v'){
		s[a][b] = '<';
		return;
	}

	if(s[a][b] == '<'){
		s[a][b] = '^';
		return;
	}
}

bool down(int a, int b){
	return s[a][b] == '+' || s[a][b] == 'L' || s[a][b] == 'R' || s[a][b] == 'U' || s[a][b] == 'v' || s[a][b] == '|';
}

bool up(int a, int b){
	return s[a][b] == '+' || s[a][b] == 'L' || s[a][b] == 'R' || s[a][b] == 'D' || s[a][b] == '^' || s[a][b] == '|';
}

bool left(int a, int b){
	return s[a][b] == '+' || s[a][b] == 'D' || s[a][b] == 'R' || s[a][b] == 'U' || s[a][b] == '<' || s[a][b] == '-';
}

bool right(int a, int b){
	return s[a][b] == '+' || s[a][b] == 'L' || s[a][b] == 'D' || s[a][b] == 'U' || s[a][b] == '>' || s[a][b] == '-';
}

void bfs(int u){
	queue <int> Q;
	Q.push(u);
	int ver = n * m;
	for(int i = 1; i <= 4 * ver; ++i)
		d[i] = -1;
	d[u] = 0;

	while(!Q.empty()){
		int k = Q.front();
		Q.pop();
		
		if(d[k + m] == -1 && V[k][0]){
			d[k + m] = d[k] + 1;
			Q.push(k + m);
		}

		if(d[k + 1] == -1 && V[k][1]){
			d[k + 1] = d[k] + 1;
			Q.push(k + 1);
		}

		if(d[k - 1] == -1 && V[k][2]){
			d[k - 1] = d[k] + 1;
			Q.push(k - 1);
		}

		if(d[k - m] == -1 && V[k][3]){
			d[k - m] = d[k] + 1;
			Q.push(k - m);
		}
		
		if(k + ver <= 4 * ver && d[k + ver] == -1){
			d[k + ver] = d[k] + 1;
			Q.push(k + ver);
		}
		
		if(k + ver > 4 * ver && d[k - 3 * ver] == -1){
			d[k - 3 * ver] = d[k] + 1;
			Q.push(k - 3 * ver);
		}
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);
	
	scanf("%d %d", &S.st, &S.nd);
	scanf("%d %d", &M.st, &M.nd);
		
	int ver = n * m;
	for(int k = 0; k < 4; ++k){
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j){
				int nr = (i - 1) * m + j + k * ver;
				if(i < n && down(i, j) && up(i + 1, j))
					V[nr][0] = true;

				if(j < m && right(i, j) && left(i, j + 1))
					V[nr][1] = true;

				if(j > 1 && left(i, j) && right(i, j - 1))
					V[nr][2] = true;

				if(i > 1 && up(i, j) && down(i - 1, j))
					V[nr][3] = true;
			}
		
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				change(i, j);
	}
	
	bfs((S.st - 1) * m + S.nd);
	
	int nr = M.st * m + M.nd - m;	
	int who = nr;
	for(int i = 0; i < 4; ++i)
		if(d[nr + i * ver] < d[who])
			who = nr + i * ver;
	
	printf("%d\n", d[who]);
	return 0;
}