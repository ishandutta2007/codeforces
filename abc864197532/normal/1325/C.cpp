#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>

const int N = 100000;
vector <int> adj[N];

int main () {
	int n, u, v;
	cin >> n;
	fop (i,0,n-1) {
		cin >> u >> v;
		u--; v--;
		adj[u].pb(i);
		adj[v].pb(i);
	}
	int s = 0;
	fop (i,0,n) {
		if (adj[i].size() > 2) s = i;
	}
	vector <int> ans(n - 1, -1);
	int now = 0;
	for (int i : adj[s]) {
		ans[i] = now++;
	}
	fop (i,0,n-1) {
		if (ans[i] == -1) ans[i] = now++;
	}
	for (int i : ans) cout << i << '\n';
}