#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

const int DX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int DY[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, m;
string in[N];
vector <bool> Left[N], Right[N];

bool exist(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

int nr(int x, int y){
	return x * m + y - m;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	Left[0].resize(m + 2, false);
	Right[0].resize(m + 2, false);

	for(int i = 1; i <= n; ++i){
		cin >> in[i];
		in[i] = '#' + in[i];

		Left[i].resize(m + 2, false);
		Right[i].resize(m + 2, false);
	}

	Left[n + 1].resize(m + 2, false);
	Right[n + 1].resize(m + 2, false);
	
	Left[1][1] = true;
	Right[n][m] = true;

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			if(in[i][j] == '#')
				continue;
			
			Left[i][j] = Left[i][j] || Left[i - 1][j];
			Left[i][j] = Left[i][j] || Left[i][j - 1];
		}
	
	for(int i = n; i >= 1; --i)
		for(int j = m; j >= 1; --j){
			if(in[i][j] == '#')
				continue;

			Right[i][j] = Right[i][j] || Right[i + 1][j];
			Right[i][j] = Right[i][j] || Right[i][j + 1];
		}
	
	int best = 2;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(i + j == n + m)
				continue;

			if(!Left[i][j] || !Right[i][j])
				continue;

			if(best <= nr(i, j)){
				puts("1");
				exit(0);
			}
			
			if(Right[i + 1][j])
				best = max(best, nr(i + 1, j));
			if(Right[i][j + 1])
				best = max(best, nr(i, j + 1));
		}
	}
	
	if(!Left[n][m]){
		puts("0");
		return 0;
	}
	
	puts("2");
	return 0;
}