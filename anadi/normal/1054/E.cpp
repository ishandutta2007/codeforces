#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 307;
const int M = 1e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
char s[M];
int cnt[N][2];
string ini[N][N];
//string cur[N][N];
string final[N][N];
vector <pair <PII, PII> > res;

int roz[N][N];
inline void add(int x1, int y1, int x2, int y2){
//	assert(cur[x1][y1].size() > 0);
//	reverse(cur[x2][y2].begin(), cur[x2][y2].end());
//	cur[x2][y2].push_back(cur[x1][y1].back());
//	cur[x1][y1].pop_back();
//	reverse(cur[x2][y2].begin(), cur[x2][y2].end());

	roz[x1][y1]--; roz[x2][y2]++;
	res.push_back({{x1, y1}, {x2, y2}});
}

/*void write(){
	puts("WYPISUJE");
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j)
			cout << cur[i][j] << " " ;
		cout << "\n";
	}
}*/

void solveFirst(){
	reverse(ini[n][1].begin(), ini[n][1].end());
	while(roz[1][1]){
		add(1, 1, n, 1);
		ini[n][1].push_back(ini[1][1].back());
		ini[1][1].pop_back();
	}

	while(roz[n][m]){
		add(n, m, n, 1);
		ini[n][1].push_back(ini[n][m].back());
		ini[n][m].pop_back();
	}
	
//	write();
	reverse(ini[n][1].begin(), ini[n][1].end());
	for(int i = 1; i <= n; ++i){
//		write();
		if(1 < i){
			if(i < n)
				reverse(ini[i][m].begin(), ini[i][m].end());

			for(int j = ini[i][1].size() - 1; j >= 0; --j)
				if(ini[i][1][j] == '1')
					add(i, 1, 1, 1);
				else{
					add(i, 1, i, m);
					if(i < n)
						ini[i][m].push_back('0');
				}
			
			if(i < n)
				reverse(ini[i][m].begin(), ini[i][m].end());
		}
		
		if(i < n){
			for(int j = ini[i][m].size() - 1; j >= 0; --j)
				if(ini[i][m][j] == '1'){
					add(i, m, i, 1);
					if(1 < i)
						add(i, 1, 1, 1);
				}
				else
					add(i, m, n, m);
		}
		
//		write();
		for(int j = 2; j < m; ++j){
			int t = ini[i][j].size();
			for(int ii = t - 1; ii >= 0; --ii){
				if(ini[i][j][ii] == '0'){
					add(i, j, i, m);
					if(i < n)
						add(i, m, n, m);
				}
				else{
					add(i, j, i, 1);
					if(1 < i)
						add(i, 1, 1, 1);
				}
			}
		}
	}
}

void solve(int x, int y){
	for(int t = final[x][y].size() - 1; t >= 0; --t)
		if(final[x][y][t] == '0'){
			if(x < n)
				add(n, m, x, m);
			if(y < m)
				add(x, m, x, y);
		}
		else{
			if(1 < x)
				add(1, 1, x, 1);
			if(1 < y)
				add(x, 1, x, y);
		}
}

void get(int x, int y){
	for(int t = final[x][y].size() - 1; t >= 0; --t)
		if(final[x][y][t] == '0'){
			if(y < m)
				add(n, m, n, y);
			add(n, y, x, y);
		}
		else{
			if(1 < y)
				add(1, 1, 1, y);
			add(1, y, x, y);
		}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			scanf("%s", s + 1);
			int _n = strlen(s + 1);
			
			roz[i][j] = _n;
			for(int ii = 1; ii <= _n; ++ii)
				ini[i][j].push_back(s[ii]);
//			cur[i][j] = ini[i][j];
		}

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			scanf("%s", s + 1);
			int _n = strlen(s + 1);
			
			for(int ii = 1; ii <= _n; ++ii)
				final[i][j].push_back(s[ii]);
		}
	
	solveFirst();	
	for(int i = 2; i < m; ++i)
		solve(1, i), solve(n, i);

	for(int i = 2; i < n; ++i){
		for(int j = 2; j < m; ++j)
			solve(i, j);

		get(i, 1);
		get(i, m);
	}
	
	for(int t = final[1][m].size() - 1; t >= 0; --t)
		if(final[1][m][t] == '0')
			add(n, m, 1, m);
		else
			add(1, 1, 1, m);
	
	for(int t = final[1][1].size() - 1; t >= 0; --t)
		if(final[1][1][t] == '0')
			add(n, m, n, 1);
		else
			add(1, 1, n, 1);

	for(int t = final[n][m].size() - 1; t >= 0; --t)
		if(final[n][m][t] == '0')
			add(n, m, n, 1);
		else
			add(1, 1, n, 1);

	for(int t = final[n][1].size() - 1; t >= 0; --t)
		if(final[n][1][t] == '0')
			add(n, m, n, 1);
		else
			add(1, 1, n, 1);
	
	for(auto v: final[1][1])
		add(n, 1, 1, 1);
	
	for(auto v: final[n][m])
		add(n, 1, n, m);
	
//	write();	
	printf("%d\n", res.size());
	for(auto v: res)
		printf("%d %d %d %d\n", v.st.st, v.st.nd, v.nd.st, v.nd.nd);
	return 0;
}