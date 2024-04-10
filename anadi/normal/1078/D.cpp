#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 3e5 + 7;
const int T = 1 << 19;

const int LOGN = 18;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
int val[N];
int tree[2][LOGN][T + T + 7];
int Left[LOGN][N], Right[LOGN][N];

void update(int t, int p, int x, int v){
	x += T;
	tree[t][p][x] = v;
	
	while(x > 1){
		x >>= 1;
		tree[t][p][x] = min(tree[t][p][x + x], tree[t][p][x + x + 1]);
	}
}

int ask(int t, int p, int from, int to){
	int ret = N;
	from += T, to += T;
	
	while(from < to){
		if(from & 1)
			ret = min(ret, tree[t][p][from]);
		if(!(to & 1))
			ret = min(ret, tree[t][p][to]);
		
		from = (from + 1) >> 1;
		to = (to - 1) >> 1;
	}
	
	if(from == to)
		ret = min(ret, tree[t][p][from]);
	return ret;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &val[i]);
		val[n + i] = val[n + n + i] = val[i];
	}
	
	m = 3 * n;
	for(int i = 1; i <= m; ++i){
		Left[0][i] = max(1, i - val[i]),
		Right[0][i] = min(m, i + val[i]);
		
		update(0, 0, i, Left[0][i]);
		update(1, 0, i, -Right[0][i]);
	}
	
	for(int i = 1; i < LOGN; ++i){
		for(int j = 1; j <= m; ++j){
			Left[i][j] = ask(0, i - 1, Left[i - 1][j], Right[i - 1][j]);
			Right[i][j] = -ask(1, i - 1, Left[i - 1][j], Right[i - 1][j]);
			
			update(0, i, j, Left[i][j]);
			update(1, i, j, -Right[i][j]);
		}
	}
	
	for(int i = n + 1; i <= n + n; ++i){
		int from = i, to = i;
		int ans = 0;
		
		for(int j = LOGN - 1; j >= 0; --j){
			int nfrom = ask(0, j, from, to);
			int nto = -ask(1, j, from, to);
			
			if(nto - nfrom < n - 1){
				from = nfrom, to = nto;
				ans += 1 << j;
			}
		}
		
		if(to - from < n - 1)
			++ans;
		printf("%d ", ans);
	}

	return 0;
}