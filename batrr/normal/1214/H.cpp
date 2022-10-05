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

vector< int > g[N];
int n, k, col[N], d1[N], d2[N];
int dp[N], dp2[N];

void DFS(int v, int pr){
	dp[v] = 1;
	for(auto to : g[v]){
		if(to == pr)
			continue;
		DFS(to, v);
		dp[v] = max(dp[v], dp[to] + 1);
	}                                 
}
void DFS2(int v, int pr){
	vector< pii > vv;
	vv.pb({0, 0});
	for(auto to : g[v]){
		if(to == pr)
			vv.pb({dp2[v], v});
		else
			vv.pb({dp[to], to});
	}                        
	
	sort(vv.begin(), vv.end());
	reverse(vv.begin(), vv.end());
	                    
	if(vv.size() >= 4 && vv[1].f + vv[2].f >= k - 1){
		printf("No");
		exit(0);
	}	

	for(auto to : g[v]){
		if(to == pr)
			continue;
		if(vv[0].s == to)         
			dp2[to] = vv[1].f + 1;
		else
			dp2[to] = vv[0].f + 1;
		DFS2(to, v);
	}
}

void f1(int v, int pr){
	d1[v] = d1[pr] + 1;
	for(auto to : g[v])
		if(to != pr)
			f1(to, v);
}
void f2(int v, int pr){
	d2[v] = d2[pr] + 1;
	for(auto to : g[v])
		if(to != pr)
			f2(to, v);
}
void ff(int v, int pr, int x, int y){
	x = (x + y + k) % k;
	col[v] = x;
	for(auto to : g[v])
		if(to != pr)
			ff(to, v, x, y);
}
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i < n; i++){
		int v, u;
		scanf("%d%d", &v ,&u);
		g[v].pb(u);
		g[u].pb(v);
	}
	if(k > 2){
		DFS(1, 1);
		DFS2(1, 1);
	}
	f1(1, 1);
	int A = 1;
	for(int i = 1; i <= n; i++)
		if(d1[i] > d1[A])
			A = i;
	f2(A, A);

	int B = 1;
	for(int i = 1; i <= n; i++)
		if(d2[i] > d2[B])
			B = i;
	int v = B, last = -1;
	while(true){
	    col[v] = d2[v] % k;
	    for(auto to : g[v])
			if(d2[to] > d2[v] && to != last){
				if(d2[v] * 2 > d2[B])
                	ff(to, v, col[v], 1);
				else
					ff(to, v, col[v], k - 1);
			}
		if(v == A)
			break;
		for(auto to : g[v]){
			if(d2[to] < d2[v]){
				last = v;
				v = to;
				break;
			}
	    }
	}

	printf("Yes\n");
	for(int i = 1; i <= n; i++)
		printf("%d ", col[i] + 1);
	return 0;
}