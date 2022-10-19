#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e5+7;
vector<int>V[LIM], ile;
void DFS(int x, int o) {
	int p=0;
	for(auto i : V[x]) if(i!=o) {
		++p;
		DFS(i, x);
	}
	if(p) ile.pb(p);
}
void solve() {
	int n;
	cin >> n;
	ile.clear();
	rep(i, n) V[i].clear();
	rep(i, n-1) {
		int a=i+1, b;
		cin >> b; --b;
		V[a].pb(b);
		V[b].pb(a);
	}
	ile.pb(1);
	DFS(0, 0);
	sort(all(ile));
	reverse(all(ile));
	priority_queue<int>q;
	rep(i, ile.size()) q.push(ile[i]+i);
	int ans=ile.size();
	while(!q.empty()) {
		int p=q.top();
		if(ans>=p) break;
		++ans;
		q.pop();
		q.push(p-1);
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}