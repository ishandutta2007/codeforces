#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2007;
const int MX = 998244353;

int n;
int in[N][N];

int np[N];
int sil[N];
int suf[N];
int dp[N][N];

int getSil(){
	int ret = 0;
	vector <bool> is(n + 1, true);

	for(int i = 1; i <= n; ++i){
		int pl = 0;
		for(int j = 1; j < in[1][i]; ++j)
			pl += is[j];
		
		is[in[1][i]] = false;
		ret = (ret + 1LL * pl * sil[n - i]) % MX;
	}
	
	return ret;
}

const int T = 1 << 11;

int tree[2][T + T + 7];

void add(int t, int p, int v){
	p += T;
	while(p){
		tree[t][p] += v;
		p >>= 1;
	}
}

int ask(int t, int from, int to){
	int ret = 0;
	from += T, to += T;

	while(from <= to){
		if(from & 1)
			ret += tree[t][from];
		if(!(to & 1))
			ret += tree[t][to];
		
		from = (from + 1) / 2;
		to = (to - 1) / 2;
	}
	
	return ret;
}

int getId(int row){
	int ret = 0;
	vector <int> is(n + 1, 1);
	
	for(int i = 0; i < T + T; ++i)
		tree[0][i] = tree[1][i] = 0;
	
	for(int i = 1; i <= n; ++i)
		add(1, i, 1);
	
	for(int i = 1; i <= n; ++i){
		int prv = in[row - 1][i];
		int cur = in[row][i];

		if(is[prv] != -1){
			is[prv] = 0;
			add(1, prv, -1);
			add(0, prv, 1);
		}
		
		int cnt = ask(1, 1, n);
		int sub = ask(1, 1, cur - 1);
		int eq = ask(0, 1, cur - 1);
		
		if(is[prv] != -1 && prv < cur)
			eq--;
		
		if(cnt > 0)
			ret = (ret + 1LL * sub * dp[n - i][cnt - 1]) % MX;
		ret = (ret + 1LL * eq * dp[n - i][cnt]) % MX;
		
		add(is[cur], cur, -1);
		is[cur] = -1;
	}
	
	return ret;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			scanf("%d", &in[i][j]);
	
	np[0] = 1, np[1] = 0;
	for(int i = 2; i <= n; ++i)
		np[i] = (1LL * (i - 1) * (np[i - 1] + np[i - 2])) % MX;
	
	sil[0] = 1;
	for(int i = 1; i <= n; ++i)
		sil[i] = (1LL * sil[i - 1] * i) % MX;
	
	suf[0] = 1;
	for(int i = 1; i <= n; ++i)
		suf[i] = (1LL * suf[i - 1] * np[n]) % MX;
	
	dp[0][0] = 1;
	for(int i = 1; i <= n; ++i){
		dp[i][i] = np[i];
		for(int j = i - 1; j >= 0; --j)
			dp[i][j] = (dp[i][j + 1] + dp[i - 1][j]) % MX;
		assert(dp[i][0] == sil[i]);
	}
	
	int ans = (1LL * suf[n - 1] * getSil()) % MX;
	for(int i = 2; i <= n; ++i)
		ans = (ans + 1LL * getId(i) * suf[n - i]) % MX;
	printf("%d\n", ans);
	return 0;
}