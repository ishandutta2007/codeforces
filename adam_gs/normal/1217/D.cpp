#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=5e3+7;
vector<int>V[LIM];
pair<int,int>kraw[LIM];
int in[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, m) {
		cin >> kraw[i].st >> kraw[i].nd;
		--kraw[i].st; --kraw[i].nd;
		V[kraw[i].st].pb(kraw[i].nd);
		++in[kraw[i].nd];
	}
	queue<int>q;
	rep(i, n) if(!in[i]) q.push(i);
	bool ok=true;
	rep(i, n) {
		if(q.empty()) {
			ok=false;
			break;
		}
		int p=q.front(); q.pop();
		for(auto j : V[p]) {
			--in[j];
			if(!in[j]) q.push(j);
		}
	}
	if(ok) {
		cout << 1 << '\n';
		rep(i, m) cout << 1 << " ";
		cout << '\n';
		return 0;
	}
	cout << 2 << '\n';
	rep(i, m) cout << (kraw[i].st<kraw[i].nd?1:2) << " ";
	cout << '\n';
}