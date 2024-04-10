#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 32;
const int MX = 1e9 + 7;
const int inf  = 1e9 + 9;

int n;
int strength[N];
bool is[2 * N][2 * N];
int p[N][2 * N][2 * N * N];
bool dp[N][2 * N][2 * N * N];

void solve(vector <PII> cur){
	if(cur.size() == 0)
		return;
	sort(cur.begin(), cur.end());
	
	for(int i = 0; i + 1 < (int)cur.size(); ++i)
		if(i < cur[cur.size() - 1].st)
			is[cur[cur.size() - 1].nd][cur[i].nd] = true;
		else
			is[cur[i].nd][cur[cur.size() - 1].nd] = true,
			cur[i].st--;
	cur.pop_back();
	
	solve(cur);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &strength[i]);
	sort(strength + 1, strength + n + 1);
	
	dp[0][0][0] = true;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= 2 * strength[i] + 1; ++j)
			for(int k = j * (j - 1) / 2; k <= j * strength[i]; ++k){
				int curS = k, cnt = 0;
				for(int ii = 1; ii <= j - i + 1; ++ii){
					curS -= strength[i], ++cnt;
					if(curS < (j - cnt) * (j - cnt - 1) / 2)
						break;

					if(dp[i - 1][j - ii][curS]){
						dp[i][j][k] = true;
						p[i][j][k] = ii;
						break;
					}
				}
			}
	
	int curN = n, curV = -1, curS = -1;
	for(int i = n; i <= 2 * strength[n] + 1; ++i)
		if(dp[n][i][i * (i - 1) / 2]){
			curV = i, curS = i * (i - 1) / 2;
			break;
		}
	
	if(curV == -1){
		puts("=(");
		return 0;
	}
	
	int licz = 0;
	vector <PII> d;
	while(curN > 0){
		for(int i = 0; i < p[curN][curV][curS]; ++i)
			d.pb({strength[curN], ++licz});
		int cnt = p[curN][curV][curS];
		
		curN--;
		curV -= cnt;
		curS -= strength[curN + 1] * cnt;
	}
	
	printf("%d\n", licz);
	solve(d);
	
	for(int i = 1; i <= licz; ++i){
		for(int j = 1; j <= licz; ++j)
			printf("%d", is[i][j]);
		puts("");
	}

	return 0;
}