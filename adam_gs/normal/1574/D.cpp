#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int N=10;
vector<int>V[N];
map<vector<int>,int>odw, ban;
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	priority_queue<pair<int,vector<int>>>q;
	vector<int>p;
	int sum=0;
	rep(i, n) {
		int c;
		cin >> c;
		p.pb(c-1);
		while(c--) {
			int a;
			cin >> a;
			V[i].pb(a);
		}
		sum+=V[i].back();
	}
	odw[p]=1;
	q.push({sum, p});
	int m;
	cin >> m;
	while(m--) {
		p.clear();
		rep(i, n) {
			int a;
			cin >> a; --a;
			p.pb(a);
		}
		ban[p]=1;
	}
	while(!q.empty()) {
		sum=q.top().st; p=q.top().nd; q.pop();
		if(!ban[p]) {
			for(auto i : p) cout << i+1 << " ";
			cout << '\n';
			return 0;
		}
		rep(i, n) if(p[i]>0) {
			sum-=V[i][p[i]];
			--p[i];
			sum+=V[i][p[i]];
			if(!odw[p]) {
				odw[p]=1;
				q.push({sum, p});
			}
			sum-=V[i][p[i]];
			++p[i];
			sum+=V[i][p[i]];
		}
	}
}