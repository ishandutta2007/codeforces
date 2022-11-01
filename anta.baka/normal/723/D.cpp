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

pii go[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
vector<vector<pii>> oz;

int main() {
	ios_base::sync_with_stdio(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<char>> a(n, vector<char>(m));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];

	vector<vector<bool>> b(n, vector<bool>(m, false));
	queue<pii> q;
	for(int i = 0; i < n; i++) {
		if(a[i][0] == '.') {
			q.push(mp(i,0));
			b[i][0] = true;
		}
		if(a[i][m-1] == '.') {
			q.push(mp(i,m-1));
			b[i][m-1] = true;
		}
	}
	for(int j = 0; j < m; j++) {
		if(a[0][j] == '.') {
			q.push(mp(0,j));
			b[0][j] = true;
		}
		if(a[n-1][j] == '.') {
			q.push(mp(n-1,j));
			b[n-1][j] = true;
		}
	}
	while(!q.empty()) {
		pii c = q.front();
		q.pop();
		for(int p = 0; p < 4; p++) {
			int i = c.ff + go[p].ff;
			int j = c.ss + go[p].ss;
			if(i>=0 && i<n && j>=0 && j<m && a[i][j] == '.' && b[i][j]==false) {
				b[i][j] = true;
				q.push(mp(i,j));
			}
		}
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(a[i][j] == '.' && b[i][j] == false) {
				oz.pb(vector<pii>());
				b[i][j] = true;
				q.push(mp(i,j));
				while(!q.empty()) {
					pii c = q.front();
					q.pop();
					oz.back().pb(c);
					for(int p = 0; p < 4; p++) {
						int i = c.ff + go[p].ff;
						int j = c.ss + go[p].ss;
						if(i>=0 && i<n && j>=0 && j<m && a[i][j] == '.' && b[i][j]==false) {
							b[i][j] = true;
							q.push(mp(i,j));
						}
					}
				}
			}

	auto cmp = [](int s, int c){ return sz(oz[s]) > sz(oz[c]); };
	vector<int> del;
	for(int i = 0, lim = sz(oz); i < lim; i++)
		del.pb(i);
	sort(all(del), cmp);
	int ans = 0;
	while(sz(del) > k) {
		for(pii w : oz[del.back()])
			a[w.ff][w.ss] = '*';
		ans += sz(oz[del.back()]);
		del.pop_back();
	}
	cout << ans << "\n";
	for(int i = 0; i < n; i++, cout << "\n")
		for(int j = 0; j < m; j++)
			cout << a[i][j];
}