#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
const int LIM=2e5+7;
vector<int>V[LIM];
pair<int,int>kraw[LIM];
int in[LIM], kol[LIM];
void solve() {
	int n, m;
	cin >> n >> m;
	rep(i, n) {
		V[i].clear();
		in[i]=0;
	}
	rep(i, m) {
		int t;
		cin >> t >> kraw[i].st >> kraw[i].nd; --kraw[i].st; --kraw[i].nd;
		if(t) {
			V[kraw[i].st].pb(kraw[i].nd);
			++in[kraw[i].nd];
		}
	}
	queue<int>q;
	int nr=0;
	rep(i, n) if(!in[i]) q.push(i);
	while(!q.empty()) {
		int p=q.front(); q.pop();
		kol[p]=nr; ++nr;
		for(auto i : V[p]) {
			--in[i];
			if(!in[i]) q.push(i);
		}
	}
	if(nr!=n) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	rep(i, m) {
		if(kol[kraw[i].st]>kol[kraw[i].nd]) swap(kraw[i].st, kraw[i].nd);
		cout << kraw[i].st+1 << " " << kraw[i].nd+1 << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}