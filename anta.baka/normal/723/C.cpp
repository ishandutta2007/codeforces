#include <bits/stdc++.h>

#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
	ios_base::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	int lo = n / m, hi = (n + 1) / m;
	vector<int> a(n+1);
	vector<vector<int>> g(m+1);
	vector<int> fr;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] <= m)
			g[a[i]].pb(i);
		else
			fr.pb(i);
	}
	int q = 0;
	for(int i = 1; i <= m; i++)
		if(sz(g[i]) < lo) {
			q += lo - sz(g[i]);
			while(!fr.empty() && sz(g[i]) < lo) {
				g[i].pb(fr.back());
				fr.pop_back();
				a[g[i].back()] = i;
			}
			for(int j = 1; j <= m && sz(g[i]) < lo; j++)
				while(sz(g[j]) > lo && sz(g[i]) < lo) {
					g[i].pb(g[j].back());
					g[j].pop_back();
					a[g[i].back()] = i;
				}
		}
	cout << lo << ' ' << q << "\n";
	for(int i = 1; i <= n; i++)
		cout << a[i] << ' ';
}