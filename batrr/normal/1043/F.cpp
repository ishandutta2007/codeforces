#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)3e5 + 123, inf = 1e9;
const ll INF = 1e18;

vector< int > vd[N];
int n, a[N], g, ans = 1e9, M;
int cnt[N];
bool was[N];
int get(int x){              
	int m = vd[x].size();

	vector< int > cur((1<<m)), dp((1<<m), inf);
	for(int mask = 0; mask < (1 << m); mask++){
		int val = 1;
		for(int j = 0; j < m; j++)
			if(mask & (1<<j))
				val *= vd[x][j];
		cur[mask] = cnt[val];
	}
	for(int i = 0; i < m; i++)
		for(int j = 0; j < (1<<m); j++)
			if((j & (1<<i)) == 0)
            	cur[j] -= cur[j + (1<<i)];
    for(int i = 0; i < m; i++)
		for(int j = 0; j < (1<<m); j++)
			if((j & (1<<i)) == 0)
            	cur[j + (1<<i)] += cur[j];
	dp[(1<<m) - 1] = 1;
	for(int i = (1<<m) - 1; i > 0; i--)
		for(int j = i; j > 0; j = (j - 1) & i)
			if(cur[j ^ ((1<<m) - 1)] > 0)
            	dp[j ^ i] = min(dp[j ^ i], dp[i] + 1);	
	return dp[0];
}
int main(){
	for(int i = 2; i < N; i++)
		if(vd[i].empty())
			for(int j = i; j < N; j += i)
				vd[j].pb(i);
	a[1] = 1;
	for(int i = 2; i < N; i++){
		int x = i;
		int y = vd[i][0];
		while(x % y == 0)
			x /= y;
		a[i] = y * a[x];
		if(a[i] == i)
			M++;
	}
	
	/*
	cerr << M * 6 * (1<<6) / 1e8 << endl;
	M = 0;
	for(int i = 1; i < N; i++){
		int x = vd[i].size();
		if(a[x] == x)
        	M += x * (1<<x) + (1 << x) * (1 << x);
	}
	cerr << M / 1e8 << endl;
	*/
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
	    int x;
		scanf("%d", &x);
		x = a[x];
		if(was[x])
			continue;
		was[x] = 1;
		if(g == 0)
			g = x;
        else
        	g = __gcd(x, g);
        int m = vd[x].size();
		for(int mask = 0; mask < (1 << m); mask++){
			int val = 1;
			for(int j = 0; j < m; j++)
				if(mask & (1<<j))
					val *= vd[x][j];
			cnt[val]++;
		}
	}
	if(g != 1){
		printf("-1");
		return 0;   	
	}
	for(int i = 1; i < N; i++)
		if(was[i])
        	ans = min(ans, get(i)); 
	printf("%d", ans);
	return 0;
}