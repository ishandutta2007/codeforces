#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int mod = (int)1e9 + 7;
const int inf = (1<<30);
int n;
int p[200200];
int cnt[200200];
int u[200200];
int dfs(int v) {
	if(p[v] == 0) return v;
	u[v] = 1;
	if(u[p[v]] == 1)
		return v;
	return dfs(p[v]);
}
int main () {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >>p[i];
		cnt[p[i]]++;
	}
	vector< pair<int, int> > ans;
	for(int i = 1; i <= n; i++) {
		if(cnt[i] == 0) {
			int x = dfs(i);
			if(p[x] == 0)
				ans.pb(mp(i, x));
		}
	}
	for(int i = 1;i<ans.size(); i++) {
		p[ans[i-1].s] = ans[i].f;
	}
	p[ans.back().s] = ans[0].f;
	for(int i = 1; i <= n; i++)
		cout << p[i] << " ";




 	return 0;
}