#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 2e4 + 10, maxm = 3e5 + 10;

template<typename T, int N, int M, T inf> struct Flow{
    int tp[N], nxt[2 * M], to[2 * M];
    T c[2 * M];
    int safar = 0;    
    Flow(){
	memset(tp, -1, sizeof tp);
    }
    void reset(){
	safar = 0;
	memset(tp, -1, sizeof tp);
    }
    void add_edge(int a, int b, T w){
	nxt[safar] = tp[a], to[safar] = b, c[safar] = w, tp[a] = safar;
	safar++;
	nxt[safar] = tp[b], to[safar] = a, c[safar] = 0, tp[b] = safar;
	safar++;
    }
    int arr[N], h[N];
    bool bfs(int src, int snk){
	memset(h, -1, sizeof h);
	
	int L = 0, R = 0;
	arr[R++] = src;
	h[src] = 0;
	while(L < R){
	    int u = arr[L++];
	    if(u == snk)
		return 1;
	    for(int id = tp[u]; id != -1; id = nxt[id]){
		if(c[id] != 0 && h[to[id]] == -1)
		    h[to[id]] = h[u] + 1, arr[R++] = to[id];
	    }
	}
	return 0;
    }
    int pt[N];    
    T dfs(int u, int snk, int f){
	if(u == snk)
	    return f;
	T ans = 0;
	for(int &id = pt[u]; id != -1; id = nxt[id]){
	    if(h[u] + 1 == h[to[id]]){
		int x = dfs(to[id], snk, min(f - ans, c[id]));
		c[id]-= x;
		c[id ^ 1]+= x;
		ans+= x;
		if(ans == f)
		    break;
	    }
	}
	return ans;
    }
    T flow(int src, int snk){
	T ans = 0;
	while(bfs(src, snk)){
	    memcpy(pt, tp, sizeof pt);
	    ans+= dfs(src, snk, inf);
	}
	return ans;
    }
};
Flow<int, maxn, maxm, int(1e9)> flw;

pair<int, pii> p[maxm];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
	cin >> p[i].S.F >> p[i].S.S >> p[i].F;
	--p[i].S.F, --p[i].S.S;
    }
    sort(p, p + m);

    int src = n + n, snk = src + 1;
    
    int l = 0, r = m + 1;
    while(r-l > 1){
	int mid = (l+r) >> 1;
	flw.reset();
	for(int i = 0; i < mid; i++){
	    flw.add_edge(p[i].S.F, n + p[i].S.S, 1);	    
	}
	for(int i = 0; i < n; i++){
	    flw.add_edge(src, i, 1);
	    flw.add_edge(n + i, snk, 1);	    
	}
	if(flw.flow(src, snk) == n)
	    r = mid;
	else
	    l = mid;	
    }
    if(r == m + 1)
	cout << -1 << endl;
    else
	cout << p[r - 1].F << endl;
    return 0;
}