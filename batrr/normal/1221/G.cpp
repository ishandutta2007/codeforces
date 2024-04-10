#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int K = 20;


int n, m, bt[1 << K], col[50], cnt, cntz, sz;
ll g[50], dp[8], dd[8], tmp[8], comp, ans;
bool was[50];
bool BI = 1;
void dfs(int v, int curcol = 0){	
	if(was[v]){
		if(col[v] != curcol)
			BI = 0;
		return;
	}
	was[v] = 1;	
	col[v] = curcol;
	sz++;
	comp |= (1ll << v);
	for(int to = 0; to < n; to++)
		if((g[v] >> to) & 1)
			dfs(to, col[v] ^ 1);
}
ll bb(ll mask){
    //for(int i = 0;; i++)
    //	if((mask >> i) & 1)
    //		return i;
	return min(bt[mask & ((1 << K) - 1)], bt[mask >> K] + K);
}
ll fa(ll mask){
	if(mask == 0)
		return 1;
	int v = bb(mask);
	mask ^= (1ll << v);
	ll msk = (g[v] & mask);
	if(msk == 0)
		return fa(mask) * 2;
	return fa(mask ^ msk) + fa(mask); 
}


int main()
{
	for(int i = 0; i < (1 << K); i++){
		bt[i] = 100;
		for(int j = 0; j < K; j++)
			if((i >> j) & 1)
				bt[i] = min(bt[i], j);
	}
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		--v, --u;
		g[v] |= (1ll << u);
		g[u] |= (1ll << v);
	}
	dp[0] = 1;
    for(int i = 0; i < n; i++)
    	if(!was[i]){
    		sz = 0;
    		comp = 0;
    		BI = 1;
    		dfs(i);
    		if(sz == 1){
    			for(int i = 0; i < 8; i++)
    				dp[i] *= 2;
				continue;
    		}
    		ll res = fa(comp);
    		tmp[0] = 0;
    		tmp[1] = 1;
    		tmp[2] = BI * 2;
    		tmp[3] = res;
    		tmp[4] = 1;
    		tmp[5] = 2;
    		tmp[6] = res;
    		tmp[7] = (1ll << sz);
    		for(int i = 0; i < 8; i++)
    			for(int j = 0; j < i; j++)
    				if((i | j) == i)
    					tmp[i] -= tmp[j];
    		
    		for(int i = 0; i < 8; i++)
    			for(int j = 0; j < 8; j++)
    				dd[i | j] += dp[i] * tmp[j];
    		
            
            for(int i = 0; i < 8; i++)
    			dp[i] = dd[i], dd[i] = 0;		
    		
		}
	cout << dp[7] << endl;	
	return 0;
}