#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 200500, K = 450;


vector< int > g[N], G[N], gg[N];
int n, k, q, ms[N], dp0[N], dp1[N], mxk[N], pr[N], type[N], a[N], b[N], c[N];
bool leaf[N];
void dfs(int v, int p){
	pr[v] = p;
	for(auto to : g[v])
		if(to != p)
			dfs(to, v);
}
void dfsm(int v){
	int cnt = (ms[v] != -1);
	for(auto to : g[v])
		if(to != pr[v]){
			dfsm(to);
			if(ms[to] == -1)
				continue;
			ms[v] = ms[to];
			cnt++;
		}
	if(cnt > 1)
		ms[v] = v;
	if(ms[v] == v){
		for(auto to : g[v])
			if(to != pr[v]){
				if(ms[to] != -1)
                	G[v].pb(to);
				else{
					if(leaf[to]){
						if(c[to])          
							gg[v].pb(n + 10);
						else
							gg[v].pb(-n - 10);
					}else{
						gg[v].pb(mxk[to]);
					}
				}
			}
		sort(gg[v].begin(), gg[v].end());
	}else if(ms[v] == -1){
		if(!leaf[v]){
    		int bl = - n - n - 10 + N, br = n + n + 10 + N;
    		while(bl <= br){
    			int m = (bl + br) / 2 - N;
    			int r = 0, b = 0;
    			for(auto to : g[v]){
					if(to != pr[v]){
						if(leaf[to]){
							if(c[to] == 1)
								b++;
							else
								r++;
					    }else{
					    	if(mxk[to] >= m)
					    		b++;
							else
								r++;
					    }
					}
				}
				if(b - r >= m)
					bl = m + 1 + N;
				else
					br = m - 1 + N;
			}
			mxk[v] = bl - 1 - N;
		}
	}else{
		{
			int bl = - n - n - 10 + N, br = n + n + 10 + N;
    		while(bl <= br){
    			int m = (bl + br) / 2 - N;
    			int r = 0, b = 0;
    			for(auto to : g[v]){
					if(to != pr[v]){
						if(ms[to] == -1){
							if(leaf[to]){
								if(c[to] == 1)
									b++;
								else
									r++;
					    	}else{
					    		if(mxk[to] >= m)
					    			b++;
								else
									r++;
					    	}
					    }else{
					    	if(ms[v] == to){
					    		r++;
					    	}else{
								if(dp0[to] >= m)
									b++;
								else
									r++;					    	
					    	}
					    }
					}
				}
				if(b - r >= m)
					bl = m + 1 + N;
				else
					br = m - 1 + N;
			}
			dp0[v] = bl - 1 - N;
		}			
		{
			int bl = - n - n - 10 + N, br = n + n + 10 + N;
    		while(bl <= br){
				int m = (bl + br) / 2 - N;
				int r = 0, b = 0;
    			for(auto to : g[v]){
					if(to != pr[v]){
						if(ms[to] == -1){
							if(leaf[to]){
								if(c[to] == 1)
									b++;
								else
									r++;
					    	}else{
					    		if(mxk[to] >= m)
					    			b++;    
								else
									r++;
					    	}
					    }else{
					    	if(ms[v] == to){
					    		b++;
					    	}else{
								if(dp1[to] >= m)
									b++;
								else
									r++;					    	
					    	}
					    }
					}
				}
				if(b - r >= m)
					bl = m + 1 + N;
				else
					br = m - 1 + N;
			}
			dp1[v] = bl - 1 - N;
		}			
	}
}
int get(int v){
	if(leaf[v]){
		return c[v];
	}
	int b = 0, r = 0;
	int ind = lower_bound(gg[v].begin(), gg[v].end(), k) - gg[v].begin();
	r += ind;
	b += gg[v].size() - ind;
	for(auto to : G[v]){
		int val = get(ms[to]);
		if(val == 0){
			if(ms[to] == to){
				r++;
			}else{
				if(dp0[to] >= k)
					b++;
				else
					r++;
			}
		}else{
			if(ms[to] == to){
				b++;
			}else{
				if(dp1[to] >= k)
					b++;
				else
					r++;
			}
		}
	}
	return b - r >= k;
}
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i < n; i++){
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}	
	dfs(1, 0);
	for(int i = 1; i <= n; i++){
		scanf("%d", &c[i]);
		if(c[i] != -1)
			leaf[i] = 1;
	}
	scanf("%d", &q);
	while(q){
		int cnt = min(q, K);
		q -= cnt;		
		for(int i = 0; i < cnt; i++){
			scanf("%d", &type[i]); 
			if(type[i] == 2)
				scanf("%d%d", &a[i], &b[i]);
			else
				scanf("%d", &a[i]);
		}
		for(int i = 1; i <= n; i++){
			ms[i] = -1;
			G[i].clear();
			gg[i].clear();
		}

		for(int i = 0; i < cnt; i++)
			if(type[i] != 3)
				ms[a[i]] = a[i];
        dfsm(1);
		for(int i = 0; i < cnt; i++){
			if(type[i] == 3)
				k = a[i];
			if(type[i] == 2)
				c[a[i]] = b[i];
			if(type[i] == 1)
				printf("%d\n",get(a[i]));
		}
	}
	return 0;
}