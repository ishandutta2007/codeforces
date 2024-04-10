#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, m, a[15][2100], val[15], mx[1 << 15], dp[1 << 15], nxt[1 << 15];
void add(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < (1 << n); j++){
			int cur = 0;
			for(int q = 0; q < n; q++)
				if((j >> q) & 1)
					cur += val[(i + q) % n];		
			mx[j] = max(mx[j], cur);
		}
	}
	for(int i = 0; i < (1 << n); i++)
		for(int j = 0; j < (1 << n); j++)
			if((i & j) == 0)
				nxt[i | j] = max(nxt[i | j], dp[i] + mx[j]);
	for(int i = 0; i < (1 << n); i++)
		dp[i] = nxt[i], nxt[i] = mx[i] = 0;
}

int main()
{
	int t;                    	
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				scanf("%d", &a[i][j]);
		for(int j = 0; j < m; j++){
			for(int i = 0; i < n; i++)
				val[i] = a[i][j];
			add();	
		}
		printf("%d\n", dp[(1 << n) - 1]); 
		for(int i = 0; i < (1 << n); i++)
			dp[i] = 0;
	}
	return 0;
}