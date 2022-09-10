#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PII pair <int, int>

const int N = 2507;

int n, m;
char s[N][N];
int pref[N][N];

inline int ile(int x1, int y1, int k){
	int x2 = min(n, x1 + k - 1), y2 = min(m, y1 + k - 1);
	int cnt = pref[x2][y2] + pref[x1 - 1][y1 - 1] - pref[x2][y1 - 1] - pref[x1 - 1][y2];
	return min(cnt, k * k - cnt);
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);
	
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + s[i][j] - '0';
	
	int to = max(n, m);
	int res = 4 * to * to;
	for(int i = 2; i <= to; ++i){
		int cnt = 0;
		for(int j = 1; j <= n; j += i)
			for(int ii = 1; ii <= m; ii += i)
				cnt += ile(j, ii, i);
		res = min(res, cnt);
	}

	printf("%d\n", res);
	return 0;
}