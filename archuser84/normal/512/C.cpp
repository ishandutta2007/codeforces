///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 210;

vector<int> A[N];
int cap[N][N];
const int inf = 1e6;
int n;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, inf});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : A[cur]) {
            if (parent[next] == -1 && cap[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, cap[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int a[N];
vector<vector<int>> ans;

const int M = 20010;
bool prm[M];

bool isprime(int x){
	if(x<2) return 0;
	for(int d = 2; d*d <= x; ++d)
		if(x%d==0) return 0;
	return 1;
}

bool vis[N];

void dfs(int v){
	vis[v]=1;
	ans.back().push_back(v);
	for(int u : A[v])
		if(!vis[u] && (cap[v][u]^(a[u]&1)))
			dfs(u);
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop(i,0,n) cin >> a[i];
	Loop(i,0,M) prm[i] = isprime(i);
	Loop(i,0,n) Loop(j,i+1,n){
		if(prm[a[i]+a[j]]){
			if(a[i]&1) cap[j][i]=1;
			else cap[i][j]=1;
			A[i].push_back(j);
			A[j].push_back(i);
		}
	}
	Loop(i,0,n){
		if(a[i]&1) A[i].push_back(n+1), A[n+1].push_back(i), cap[i][n+1]=2;
		else A[n].push_back(i), A[i].push_back(n), cap[n][i]=2;
	}
	n += 2;
	int x = maxflow(n-2,n-1);
	n -= 2;
	if(x != n) Kill("Impossible");
	vis[n]=vis[n+1]=1;
	Loop(i,0,n)if(!vis[i]){ans.emplace_back();dfs(i);}
	cout << ans.size() << '\n';
	for(auto& v : ans){
		cout << v.size() << ' ';
		for(auto i : v)
			cout << i+1 << ' ';
		cout << '\n';
	}
}