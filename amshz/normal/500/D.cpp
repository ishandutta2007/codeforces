# include <bits/stdc++.h>

using namespace std;

typedef long long ll;

# define F first
# define S second

const int xn = 1e5+10;

vector <int> adj[xn];
bool mark[xn];

int a[xn], b[xn], h[xn];
long double c[xn], dp[xn];
pair <int, long double> q[xn];
map < pair <int, int> , long double> w;

void DFS(int v, int e){
	mark[v] = true;
	h[v] = e;
	for (int i=0; i<adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		DFS(u, e+1);
		dp[v] += dp[u];
	}
	dp[v]++;
}

int main(){
	long double n;
	cin >> n;
	for (int i=0; i<n-1; i++)
		cin >> a[i] >> b[i] >> c[i], adj[a[i]].push_back(b[i]), adj[b[i]].push_back(a[i]), w[{a[i], b[i]}] = c[i], w[{b[i], a[i]}] = c[i];
	int tq;
	cin >> tq;
	for (int i=0; i<tq; i++) cin >> q[i].F >> q[i].S;
	DFS(1, 0);
	long 
	double s = 0;
	for (int i=0; i<n-1; i++){
		int v = a[i], u = b[i];
		if (h[v] < h[u]) swap(v, u);
		s += c[i]*dp[v]*(n-dp[v]);
	}
	s *= 6;
	s /= (n*(n-1));
	//cout << s << endl;
	for (int i=0; i<tq; i++){
		int v = a[q[i].F-1], u = b[q[i].F-1];
		if (h[v] < h[u]) swap(v, u);
		s -= (6*(c[q[i].F-1]-q[i].S)*dp[v]*(n-dp[v])/(n*(n-1)));
		c[q[i].F-1] = q[i].S;
		cout << setprecision(7) << s << endl;
	}
	return 0;
}