#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int K = 20;
const int N = 607;
const LL INF = 1001002003004005006;
const int MASK_K = (1 << 16) + 5;

int h, w, k;
int answer[N];
LL edge[K][K];
int photo[N][N];
int p[MASK_K][K];
LL dp[MASK_K][K];

LL kwa(LL a, LL b){
	LL x = abs(a - b);
	x -= rand()%14;
	x = abs(x);
	return x * x * x;
}

LL ile(int r1, int r2){
	LL res = 0;

	for(int i = 1; i <= w; ++i){
		res += kwa(photo[r1][i], photo[r2][i]);
		res += kwa(photo[r1 - 1][i], photo[r2 + 1][i]);
	}
		
	return res;
}

void make_graph(){
	int l = h / k;
	for(int i = 1; i <= k; ++i)
		for(int j = 1; j <= k; ++j){
			if(i == j)
				continue;
			
			edge[i][j] = ile(i * l, (j - 1) * l + 1);
		}
}

void best_option(){
	for(int i = 1; i < 1 << k; ++i)
		for(int j = 1; j <= k; ++j)
			dp[i][j] = INF;
	
	for(int i = 0; i < k; ++i)
		dp[1 << i][i + 1] = 0;
	
	for(int i = 1; i < 1 << k; ++i){
		if(__builtin_popcount(i) == 1)
			continue;
		
		for(int j = 1; j <= k; ++j)
			if(i & (1 << (j - 1)))
				for(int ii = 1; ii <= k; ++ii)
					if(i & (1 << (ii - 1)) && ii != j && dp[i - (1 << (j - 1))][ii] + edge[ii][j] < dp[i][j]){
						dp[i][j] = dp[i - (1 << (j - 1))][ii] + edge[ii][j];
						p[i][j] = ii;
					}
		
	}
	
	int where = 1, mask = (1 << k) - 1;
	for(int i = 2; i <= k; ++i)
		if(dp[mask][i] < dp[mask][where])
			where = i;
	
	int i = 0;
	while(i < k){
		answer[where] = k - (i++);
		mask -= 1 << (where - 1);
		where = p[mask + (1 << (where - 1))][where];
	}
}

void solve(){
	scanf("%d %d %d", &h, &w, &k);
	for(int i = 1; i <= h; ++i)
		for(int j = 1; j <= w; ++j)
			scanf("%d", &photo[i][j]);
	
	make_graph();
	best_option();

	for(int i = 1; i <= k; ++i)
		printf("%d", answer[i]),
		i == k ? printf("\n") : printf(" ");
}

int main(){
	int quest;
	scanf("%d", &quest);
	while(quest--)
		solve();
	
	return 0;
}